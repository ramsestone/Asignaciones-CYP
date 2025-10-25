# include <stdio.h>
# include <math.h>

int main() 
{
	double limInicial, limFinal, incremento, resultadoSinLibreria, resultadoConLibreria, valorACalcular;

	scanf_s("%lf %lf %lf", &limInicial, &limFinal, &incremento);
	int pasos = ((limFinal - limInicial) / incremento);
	//Asignamos un número más grande de iteraciones para calcular euler, para mayor presición.
	double pasosParaTaylor = pasos + 1;

	for (int iteracion = 0; iteracion <= pasos; iteracion++)
	{
		// Serie de Taylor = 1 + x + x^n/n! ...
		// x = valorACalcular
		// n = pasos + 1
		// e^x = resultadoSinLibreria
		// x^n / n! = termino
		valorACalcular = limInicial + iteracion * incremento;
		double termino = 1.0f;
		resultadoSinLibreria = 1.0f;
		for (int i = 1; i < pasosParaTaylor; i++)
		{
			termino = termino * valorACalcular / i;
			resultadoSinLibreria = resultadoSinLibreria + termino;
		}

		resultadoConLibreria = exp(valorACalcular);
		printf("%lf %lf %lf\n", valorACalcular, resultadoSinLibreria, resultadoConLibreria);
	}


}