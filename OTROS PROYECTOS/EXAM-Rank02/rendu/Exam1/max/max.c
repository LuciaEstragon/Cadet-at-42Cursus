//Hora INICIO: 14:23
//Hora FIN: 14:38
// Intentos: 1
//ERRORES :  PASSED at 15min   
// repasar la forma de declarar array_num



int max(int* tab, unsigned int len)
{

    unsigned int i=0;
    int max=0;
    while (i<len)
    {
        if(tab[i]>max)
            max=tab[i];
        i++;
    }
    return max;

}
/*
#include <stdio.h>

int main ()
{
    int array[7];
    array[0]=1;
    array[1]=4;
    array[2]=2;
    array[3]=33;
    array[4]=5;
    array[5]=7;
    array[6]=1;

    int thiss = max(array, 7);
    printf("%d", thiss);
    return 0;
}*/