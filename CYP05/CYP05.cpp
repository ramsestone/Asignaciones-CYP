#include <stdio.h>
#define ITEMS 2000

int main() {

    int cantidadRegistrosDeEntrada;    
    scanf_s("%i", &cantidadRegistrosDeEntrada);

    // Datos originales
    int numerosDeCuenta[ITEMS];
    float calificaciones[ITEMS];

    // Se leen los datos de entrada y se guardan en arreglos
    for (int i = 0; i < cantidadRegistrosDeEntrada; i++)
    {
        scanf_s("%i %f", &numerosDeCuenta[i], &calificaciones[i]);
    }

    // PRIMERA ETAPA: DESCARTAR CUENTAS REPETIDAS Y GUARDAR SU CALIFICACIÓN MÁXIMA
    // 
    // Encontrar cuentas únicas con su calificaciones máxima
    int numerosCuentasUnicas[ITEMS];
    float maximaCalificacion[ITEMS];
    // Inicialmente no hay cuentas únicas
    int totalUnicas = 0;


    for (int i = 0; i < cantidadRegistrosDeEntrada; i++)
    {
        // Declara la bandera
        int encontrada = 0;

        // Se busca si la cuenta existe en el arreglo cuentasUnicas
        for (int j = 0; j < totalUnicas; j++)
        {
            // i para el indice del arreglo de entrada y j para el indice del arreglo de salida
            if (numerosDeCuenta[i] == numerosCuentasUnicas[j])
            {
                // Se alza la bandera
                encontrada = 1;
                // Se compara la calificacion actual con la almacenada en el arreglo maximaCalificacion
                if (calificaciones[i] > maximaCalificacion[j])
                {
                    // Se reemplaza en dado caso
                    maximaCalificacion[j] = calificaciones[i];
                }
                // Se rompe bucle cuando se encuentra la cuenta que queremos comparar para evitar recorrer todas
                break;
            }
        }
        // Si no se encuentra una cuenta en el arreglo totalUnicas significa que es una entrada nueva

        if (!encontrada)
        {
            // Se añade la entrada nueva en el orden que se encuenta
            numerosCuentasUnicas[totalUnicas] = numerosDeCuenta[i];
            maximaCalificacion[totalUnicas] = calificaciones[i];
            totalUnicas++;
        }
    }

    // SEGUNDA ETAPA: ORDENAMIENTO POR NÚMERO DE CUENTA USANDO EL MÉTODO DE LA BURBUJA
    // n = pasadas totales; i = indice a comparar
    for (int n = 0; n < totalUnicas - 1; n++)
    {
        int banderaDeIntercambio = 0;

        for (int i = 0; i < totalUnicas - 1; i++)
        {
            if (numerosCuentasUnicas[i] > numerosCuentasUnicas[i + 1])
            {
                // Se reasignan los valores de la siguiente manera: 
                // indice1 -> variable temporal -> indice2 -> indice1
                int numCuentaTemp = numerosCuentasUnicas[i];
                numerosCuentasUnicas[i] = numerosCuentasUnicas[i + 1];
                numerosCuentasUnicas[i + 1] = numCuentaTemp;

                float calificacionTemp = maximaCalificacion[i];
                maximaCalificacion[i] = maximaCalificacion[i + 1];
                maximaCalificacion[i + 1] = calificacionTemp;

                // Hubo intercambio. Se alza la bandera.
                banderaDeIntercambio = 1;
            }
        }

        // Si en esta pasada hubo intercambio salimos del bucle
        if (!banderaDeIntercambio)
        {
            break;
        }
    }

    // TERCERA ETAPA: IMPRIMIR RESULTADO

    /*
    * FORMATO DESEADO:
    * 6                  || Total de alumnos únicos
    * 311728124 6.300000 || no.cuenta calificacion
    * 313138303 9.000000 || no.cuenta calificacion
    * 313191515 4.800000 || no.cuenta calificacion
    * 313212302 3.100000 || no.cuenta calificacion
    * 313327575 1.800000 || no.cuenta calificacion
    * 313333773 3.300000 || no.cuenta calificacion
    */
    printf("%i\n", totalUnicas);
    for (int i = 0; i < totalUnicas; i++)
    {
        printf("%i %f\n", numerosCuentasUnicas[i], maximaCalificacion[i]);
    }

    return 0;
}