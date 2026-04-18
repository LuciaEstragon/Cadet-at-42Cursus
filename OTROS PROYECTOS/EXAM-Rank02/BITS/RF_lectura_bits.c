/*
 PROGRAMA PARA LA LECTURA DE RF

 Transmitimos 8 bits.
 El mensaje siempre empieza por 1 y termina por 1 y lo demas son 0.
 El mensaje se repite dos veces.
 El bit de paridad es el bit 7.

 0000001xxxxxP11xxxxxP100---
 */

/*
 * ESTO ES COMO UN GNL DE BITS: 
 * 1)  Tendriamos que crear un buffer de lectura. No podemos leer continuamente de la antena, porque paralizaria todos los procesos. 
 *			BUFFER_SIZE = 32; (por ejemplo)
 * 2)  Entre esta info tenemos que encontrar el primer bit a 1 y guardar el mensaje, que es doble, dos de 8 bits.
 * 3)  Control de errores:
 *	3.a) Comprobamos que pos_0 y pos_7 sean 1.
 *	3.b) Comprobamos la paridad : pos_6
 *	3.c) Comprobamos que el primer mensaje y el segundo son identicos
 *	** Si falla en alguno de ellos se descarta como mensaje y se sigue preguntando hasta encontrar el siguiente bit=1.
 * NOTA:  El mensaje que recibe el coche teledirigido no se actualiza hasta tener un mensaje valido. Por ello, si el mensaje anterior recibido fue ir recto, y perdemos paquetes de info, el coche sigue llendo recto un "rato". Ese "rato" igual hay que hacerlo finito, y si no recibes nada coherente nuevo detenerte, porque igual la señal es todo 0, y eso tambien es un mensaje.
 *
 */

#include <stdio.h>
#include <stdint.h>

uint8_t package_one (uint8_t mess)
{	
	if( (((mess >> 7) & 1) == 1) && (((mess >>0) & 1)== 1))
		return (0);
	return (1);
}
int8_t parity_bit (uint8_t mess)
{
	uint8_t i = 0;
	uint8_t count = 0;
	while (i < 8)
	{
		count += ((mess >> i) & 1);
		i++;
	}
	if(!(count%2))
                return (0);
        return (1);
}

uint8_t error_control (/*uint16_t real_message*/)
{
	//mensajes de prueba
	uint8_t message[8] = {1, 0, 0, 1, 0, 1, 0, 1};
	uint8_t message_error1[8] = {1, 0, 0, 1, 0, 1, 0, 0};
	uint8_t message_error2[8] = {1, 0, 0, 1, 0, 1, 1, 1};
	
	//1) el primero y el ultimo son 1
	// si el mensaje se transmite entre 'unos', esta funcion responde OK = 0
	if (!package_one(&message_error1))
		return (1);
	//2) bit de paridad; PAR=0, IMPAR=1;
	// si el bit de paridad esta bien, esta funcion responde OK = 0
	if (!parity_bit(&message_error2))
		return (1);
	//3) diff_error; si el mensaje no contiene dos veces el propio mensaje
	return (0);
}


int main()
{
	// hacer un GNL con BUFFER_SIZE, acumulando info de lectura.
	// interpretar  esta info
	uint16_t lectura[16];
	uint8_t message[8];

	printf("%u ",error_control()); // esto es para probar, tendriamos que escribir algo bien escrito pero parecido a lo de abajo
	//if (!error_control(/*lectura*/))
		//message=lectura;

	// con ese mensaje activo cosas - motores, velocidad.. 
	return (0);
}
