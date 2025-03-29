/*
- Llegan clientes a la puerta del cajero cada 2 ó 3 minutos. 
- Cada cliente tarda entre 2 y 4 minutos para ser atendido. 
Obtener la siguiente información: 
1 - Cantidad de clientes que se atienden en 10 horas.
2 - Cantidad de clientes que hay en cola después de 10 horas. 
3 - Hora de llegada del primer cliente que no es atendido luego de 10 horas (es
decir la persona que está primera en la cola cuando se cumplen 10 horas).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aplicacion-cola.h"

int main() {
	
	int minuto, contador_llegadas = 0, contador_atendidos = 0, tiempo_llegada = 0, tiempo_atender = 0, intervalo;
	
    srand(time(NULL));
    
    Nodo* cola = NULL;
    
    for ( minuto = 0; minuto < 600; minuto++ ){
    	
    	if ( minuto >= tiempo_llegada ){
    		contador_llegadas++;
    		insertar( &cola, minuto );
    		intervalo = rand() % 2 + 2;
    		tiempo_llegada = intervalo + minuto;
		}
		
		if ( minuto >= tiempo_atender && contador_llegadas > contador_atendidos){
    		contador_atendidos++;
    		eliminar( &cola );
    		intervalo = rand() % 3 + 2;
    		tiempo_atender = intervalo + minuto;
		}
	}
	
	Nodo *siguiente_sin_atender = frente(&cola);
	
	printf ("\nLa cantidad de clientes que se atienden en 10 horas es: %d", contador_atendidos );
	printf ("\nLa cantidad de clientes que hay en cola despues de 10 horas es: %d", contador_llegadas - contador_atendidos );
	printf ("\nLa hora de llegada del primer cliente que no es atendido luego de 10 horas es: %d minutos", siguiente_sin_atender->tiempo_llegada );
}






















