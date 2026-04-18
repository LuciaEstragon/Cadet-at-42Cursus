//empiezo 13:40 -->3 veces --> el problema eta en /n de la presentacion 14:10

#include <unistd.h>

void putsr(char* str)
{
    int i=0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
void capitlizer(char* str)
{
    int i=0;
    while(str[i])
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
        /*if(i==0 && !(str[i+1]>='a' && str[i+1]<='z'))
            str[i]-=32;*/
        if((str[i]>='a' && str[i]<='z') && ( str[i+1]==' ' || str[i+1]=='\t'  || str[i+1]=='\0') )
            str[i]-=32;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc<2)
    {
        write(1, "\n", 1);
        return(0);
    }
    int i=1;
    while(argv[i])
    {
        capitlizer(argv[i]);
        write(1, "\n", 1);
        i++;
    }
    return(0);
}