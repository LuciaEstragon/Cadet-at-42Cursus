
#include "libft_basic.h"

void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
void ft_putnmb(int nmb)
{
    if(nmb<0) {nmb=-nmb; write(1, "-", 1);}
    if(nmb>=10)
        ft_putnmb(nmb/10);
    char c = nmb%10 + '0';
    write(1, &c, 1);
}
int ft_atoi(char *str) // ascii to int
{
    int i=0;
    int neg=1;
    while(str[i]==' ') i++;
    if(str[i]=='-') {neg=-neg;  i++;}
    if(str[i]=='+') {neg=1;   i++;}
    int nmb = 0;
    while(str[i])
    {
        nmb = nmb*10 + str[i]-'0';
        i++;
    }
    return(neg*nmb);
}
char *ft_itoa(int nmb) // int to ascii
{
    char* str = NULL;
    nmb=0;
    return(str);
}
/* --PROBAR TODAS LAS FUNCIONES DE libft_basic--
int main(int argc, char** argv)
{
    if(argc<2)
    {
        write(1, "\n", 1);
        return 0;
    }
    int i=1;
    while(argv[i])
    {
        if(i == 1) ft_putstr(argv[i]);
        else if(i == 2) ft_putnmb(ft_atoi((argv[i]));
        else if(i == 3) ft_putstr(ft_itoa(ft_atoi((argv[i])));
        else putstr(argv[i]);
        write(1, "\n", 1);
        i++;
    }
    return(0);
}
*/