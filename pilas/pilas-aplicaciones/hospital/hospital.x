	/*
- Llegan clientes a un hospital de dos distintos tipos de gravedad.
los de gravedad 1 (mayor gravedad) llegan cada 7 o 8 minutos y los de gravedad 0 (menor gravedad)
cada 4 o 5 minutos 
- Cada cliente tarda entre 2 y 5 minutos para ser atendido. 
Obtener la siguiente información: 
1 - Cantidad de clientes que se atienden en 24 horas.
2 - Cantidad de clientes que hay en cada cola después de 24 horas.
*/

#include<stdio.h>
#include <stdlib.h>
#include "hospital.h"

int main(){
	
	Nodo *cola_grave = NULL, *cola_leve = NULL;
	int minuto, tiempo_llegada_grave, tiempo_llegada_leve, tiempo_atencion = 0,
	contador_graves = 0, contador_leves = 0, atendidos_graves = 0, atendidos_leves = 0;
	
	srand(time(NULL));
	
	tiempo_llegada_grave = rand() % 2 + 7;
	tiempo_llegada_leve = rand() % 2 + 4;
	
	for ( minuto = 0; minuto < 1440; minuto++ ){
		
		if ( minuto >= tiempo_llegada_grave ){
			insertar ( &cola_grave );
			contador_graves++;
			tiempo_llegada_grave = rand() % 2 + 7 + minuto;
		}
		
		if ( minuto >= tiempo_llegada_leve ){
			insertar ( &cola_leve );
			contador_leves++;
			tiempo_llegada_leve = rand() % 2 + 4 + minuto;
		}
		
		if ( minuto >= tiempo_atencion ){
			
    	if ( cola_grave != NULL ){ 
    	
        eliminar ( &cola_grave );
        atendidos_graves++;
        
    	} else if ( cola_leve != NULL ){  
    	
        eliminar ( &cola_leve );
        atendidos_leves++;
        
    	}

    	tiempo_atencion = rand () % 4 + 2 + minuto;
		}
	}
	
	printf ("\nLa cantidad de clientes que se atienden en 24 horas es: %d", atendidos_leves + atendidos_graves );
	printf ("\nLa cantidad de clientes que hay la cola de graves despues de 24 horas es: %d", contador_graves - atendidos_graves );
	printf ("\nLa cantidad de clientes que hay la cola de leves despues de 24 horas es: %d", contador_leves - atendidos_leves );
	
	return 0;
	
}









