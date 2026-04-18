//init 11:30
//init 11:55


#include<unistd.h>
#include<stdio.h>
void mirror(char* str)
{
    int i=0;
    int mirror=0;
    while(str[i])
    {
        if(str[i]>='a' && str[i]<='z')
        {
            mirror=str[i]-'n';
            str[i]='n'-mirror-1;
        }
        if(str[i]>='A' && str[i]<='Z')
        {
            mirror=str[i]-'N';
            str[i]='N'-mirror-1;
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char**argv)
{
    if (argc!=2)
    {
        write(1, "\n", 1);
        return 0;
    }
    mirror(argv[1]);
    write(1, "\n", 1);
    return 0;
}