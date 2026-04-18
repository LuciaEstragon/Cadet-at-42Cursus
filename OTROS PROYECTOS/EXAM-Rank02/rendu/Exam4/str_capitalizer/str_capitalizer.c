#include <unistd.h>

void capitlizer(char* str)
{
    int i=0;
    while(str[i])
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
        if(i==0 && (str[i]>='a' && str[i]<='z'))
            str[i]-=32;
        else if((str[i]>='a' && str[i]<='z') && ( str[i-1]==' ' || str[i-1]=='\t') )
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
