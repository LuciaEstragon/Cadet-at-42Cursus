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
