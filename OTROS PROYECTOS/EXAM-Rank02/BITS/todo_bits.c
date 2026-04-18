
#include <stdio.h> 
int main()
{
    int a = 50;  //binario = 110010
    printf("USANDO B = %b\n", a); 
    
    unsigned char byteData = 0b00110010; //0011 0010
    int bitLeido = (byteData >> 3) & 1;
    printf("USANDO D = %d \n", bitLeido);
    //imprimirBinario - byte
    printf("Lectura TÖDO = ");
    for (int i = 7; i >= 0; i--)
        printf("%d", (byteData >> i) & 1);
    printf("\n");

    printf("B = %b\n", (byteData >> 3) & 7); //7 es 111, luego es un & a todo
    printf("D = %d\n", (byteData >> 3) & 7);

    printf("B = %b\n", (byteData >> 3)); // 4 es 100
    printf("D = %d\n", (byteData >> 3) & 4);
/*para que sea transparente AND & de 1, 3, 7, 15, 31... y es como una mascara */

    printf("B = %b\n", (byteData >> 4)); // 0011 0010
    printf("D = %d\n", (byteData >> 4) & 1);
    printf("D = %d\n", (byteData & 16) >> 4); //10000  /1-11-111-1111-11111-111111
    // escribe 50 en binario
    //print_bits(byteData);
    // intercambia los primeros 4 y los 4 ultimos 
    //swap_bits(byteData);
    // leer los bits en orden inverso
    //reverse_bits(unsigned char octet);

    return 0;
}

/*
void print_bits(unsigned char octet)
{
        int     i = 8;
        unsigned char   bit;

        while (i--)
        {
                bit = (octet >> i & 1) + '0';
                write(1, &bit, 1);
        }
}

unsigned char   swap_bits(unsigned char octet)
{
        return ((octet >> 4) | (octet << 4));
}

unsigned char   reverse_bits(unsigned char octet)
{
        int             i = 8;
        unsigned char   res = 0;

        while (i > 0)
        {
                res = res * 2 + (octet % 2);
                octet = octet / 2;
                i--;
        }
        return (res);
}

int     main(int argc, char **argv)
{
    //MAIN 1
        unsigned char c;
        (void)argc;

        c = argv[1][0];
        write(1, &c, 1);
        write(1, "\n", 1);
        c = swap_bits(c);
        write(1, &c, 1);
        write(1, "\n", 1);
    
    //MAIN 2
        if (ac == 2)
            printf("%d", reverse_bits(av[1][0]));

        return (0);
}
*/
