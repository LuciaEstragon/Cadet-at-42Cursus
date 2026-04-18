//empiezo a las 12:30 -> fallo dos ves --> termino 12:55  (30min, 2fallos)

#include <unistd.h>

void putstr(char *str)
{
    int i=0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
int ft_strlen(char *str)
{
    int len=0;
    while(str[len])
        len++;
    return len;
}
void remplace(char* str, char a, char b)
{
    int i=0;
    while(str[i])
    {
        if(str[i] == a)
            str[i]=b;
        write(1, &str[i], 1);
        i++;
    }
}
int main(int argc, char **argv)
{
    if(argc!=4)
    {
        write(1, "\n", 1);
        return (0);
    }
    char* msg = argv[1];
    char* msg1 = argv[2];
    char* msg2 = argv[3];
    if(ft_strlen(msg1) !=1 || ft_strlen(msg2) !=1)
    {
        write(1, "\n", 1);
        return (0);
    }    
    remplace(msg, *msg1, *msg2);
    write(1, "\n", 1);
    /*int i=1;
    while(argv[i])
    {
        putstr(argv[i]);
        i++;
    }*/
}