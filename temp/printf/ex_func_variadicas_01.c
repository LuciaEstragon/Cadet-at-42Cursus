#include <stdio.h>
#include <stdarg.h>
 
int vout(int max, ...);
 
int main(void)
{
   vout(2, "Sat", "Sun");
   printf("\n");
   vout(3, "Mon", "Tues", "Wed");
   // LEG Pruebas - desde aqui
   printf("\n LEG pruebas \n");
   vout(2); // ERROR no controlado
   printf("\n");
   vout(1, "Mon", "Tues", "Wed");
   printf("\n");
   vout(0, "Mon", "Tues", "Wed"); // no imprime nada de nada, solo el \n dos veces, al de antes y el de despues
   printf("\n");
   vout(2, "Mon", "Tues", "Wed");
      printf("\n");
   vout(3, "", NULL, '\0'); // MEJOR, si esta controlado
   
   return(0);
}
 
int vout(int max, ...)
{
   va_list arg_ptr;
   va_list args_copy;
   int args;
   char *day;
   va_start(arg_ptr, max);
   va_copy(args_copy, arg_ptr);
   args = 0;
   while(args < max)
   {
      day = va_arg(arg_ptr, char *);
      printf("Day: %s\n", day);
      args++;
   }
   va_end(arg_ptr);

   args = 0;
   while(args < max)
   {
      day = va_arg(args_copy, char *);
      printf("Day: %s\n", day);
      args++;
   }
   va_end(args_copy);
   
   return (0);
}
 
/******************  Output should be similar to:  ****************
Day: Sat
Day: Sun
Day: Sat
Day: Sun

Day: Mon
Day: Tues
Day: Wed
Day: Mon
Day: Tues
Day: Wed
*/
