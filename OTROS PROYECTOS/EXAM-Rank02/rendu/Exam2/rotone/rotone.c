// INCIO :6:20
// FIN: 6:32
// INTENTOS: 2

#include <unistd.h>
void rotone(char *str)
{
    int i=0;
    while(str[i])
    {
        if(str[i]>='a' && str[i]<='z')
        {
            if(str[i]!='z')
                str[i] = str[i]+1;
            else
                str[i] = 'a';
        }
        if(str[i]>='A' && str[i]<='Z')
        {
            if(str[i]!='Z')
                str[i] = str[i]+1;
            else
                str[i] = 'A';
        }
        write(1, &str[i], 1);
        i++;
    }
}
int main (int argc, char **argv)
{
    if (argc!=2)
    {
        write(1, "\n", 1);
        return 0;
    }
    rotone(argv[1]);
    write(1, "\n", 1);
    return 0;
}