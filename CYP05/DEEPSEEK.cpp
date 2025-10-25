#include <stdio.h>
#define ITEMS 2000

int main() {
    int cantidad_registros;

    // Leer el número de registros
    scanf_s("%d", &cantidad_registros);

    // Arreglos para almacenar los datos originales
    int numerosDeCuenta[ITEMS];
    float calificaciones[ITEMS];

    // Leer todos los datos
    for (int i = 0; i < cantidad_registros; i++) {
        scanf_s("%i %f", &numerosDeCuenta[i], &calificaciones[i]);
    }

    // Paso 1: Encontrar cuentas únicas y su máxima calificación
    int cuentas_unicas[ITEMS];
    float max_calificaciones[ITEMS];
    int total_unicas = 0;

    for (int i = 0; i < cantidad_registros; i++) {
        int encontrada = 0;

        // Buscar si la cuenta ya existe en cuentas_unicas
        for (int j = 0; j < total_unicas; j++) {
            if (numerosDeCuenta[i] == cuentas_unicas[j]) {
                encontrada = 1;
                // Actualizar la calificación máxima
                if (calificaciones[i] > max_calificaciones[j]) {
                    max_calificaciones[j] = calificaciones[i];
                }
                // Rompemos bucle cuando se encuentra la cuenta que queremos comparar para evitar recorrer todas
                break;
            }
        }

        // Si no se encontró, agregar nueva cuenta
        if (!encontrada) {
            cuentas_unicas[total_unicas] = numerosDeCuenta[i];
            max_calificaciones[total_unicas] = calificaciones[i];
            total_unicas++;
        }
    }

    // Paso 2: Ordenar las cuentas únicas de menor a mayor (usando método de la burbuja)
    for (int i = 0; i < total_unicas - 1; i++) {
        for (int j = 0; j < total_unicas - i - 1; j++) {
            if (cuentas_unicas[j] > cuentas_unicas[j + 1]) {
                // Intercambiar cuentas
                int temp_cuenta = cuentas_unicas[j];
                cuentas_unicas[j] = cuentas_unicas[j + 1];
                cuentas_unicas[j + 1] = temp_cuenta;

                // Intercambiar calificaciones correspondientes
                float temp_calif = max_calificaciones[j];
                max_calificaciones[j] = max_calificaciones[j + 1];
                max_calificaciones[j + 1] = temp_calif;
            }
        }
    }

    // Paso 3: Imprimir el resultado
    printf("%d\n", total_unicas);
    for (int i = 0; i < total_unicas; i++) {
        printf("%i %f\n", cuentas_unicas[i], max_calificaciones[i]);
    }

    return 0;
}