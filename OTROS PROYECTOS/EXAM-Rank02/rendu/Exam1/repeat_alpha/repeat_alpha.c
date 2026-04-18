//Hora INICIO: 14:10
//Hora FIN: 14:23 
// Intentos: 1
//ERRORES :  PASSED at 13min 

#include <unistd.h>

void putstr(char* str)
{
    int i=0;
    while(str[i])
    {
        if( (str[i]>='a' && str[i]<='z') )
        {
            int j=str[i]-'a'+1;
            while (j>0)
            {
                write(1, &str[i], 1);
                j--;
            }
        }
        else if (str[i]>='A' && str[i]<='Z') 
        {
            int j=str[i]-'A'+1;
            while (j>0)
            {
                write(1, &str[i], 1);
                j--;
            }
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}


int main(int c, char** argv)
{

    if (c!=2)
    {
        write(1, "\n", 1);
        return 0;
    }
    putstr(argv[1]);
    write(1, "\n", 1);
    return 0;
}