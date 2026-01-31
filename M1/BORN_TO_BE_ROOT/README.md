*Este proyecto ha sido creado commo parte del curriculum de 42 por lestrada.*

# 📦 BORN TO BE ROOT


## 🌟 Descripcion

El proyecto Born2beRoot consiste en la instalación y configuración avanzada de una máquina virtual Debian, enfocándose en la gestión de sistemas, seguridad de usuarios y servicios de red bajo los siguientes requisitos específicos:
- MV sin interfaz gráfica.
- SELinux y AppArmor deben estar bien configurados y ejecutándose al inicio.
- crear al menos dos particiones cifradas con LVM. (el mio tiene 3)
lsblk
```text
NAME                          MAJ:MIN RM  SIZE RO TYPE  MOUNTPOINTS
sda                             8:0    0   20G  0 disk  
├─sda1                          8:1    0  918M  0 part  /boot
├─sda2                          8:2    0    1K  0 part  
└─sda5                          8:5    0 19,1G  0 part  
  └─sda5_crypt                254:0    0 19,1G  0 crypt 
    ├─lestrada42--vg-root     254:1    0  6,7G  0 lvm   /
    ├─lestrada42--vg-var      254:2    0  1,9G  0 lvm   /var
    ├─lestrada42--vg-swap     254:3    0  668M  0 lvm   [SWAP]
    ├─lestrada42--vg-tmp      254:4    0  512M  0 lvm   /tmp
    ├─lestrada42--vg-home     254:5    0  4,2G  0 lvm   /home
    ├─lestrada42--vg-srv      254:6    0  3,7G  0 lvm   /srv
    └─lestrada42--vg-var--log 254:7    0  1,4G  0 lvm   /var/log
sr0                            11:0    1 1024M  0 rom   
```
- Ejecutar servicio SSH en puerto 4242 de la maquina. No debe ser posible conectarse usando el SSH como root
- Firewal UFW - Dejar solo abierto el puerto 4242.
- Nombre de host la MV lestrada42 debo poder modificarlo
- Debe tener un grupo sudo y user42, y un usuario lestrada
- Debe implementar una politica de contraseñas seguras
- Crear un script de bash llamado monitoring.sh. ejecutado en cron, y poder interrumpirlo.


## ⬇️ Instrucciones

Entras en el **hipervisor** Virtual Box. Alli abre tu maquina virtual creada. En mi caso se llama **debian-lu**. Dar doble-click o start. 

Nada mas entrar te dice que se va a abrir **Debian GNU**. Te pide la clave para la particion encriptada sda5_crypt. Se la ponemos. 

Despues te dice que estas en **Debian GNU/Linux 13** y que el **hostname** de la maquina es *lestrada42*, puerto de conexion tty1. Te pide que te logues con un usuario. Mi usuario es _lestrada_. Despues te pide la pass.

    Debian GNU/Linux 13 lestrada42 tty1

Nos acabamos de logar a la MV a traves de mi usurio usando el hipervisor, pero puedes logarte de otra forma, a traves de **ssh**. Abres una terminal cualquiera en el PC (host).

```bash
ssh lestrada@localhost -p 2222
```

Esta frase significa exactamente que te vas a conectar por un protocolo seguro **ssh** (como un tunel seguro con reglas *AppAmor*) a el usuario **_lestrada_** de la maquina de destino que se encuentra **@** en tu propia máquina **localhost** (IP 127.0.0.1), especificando un puerto no estándar **-p 2222** (el puerto estandar es el 22, para conectarte a cuaquier maquina, pero para maquinas virtuales se  suele usar el 2222).

    [ PC(host) ] --> Port 2222 --> [ hipervisor(VirtualBox) ] --> Port 4242 --> [ debian-lu(MV) ]


## ℹ️ Como corregir el BORN_TO_BE_ROOT

Documentos para entregar tu proyecto:
 - crea tu key 
 - duplica tu maquina

1º subir un hash –> una firma digital de la maquina vitual:
```bash
> sha1sum "debian-lu.vdi"  # este proceso tarda
```
2º abrir VirtualBox  –> haces un duplicado:
pasas el codigo anterior sobre la maquina duplicada para saber que tiene la misma firma digital
```bash
diff archivo1.txt archivo2.txt  # para comprobar que es la misma
```
Las maquinas virtuales tienen instantáneas (Snapshots): Permite guardar el estado exacto de la máquina. Si comete un error, puede "regresar en el tiempo" al punto anterior de forma inmediata. 


## 🚀 Recursos

### Pasos para crear una maquina virtual:

 - 1. Necesitas un *hipervisor*: VirtualBox
 - 2. Boton Crear -> 1. Nombre MV: debian-lu. 2. Donde esta: ruta. 3. S.O. : Imagen Debian. (> hostnamectl  # para saber mi s.o.)
 - 3. Configuraciones fisicas y de recursos que comparto entre MV y host.

### Configuraciones del s.o. de tu maquina necesitas:

 - VERIFICAR KERNELL
 ```bash
> uname --kernell -version
> sudo systemctl set-defaults multi-user target # sin entorno grafico
> sudo systemctl start grafical-target # con entorno grafico
```
NOta: veremos el sujifo ctr=control en **systemctl**(System Control) para control de servicios (UFW, SSH, etc.).
Se utiliza tambien -ctl para hostnamectl, timedatectl, journalctl.


 - PARTICIONES:  · entorno LVM (gestor de volumenes logicos) · extension de mi maquina .vdi · crypt
```bash
> lsblk     # ver el arbol de particiones # para que tener tantas particiones
> sudo pvresize /dev/mapper/sda5_crypt  # modificar tamaño de las particiones
> sudo nano /etc/fstab  #modificar nombre de las particiones  aqui y debajo
> sudo lvrename lestrada42-vg 'nombre_antiguo' 'nombre_nuevo'
```
Las particiones son trozos de memoria dedicados a "allocar" una funcionalidad. El entorno LVM (gestor de volumenes logicos) te permite que esas particiones no sean reales, si no logicas. Asi si las puees modificar, cambiar de lado o incluso abrir mas espacio en otro sitio fisico. Antes añadias un disco fisico para ganar mas espacio de la particion y tenias que rehacerlo para poder tener las particiones separdas. Los volumees te permiten versatilidad en eso: lo añades y "se lo traga", el trabaja coo si fuera todo la misma seccion. 

Cuando encriptas un volumen con LUKS ("capa" de seguridad), como /home, /var o la partición root, los datos no son legibles sin una clave simétrica. Es más seguro, porque si alguien roba el disco físico (o el archivo .vdi de tu VM), no podrá ver ni un solo archivo sin esa contraseña de volumen.

 - HOSTNAME
```bash
> hostnamectl  # muestra ell nombre del hostname
> sudo hostnamectl set-hostname nuevo_nombre # modificar el hostname
> sudo nano /etc/hosts # modificar el hostname en el archivo (para que no se vaya al hacer reboot)
# 127.0.1.1 nombre_viejo
```  
El hostname es el nombre que le das a tu direccion IP propia de tu maquina virtual. Con el primer metodo lo esta cambiando en /etc/hostname, y el segundo en /etc/hosts. El etc/hostname solo contiene una palabra: el nombre de tu máquina. al comprobar >hostname solo compruebo eso. El etc/host es una tabla que traduce nombres a direcciones IP.

 - SSH:
```bash
> systemctl status ssh  # muestra si el servicio SSH está activo, inactivo, o problemas
> sudo service ssh status  # verificamos que esta funcionando en los siguientes puertos
> nano /etc/ssh/sshd_config  # editar archivo de configuracion del ssh (ruta, editor -vim, nano)
#  Dentro del archivo, busca las líneas:
#    #Port 22
#    #PermitRootLogin prohibit-password
#    Cambia estas líneas a:
#    Port 4242
#    PermitRootLogin no
> sshd -t  # verificar la sintaxis antes de reiniciar
> systemctl restart ssh   # reiniciar  > sudo systemctl reload ssh  # reconfigurar sin reiniciar

# Comprobacion:
> systemctl enable ssh   # para encender ssh
> ss -tunlp | grep 4242   # forma de verificar puerto activo

# !! No debes poder modificar ssh desde root
> whoami  # para ir al root  > su – root 
```  

- UFW
```bash
> apt install ufw   # Instala UFW. → si no funciona poner sudo o  su – root
>  ufw default deny incoming   # Bloquea todas las solicitudes entrantes. - msgOK change deny
> ufw default allow outgoing  # Permite todas las solicitudes salientes. - msgOK change allow
> ufw allow 4242 # Permite el tráfico entrante en el puerto 4242. Esto es crucial para garantizar que aún pueda acceder a su servidor mediante SSH.  - msgOK rule update

# Te preguntan
> ufw enable # Habilita UFW. o systemctl status ufw
> ufw status  # estado - esta instalado?
> ufw status verbose || ufw status numbered  # verificamos que esta funcionando en los siguientes puertos
> ufw allow _puerto_ # regla nueva para abrir puerto 8080  > ufw allow 8080 
> ufw delete allow _puerto_ #depues borrar > ufw delete allow 8080 
> systemctl restart ufw   # reiniciar  > sudo systemctl reload ufw # reconfigurar sin reiniciar
```  

- SUDO
```bash
> visudo
# Defaults        requiretty
# Defaults        badpass_message="WRONG PASSWORD"
# Defaults        logfile=/var/log/sudo/sudo.log
# Defaults        log_input
# Defaults        log_output
# Defaults        iolog_dir=/var/log/sudo
# Defaults        passwd_tries=3
> visudo -c -v   #  para verificar sintaxis de lo escrito y que salgan errores
  # > visudo -c -f /etc/sudoers.d/mi_archivo # verifica un archivo concreto
``` 

  - USER - GROUP
```bash
> groupadd user42 # Agrega el grupo user42.
> cat /etc/group  # Para verificar los cambios 
# lestrada:x:1000        --> grupo:lestrada, contraseña:x (se guarda encriptada en /etc/gshadow), 1000:GID (Group ID)
# user42:x:1001:lestrada --> grupo:contraseña:GID: + lestrada - este usuario se unio a ese grupo

> usermod -a -G user42,sudo lestrada # Agrega el usuario a los grupos user42 y sudo.
> cat /etc/sudoers  # Para verificar los cambios 

> adduser userlu # Crear usuario nuevo userlu
> userdel -r userlu # Eliminar user
> passwd userlu # para añadir PASS
> cat /etc/passwd  # Para verificar los cambios 
``` 

- PASS
```bash
# Requisito de tiempo validez -- Hay que cambiarlo en tres sitios:
> nano /etc/login.defs  # Configuración GLOBAL (futuros usuarios)
> chage -l root # Configuración del USUARIO root
> chage -m 2 -M 30 -W 7 root
> chage -l lestrada  # Configuración del USUARIO existente lestrada
> chage -m 2 -M 30 -W 7 lestrada

# Requisito de fortaleza de la contraseña: 
> apt install libpam-pwquality
> nano /etc/pam.d/common-password 
#password requisite pam_pwquality.so retry=3 minlen=10 difok=7 maxrepeat=3 dcredit=-1 ucredit=-1 lcredit=-1 reject_username enforce_for_root

# Para cambiar una ccontraseña:
> passwd lestrada
``` 

- Que es cron?
```bash
> apt install bc sysstat # bc: es una calculadora # sysstat: conjunto de herramientas para monitorear el rendimiento del sistema: -Incluye comandos como: sar, iostat, mpstat, pidstat

> crontab -u root -e # mecesitas estar en root, por esu -u root; o no funciona
# */10 * * * * bash /etc/cron.d/monitoring.sh | wall
# NOTA: el  wall sirve para que se escriba sobre todos los terminales abiertos

> sudo systemctl start cron 
> sudo systemctl stop cron 
> sudo systemctl status cron 

> sudo crontab -l # para ver el contenido de cron
> cat /etc/crontab
``` 
Existen varios direcctorios de cron: /etc/crontab y /etc/cron.d/. Nosotros tenemos que meter nuesto file **monitoring.sh** en /etc/cron.d/monitoring.sh. En esa direccion hay otro fichero mas **cat /etc/cron.d/e2scrub_all** que es un servicio de mantenimiento automático de Debian para sistemas de archivos ext4 (el que probablemente usaste al instalar la máquina).

- Informacion sobre mi script monitoring.sh
```bash
#!/bin/bash
# monitoring.sh - Versión simplificada

echo "========================================="
echo "      MONITOREO - $(date '+%H:%M:%S')"
echo "========================================="

# 1. Arquitectura y kernel
echo "● Sistema:"
echo "  Arquitectura: $(uname -m)"
echo "  Kernel: $(uname -r)"

# 2. CPU
CPU_PHYS=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
CPU_VIRT=$(grep -c "^processor" /proc/cpuinfo)
echo "● CPU:"
echo "  Procesadores físicos: $CPU_PHYS"
echo "  Procesadores virtuales: $CPU_VIRT"
echo "  Uso: $(top -bn1 | grep "%Cpu(s)" | awk '{printf "%.1f%%", $2+$4}')"

# 3. RAM
RAM_TOTAL=$(free -m | awk '/^Mem:/{print $2}')
RAM_USED=$(free -m | awk '/^Mem:/{print $3}')
RAM_PERC=$(free | awk '/^Mem:/{printf "%.1f", $3/$2*100}')
echo "● Memoria:"
echo "  Total: ${RAM_TOTAL}MB"
echo "  Usada: ${RAM_USED}MB (${RAM_PERC}%)"

# 4. Disco
DISK_PERC=$(df / --output=pcent | tail -1 | tr -d ' %')
echo "● Almacenamiento:"
echo "  Uso del disco: ${DISK_PERC}%"

# 5. LVM
echo "● LVM: $(lsblk | grep -q lvm && echo 'ACTIVO' || echo 'INACTIVO')"

# 6. Red
echo "● Red:"
echo "  IPv4: $(hostname -I | awk '{print $1}')"
echo "  Conexiones: $(ss -tun | grep -v State | wc -l)"

# 7. Usuarios
echo "● Usuarios:"
echo "  Conectados: $(who | wc -l)"
echo "  Sudo: $(journalctl _COMM=sudo 2>/dev/null | grep -c COMMAND || echo 0)"

echo "========================================="
```

## ✍️ Author 💭

All projects on this GitHub repository are written by **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). January 2026.

_Todos los proyectos de este repositorio GitHub han sido escritos por **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). January 2026._