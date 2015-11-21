#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int n;  
	
	scanf("%d", &n);
	
	if (n < 2)
		exit(1);
		
	int i; // Contador de iteraciones
	int temp; // Entero temporal para los intercambios iniciales
	
	long x1 = 0, y1 = 0;
	long x2 = 0, y2 = 0; // Se asume que los puntos de entrada son todos distintos entre si
	long x, y;

	scanf("%li %li", &x1, &y1);
	scanf("%li %li", &x2, &y2);   
	
	if (x1 > x2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp; 
	}
	
	if (y1 > y2) // Orden de los puntos. Por convencion, (x1,y1) < (x2,y2)
	{
		temp = y1;
		y1 = y2;
		y2 = temp; 
	}

	for (i = 2; i < n; i++)
	{
		scanf("%li %li", &x, &y);
		
		if (x < x1 && x < x2) // Si x es menor que x1 y que x2, se actualiza x1
			x1 = x;
		else if (x > x1 && x > x2) // Si x es mayor que x1 y que x2, se actualiza x2
			x2 = x; 
		
		if (y < y1 && y < y2) // Igual que antes, para los valores de y
			y1 = y;
		else if (y > y1 && y > y2)
			y2 = y; 
		
	}

	long a = x2 - x1;
	long b = y2 - y1; // Se calcula la distancia entre los puntos

	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1; // Valores absolutos de los resultados
	
	//printf("a: %li \nb: %li\n", a, b);
	
	if (a < b)
		printf("%llu\n", (long long)pow((double)b, 2));
	else if (b < a)
		printf("%llu\n", (long long)pow((double)a, 2));
	else
		printf("%llu\n", (long long)pow((double)a, 2));

	return 0;
}
