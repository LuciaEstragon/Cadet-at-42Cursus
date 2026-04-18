//INICIO : 7:50
//FIN : 8:14
//INTENTOS : RENDIRSE
/*
char    *ft_strcpy(char *s1, char *s2) //dest - orgien
{
    int i=0, len=0;
    while(s1[len])
        len++;
    i=0;
    while(s2[i] && i<=len)
    {
        s1[i]=s2[i];
        i++;
    }
    s1[i]='\0';
    return(s1);
}*/

char    *ft_strcpy(char *s1, char *s2)
{
        int     i;

        i = 0;
        while (s2[i] != '\0')
        {
                s1[i] = s2[i];
                i++;
        }
        s1[i] = '\0';
        return (s1);
}

/*
#include<stdio.h>
int main()
{
    char* origen ="Hola";
    char dest[3];
    printf("%s", ft_strcpy(dest, origen));
    return 0;
}*/