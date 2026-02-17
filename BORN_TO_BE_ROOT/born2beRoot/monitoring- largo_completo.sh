#!/bin/bash
# ====================================================
# monitoring.sh - Script de monitoreo para Born2beroot
# Debe ejecutarse cada 10 minutos via cron
# Requiere: bc, awk, grep, y comandos estándar de Linux
# ====================================================

# ------------------------------------------------------------------
# 1. CONFIGURACIÓN DE COLORES (opcional, para mejor visualización)
# ------------------------------------------------------------------
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color (reset)

# ------------------------------------------------------------------
# 2. OBTENER INFORMACIÓN DEL SISTEMA
# ------------------------------------------------------------------

# 2.1 Arquitectura y versión de kernel
ARCH=$(uname -m)
KERNEL=$(uname -r)
OS_INFO=$(cat /etc/os-release | grep "PRETTY_NAME" | cut -d'"' -f2)

# 2.2 Número de procesadores físicos y virtuales
CPU_PHYSICAL=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
CPU_VIRTUAL=$(grep -c "^processor" /proc/cpuinfo)

# 2.3 RAM disponible y tasa de utilización
RAM_TOTAL=$(free -m | awk '/^Mem:/{print $2}')
RAM_USED=$(free -m | awk '/^Mem:/{print $3}')
RAM_FREE=$(free -m | awk '/^Mem:/{print $4}')
RAM_PERCENT=$(free | awk '/^Mem:/{printf "%.2f", $3/$2 * 100}')

# 2.4 Almacenamiento disponible y tasa de utilización
DISK_TOTAL=$(df -h --total 2>/dev/null | awk '/total/{print $2}' || df -h / | awk 'NR==2{print $2}')
DISK_USED=$(df -h --total 2>/dev/null | awk '/total/{print $3}' || df -h / | awk 'NR==2{print $3}')
DISK_PERCENT=$(df --total 2>/dev/null | awk '/total/{print $5}' || df / | awk 'NR==2{print $5}' | tr -d '%')

# 2.5 Tasa de utilización de procesadores
CPU_PERCENT=$(top -bn1 | grep "%Cpu(s)" | awk '{printf "%.1f", $2 + $4}')

# 2.6 Fecha y hora del último reinicio
LAST_REBOOT=$(who -b | awk '{print $3 " " $4}')

# 2.7 Verificar si LVM está activo
if command -v lvm &> /dev/null; then
    LVM_STATUS=$(lsblk | grep -q "lvm" && echo "${GREEN}SI${NC}" || echo "${RED}NO${NC}")
else
    LVM_STATUS="${YELLOW}LVM no instalado${NC}"
fi

# 2.8 Número de conexiones activas (TCP)
TCP_CONNECTIONS=$(ss -tun | grep -v "State" | wc -l)

# 2.9 Número de usuarios utilizando el servidor
USER_COUNT=$(who | wc -l)

# 2.10 Dirección IPv4 y dirección MAC
IPV4=$(ip addr show | grep -oP 'inet \K[\d.]+' | grep -v "127.0.0.1" | head -1)
MAC=$(ip link show | awk '/link\/ether/ {print $2; exit}')

# 2.11 Número de comandos ejecutados con sudo
# Buscar en journalctl (systemd) o auth.log (syslog)
if command -v journalctl &> /dev/null; then
    SUDO_COUNT=$(journalctl _COMM=sudo 2>/dev/null | grep -c "COMMAND" || echo "0")
else
    SUDO_COUNT=$(grep -c "sudo:" /var/log/auth.log 2>/dev/null || echo "0")
fi

# 2.12 Información adicional: Uptime
UPTIME=$(uptime -p | sed 's/up //')

# 2.13 Carga del sistema (load average)
LOAD_AVG=$(uptime | awk -F'load average:' '{print $2}' | xargs)

# ------------------------------------------------------------------
# 3. MOSTRAR INFORMACIÓN CON FORMATO
# ------------------------------------------------------------------

# Banner opcional (descomentar si quieres)
cat << "EOF"

 /$$      /$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$   /$$$$$$  /$$$$$$$ 
| $$$    /$$$| $$_____/|__  $$__/| $$__  $$ /$$__  $$| $$__  $$
| $$$$  /$$$$| $$         | $$   | $$  \ $$| $$  \ $$| $$  \ $$
| $$ $$/$$ $$| $$$$$      | $$   | $$$$$$$/| $$  | $$| $$$$$$$/
| $$  $$$| $$| $$__/      | $$   | $$__  $$| $$  | $$| $$__  $$
| $$\  $ | $$| $$         | $$   | $$  \ $$| $$  | $$| $$  \ $$
| $$ \/  | $$| $$         | $$   | $$  | $$|  $$$$$$/| $$  | $$
|__/     |__/|__/         |__/   |__/  |__/ \______/ |__/  |__/
                     Monitoring System v1.0
EOF

echo -e "\n${CYAN}=====================================================${NC}"
echo -e "${CYAN}        INFORMACIÓN DEL SISTEMA - $(date)${NC}"
echo -e "${CYAN}=====================================================${NC}\n"

# ------------------------------------------------------------------
# 4. SECCIONES DE INFORMACIÓN
# ------------------------------------------------------------------

echo -e "${GREEN}● ARQUITECTURA Y SISTEMA OPERATIVO${NC}"
echo -e "  Sistema Operativo: ${OS_INFO}"
echo -e "  Arquitectura: ${ARCH}"
echo -e "  Versión de Kernel: ${KERNEL}"
echo -e "  Tiempo activo: ${UPTIME}"
echo -e "  Último reinicio: ${LAST_REBOOT}"
echo -e "  Carga del sistema: ${LOAD_AVG}\n"

echo -e "${GREEN}● PROCESADORES (CPU)${NC}"
echo -e "  Procesadores físicos: ${CPU_PHYSICAL}"
echo -e "  Procesadores virtuales: ${CPU_VIRTUAL}"
echo -e "  Uso de CPU: ${CPU_PERCENT}%\n"

echo -e "${GREEN}● MEMORIA (RAM)${NC}"
echo -e "  Total RAM: ${RAM_TOTAL} MB"
echo -e "  RAM usada: ${RAM_USED} MB"
echo -e "  RAM libre: ${RAM_FREE} MB"
echo -e "  Porcentaje usado: ${RAM_PERCENT}%\n"

echo -e "${GREEN}● ALMACENAMIENTO (DISCO)${NC}"
echo -e "  Total disco: ${DISK_TOTAL}"
echo -e "  Disco usado: ${DISK_USED}"
echo -e "  Porcentaje usado: ${DISK_PERCENT}%\n"

echo -e "${GREEN}● LVM (Logical Volume Manager)${NC}"
echo -e "  Estado LVM: ${LVM_STATUS}\n"

echo -e "${GREEN}● RED Y CONEXIONES${NC}"
echo -e "  Conexiones TCP activas: ${TCP_CONNECTIONS}"
echo -e "  Dirección IPv4: ${IPV4}"
echo -e "  Dirección MAC: ${MAC}\n"

echo -e "${GREEN}● USUARIOS${NC}"
echo -e "  Usuarios conectados: ${USER_COUNT}"
echo -e "  Comandos sudo ejecutados: ${SUDO_COUNT}\n"

# ------------------------------------------------------------------
# 5. ESTADO DE SERVICIOS (opcional pero útil)
# ------------------------------------------------------------------

echo -e "${GREEN}● ESTADO DE SERVICIOS${NC}"
SERVICES="ssh cron ufw"
for service in $SERVICES; do
    if systemctl is-active --quiet $service 2>/dev/null; then
        echo -e "  ${service}: ${GREEN}ACTIVO${NC}"
    else
        echo -e "  ${service}: ${RED}INACTIVO${NC}"
    fi
done

# ------------------------------------------------------------------
# 6. ESTADO DEL SISTEMA (resumen visual)
# ------------------------------------------------------------------

echo -e "\n${CYAN}● RESUMEN DEL ESTADO${NC}"

# Indicador de CPU
CPU_INT=${CPU_PERCENT%.*}
if [ $CPU_INT -lt 50 ]; then
    CPU_IND="${GREEN}◉${NC}"
elif [ $CPU_INT -lt 80 ]; then
    CPU_IND="${YELLOW}◉${NC}"
else
    CPU_IND="${RED}◉${NC}"
fi

# Indicador de RAM
RAM_INT=${RAM_PERCENT%.*}
if [ $RAM_INT -lt 50 ]; then
    RAM_IND="${GREEN}◉${NC}"
elif [ $RAM_INT -lt 80 ]; then
    RAM_IND="${YELLOW}◉${NC}"
else
    RAM_IND="${RED}◉${NC}"
fi

# Indicador de Disco
DISK_INT=${DISK_PERCENT%.*}
if [ $DISK_INT -lt 70 ]; then
    DISK_IND="${GREEN}◉${NC}"
elif [ $DISK_INT -lt 90 ]; then
    DISK_IND="${YELLOW}◉${NC}"
else
    DISK_IND="${RED}◉${NC}"
fi

echo -e "  CPU:  [${CPU_IND}] ${CPU_PERCENT}%  RAM: [${RAM_IND}] ${RAM_PERCENT}%  Disco: [${DISK_IND}] ${DISK_PERCENT}%"

# ------------------------------------------------------------------
# 7. PIE DE PÁGINA
# ------------------------------------------------------------------

echo -e "\n${CYAN}=====================================================${NC}"
echo -e "${PURPLE}Script ejecutado: $(date '+%Y-%m-%d %H:%M:%S')${NC}"
echo -e "${PURPLE}Próxima ejecución: $(date -d '+10 minutes' '+%H:%M:%S')${NC}"
echo -e "${CYAN}=====================================================${NC}\n"

# ------------------------------------------------------------------
# 8. VERSIÓN SIN COLORES PARA WALL (opcional)
# ------------------------------------------------------------------
# Si usas wall, puedes descomentar esta sección alternativa:

cat << EOF
=====================================================
      INFORMACIÓN DEL SISTEMA - $(date)
=====================================================

● ARQUITECTURA Y SISTEMA
  Sistema Operativo: ${OS_INFO}
  Arquitectura: ${ARCH}
  Kernel: ${KERNEL}
  Último reinicio: ${LAST_REBOOT}
  Uptime: ${UPTIME}

● PROCESADORES
  Físicos: ${CPU_PHYSICAL}
  Virtuales: ${CPU_VIRTUAL}
  Uso: ${CPU_PERCENT}%

● MEMORIA
  Total: ${RAM_TOTAL} MB
  Usada: ${RAM_USED} MB (${RAM_PERCENT}%)

● ALMACENAMIENTO
  Total: ${DISK_TOTAL}
  Usado: ${DISK_USED} (${DISK_PERCENT}%)

● LVM: $(echo ${LVM_STATUS} | sed 's/\\033\[[0-9;]*m//g')

● RED
  Conexiones TCP: ${TCP_CONNECTIONS}
  IPv4: ${IPV4}
  MAC: ${MAC}

● USUARIOS
  Conectados: ${USER_COUNT}
  Comandos sudo: ${SUDO_COUNT}

=====================================================
EOF
