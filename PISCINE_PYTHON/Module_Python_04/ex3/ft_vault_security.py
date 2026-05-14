#!/usr/bin/env python3

# ************************************************************************ #
#                                                                          #
#                                                      :::      ::::::::   #
#   ft_vault_security.py                             ::+::    :+:    :+:   #
#                                                  +:+ +:+         +:+     #
#   By: lestrada <lestrada@student.42.es>        +#+  +:+       +#+        #
#                                              +#+#+#+#+#+   +#+           #
#   Created: 2026/05/06          by lestrada        #+#    #+#             #
#   Updated: 2026/05/10          by lestrada       ###   ########.es       #
#                                                                          #
# ************************************************************************ #



def secure_archive(filename, action='read', content=None):
    """
    Safe file access using context manager.
    - action: either 'read' or 'write'
    - content: string to write when action='write'
    Returns (bool, str) - success flag and either file content or error message.
    """
    if action == 'read':
        try:
            with open(filename, 'r') as f:
                data = f.read()
            return (True, data)
        except Exception as e:
            return (False, str(e))
    elif action == 'write':
        if content is None:
            return (False, "No content provided for writing")
        try:
            with open(filename, 'w') as f:
                f.write(content)
            return (True, "Content successfully written to file")
        except Exception as e:
            return (False, str(e))
    else:
        return (False, f"Unknown action: {action}")

# Demostración del uso (para que el script produzca una salida similar al ejemplo)
if __name__ == "__main__":
    print("=== Cyber Archives Security ===\n")

    # Lectura de archivo inexistente
    result = secure_archive("/not/existing/file", "read")
    print(f"Using 'secure_archive' to read from a nonexistent file: {result}\n")

    # Lectura de archivo inaccesible (ajusta la ruta según tu sistema)
    result = secure_archive("/etc/master.passwd", "read")
    print(f"Using 'secure_archive' to read from an inaccessible file: {result}\n")

    # Lectura de un archivo regular (asegúrate de que existe, por ejemplo 'ancient_fragment.txt')
    result = secure_archive("ancient_fragment.txt", "read")
    print(f"Using 'secure_archive' to read from a regular file:\n{result}\n")

    # Escritura de contenido previo a un nuevo archivo
    sample_content = "[FRAGMENT 001] Digital preservation protocols established 2087\n[FRAGMENT 002] Knowledge must survive the entropy wars\n[FRAGMENT 003] Every byte saved is a victory against oblivion\n"
    result = secure_archive("new_fragment.txt", "write", sample_content)
    print(f"Using 'secure_archive' to write previous content to a new file: {result}")
