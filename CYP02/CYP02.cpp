#include <stdio.h>

int main() {
	int fileSize, pixelPos; //Declaramos variables de entrada
	scanf_s("%i %i", &fileSize, &pixelPos); //Asignamos valores a las variables
	printf("BM%08X00000000%08X", fileSize, pixelPos); //Formateamos la string de salida
	return 0;
}