# ft_printf() function

**#include "ft_printf.h"**
**int _printf(const char** *format* **, ...);**

## Description

The **_printf()** function produce output according to a *format* as described below.
A format string is a template used to display text. It consists of two things: plain text, which is printed exactly as it is, and conversion tags (starting with %), which act as placeholders for variables. Each % tag tells the computer how to format and insert a specific value into the final message.

### Conversion specifiers

Implemented conversions:
- **%c** to print a single character.
- **%s**  to print a string (according to the default definition in C).
- **%p** prints the empty pointer * given as an argument in hexadecimal format.
- **%d**  to print a decimal number (base 10).
- **%i**  to print an integer in base 10.
- **%u** to print an unsigned decimal number (base 10).
- **%x**  to print a lowercase hexadecimal number (base 16).
- **%X**  to print an uppercase hexadecimal number (base 16).
- **%%**  to print the percent symbol.

## How to use. Examples.

The *ft_printf* function works the same as the *printf* function. 

```c
#include "ft_printf.h"

int main(void)
{
   ft_printf("Hello %s, this is my %d proyect \n", "printf_function", 42);
   return (0);
}
//Return: 
> Hello printf_function, this is my 42 proyect
>
```

## About Functions

This project was designed to include the ft_printf function in our own libft library. Therefore, we have reused and remastered many of the functions already present in libft.

### int	function_types(char const *s, va_list arg)
The weight of the printf function's format choice falls on this function. Here you select the type of conversion.

### int ft_putchar((char) va_arg(arg, int))
To print a single character or % caracter.

### int ft_putstr(va_arg(arg, char *))
To print a string. This function is sometimes used with allocated strings, and we need to free their memory before continuing. Therefore, we'll use a wrapper, which is ###int ft_putstr_free(char *str)

### int ft_putnbr(va_arg(arg, int))
To print a decimal number or a integer in base 10. To print an unsigned decimal number (base 10) we have to use that modified funtion ### int ft_putnbr_pos(va_arg(arg, unsigned int)). This is because we are changing the input parameter to an **unsigned integer**.

### char ft_itoa_base(va_arg(arg, int), HEX)
To print a hexadecimal number (base 16). As an input parameter, we pass the type of base 16 we are going to use, which can be uppercase or lowercase.
   **#define HEX_UP "0123456789ABCDEF"**
   **#define HEX_DOWN "0123456789abcdef"**
To print an prints the empty pointer * (base 16) we have to use that modified funtion ### char ft_itoa_base_ptr(ptr, HEX). This is because we are changing the input parameter to an **unsigned long long**. With this change, we would have to control the maximum and minimum values ​​for normal HEX, and we would exceed the number of lines allowed.

## For use inside my libft (M0)

Add the modified functions from the **ft_printf_utils.c** and **ft_printf_utils_itoa.c** section to the sections where the functions with the same name exist in libft.
Then add a new section to include the "ft_printf.c" file. Don't forget to add it to the Makefile and libft.h.

## Author

**ft_printf()** is written and maintained by **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). January 2026.
