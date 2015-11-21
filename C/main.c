/*
Actividad Ayudantia 2 - 18/11
Alejandro Sepulveda, 201373544-4
Beatriz Latorre, 201573543-3
P201, Pedro Godoy
*/


#include <stdio.h> // printf, fopen, fclose, feof
#include <stdlib.h> // malloc, free, exit
#include <string.h> // strlen, strcpy, strcmp
#include <ctype.h> // toupper

int main()
{
	typedef struct
	{
		char titulo[20+1];
		int anno;
		int arrendado;
		char nombreArrendador[20+1];
	} datosBiblioteca;
	
	
	datosBiblioteca librosBiblioteca[5];
	
	// Libros definidos por defecto. Posiciones 0 y 1
	strcpy(librosBiblioteca[0].titulo, "El principito\0");
	librosBiblioteca[0].anno = 1951;
	librosBiblioteca[0].arrendado = 15;
	strcpy(librosBiblioteca[0].nombreArrendador, "Jose Luis Marti\0");
	
	strcpy(librosBiblioteca[1].titulo, "Manual para calvos\0");
	librosBiblioteca[1].anno = 2015;	
	librosBiblioteca[1].arrendado = 1;
	strcpy(librosBiblioteca[1].nombreArrendador, "Pedro Godoy\0");
	
	int i;
	
	for (i = 2; i < 5; i++)
	{
		char stringTemp[20+1];
		printf("Ingrese los datos del libro %d\n", i+1);
		
		printf("Titulo: ");
		// scanf("%20[^\n]s", stringTemp); // Lee todo hasta el primer \n 
		scanf("%s", stringTemp);

		strcpy(librosBiblioteca[i].titulo, stringTemp);
		
		printf("Anno de publicacion: ");
		scanf("%d", &librosBiblioteca[i].anno);
		
		printf("Veces arrendado: ");
		scanf("%d", &librosBiblioteca[i].arrendado);

		printf("Nombre del ultimo arrendador: ");
		// scanf("%20[^\n]s", stringTemp); // Usar el metodo anterior lee el \n del scanf("%d") anterior
		scanf("%s", stringTemp);

		strcpy(librosBiblioteca[i].nombreArrendador, stringTemp);
	}

	int flag = -1;
	
	while (flag != 0)
	{
		printf("Opciones disponibles\n");
		printf("(1) Ver el listado de libros\n");
		printf("(2) Prestar un libro\n");
		printf("(3) Listar libros por abecedario\n");
		printf("(0) Salir\n");
		printf("Seleccione una opcion: ");
		
		scanf("%d", &flag);		

		switch (flag)
		{
			case 0:
				flag = 0;
				break;
			
			case 1:
				printf("\n");
				printf("Listado de libros:\n");
				
				for (i = 0; i < 5; i++)
				{
					printf("%s\n", librosBiblioteca[i].titulo);
				}
				
				break;

		
			case 2:
				printf("\n");
				int libro = 0;
				char nombreUsuario[20+1] = "";
				
				printf("Seleccione un libro, del 1 al 5: ");
				scanf("%d", &libro);
				
				printf("Ingrese su nombre: ");
				scanf("%s", nombreUsuario);
				
				librosBiblioteca[libro-1].arrendado++;
				strcpy(librosBiblioteca[libro-1].nombreArrendador, nombreUsuario);
				
				printf("Ha retirado el libro %s, a nombre de %s\n", librosBiblioteca[libro-1].titulo, nombreUsuario);
				
				break;
				
		
			case 3:
				printf("\n");
				printf("Listado de libros por abecedario\n");			
				char letra1, letra2;
				printf("Ingrese las letras (separadas por un espacio): ");
				scanf("%s %s", &letra1, &letra2); // Porque aqui funciona?
			
				if (toupper(letra1) > toupper(letra2))
				{
					char temp = toupper(letra1);
					letra1 = toupper(letra2);
					letra2 = toupper(temp);
				}
				
				printf("Libros en el rango %c - %c\n", letra1, letra2);
			
				for (i = 0; i < 5; i++)
				{
					if (toupper(letra1) <= toupper(librosBiblioteca[i].titulo[0])
						&& toupper(librosBiblioteca[i].titulo[0]) <= toupper(letra2))
					{
						printf("%s\n", librosBiblioteca[i].titulo);
					}
				}
				printf("\n");
				break;
		
			default:
				break;
		
		}
		
	}
	
	return 0;
}
