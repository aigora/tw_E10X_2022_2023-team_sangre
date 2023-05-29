#include <stdio.h>

/*Este comando pertenece a parte de la parte de Álvaro. Debido a que por alguna razón no logramos averiguar porque cuando estamos en el menú de comparaciones
y seleccionamos a no se ejecuta y tras revisar varias veces, tanto el switch, dentro del switch y la forma del void para el switch no logramos solucionarlo. 
Tambien hemos intententado crear una unica funcion que aglutine todo el codigo pero ha sido fallido. Aqui esta el código el cuál deberia funcionar y estar 
incluido en el trabajo original, en la linea de comando prinicipal. Se ha incliudo en la wiki imágenes de como sería ejecutado en caso de que también fallará*/


void solicitarAnios(int *anio1, int *anio2) {
    do {
        printf("Ingrese el primer anio entre 2007 y 2023: ");
        scanf("%d", anio1);
    } while (*anio1 < 2007 || *anio1 > 2023);

    do {
        printf("Ingrese el segundo anio entre 2007 y 2023: ");
        scanf("%d", anio2);
    } while (*anio2 < 2007 || *anio2 > 2023);
    
     }
    
void Op_Ficheros_Anios(int anio1, int anio2) {
    char ruta1[100], ruta2[100];
    sprintf(ruta1, "C:\\Users\\user2\\Desktop\\FicherosAnios\\%d.txt", anio1);
    sprintf(ruta2, "C:\\Users\\user2\\Desktop\\FicherosAnios\\%d.txt", anio2);

    FILE *archivo1 = fopen(ruta1, "r");
    FILE *archivo2 = fopen(ruta2, "r");

    if (archivo1 == NULL || archivo2 == NULL) {
        printf("No se pudieron abrir uno o ambos archivos.\n");
        return;
    }

    printf("\nInformación de la producción del año %d:\n\n", anio1);
    
    int numero, numero2, numero3, numero4, numero5, numero6, numero7, numero8, numero9, numero10, numero11, numero12, numero13, numero14, numero15, numero16, numero17, numero18, numero19;

    fscanf(archivo1, "%d", &numero);
    printf("Hidraulica: %d\n", numero);

    fscanf(archivo1, "%d", &numero2);
    printf("Eolica: %d\n", numero2);

    fscanf(archivo1, "%d", &numero3);
    printf("Solar Fotovoltaiva: %d\n", numero3);

    fscanf(archivo1, "%d", &numero4);
    printf("Solar Termica: %d\n", numero4);
    
    fscanf(archivo1, "%d", &numero5);
    printf("Hidroelectrica: %d\n", numero5);
    
    fscanf(archivo1, "%d", &numero6);
    printf("Otras Renovables: %d\n", numero6);

    fscanf(archivo1, "%d", &numero7);
    printf("Resiudos Renovables: %d\n\n", numero7);

    fscanf(archivo1, "%d", &numero8);
    printf("Generacion Renovable: %d\n\n\n", numero8);

    fscanf(archivo1, "%d", &numero9);
    printf("Turbinacion Bombeo: %d\n", numero9);

    fscanf(archivo1, "%d", &numero10);
    printf("Nuclear: %d\n", numero10);

    fscanf(archivo1, "%d", &numero11);
    printf("Ciclo Bombeado: %d\n", numero11);

    fscanf(archivo1, "%d", &numero12);
    printf("Carbon: %d\n", numero12);

    fscanf(archivo1, "%d", &numero13);
    printf("Motores Diesel: %d\n", numero13);

    fscanf(archivo1, "%d", &numero14);
    printf("Turbina de Gas: %d\n", numero14);

    fscanf(archivo1, "%d", &numero15);
    printf("Turbina de Vapor: %d\n", numero15);

    fscanf(archivo1, "%d", &numero16);
    printf("Fuel Gas: %d\n", numero16);

    fscanf(archivo1, "%d", &numero17);
    printf("Cogeneracion: %d\n", numero17);

    fscanf(archivo1, "%d", &numero18);
    printf("Residuos no renovables: %d\n\n", numero18);

    fscanf(archivo1, "%d", &numero19);
    printf("Generacion no renovable: %d\n\n\n", numero19);

    printf("\n");

    printf("Información de la producción del año %d:\n\n", anio2);

    fscanf(archivo2, "%d", &numero);
    printf("Hidraulica: %d\n", numero);

    fscanf(archivo2, "%d", &numero2);
    printf("Eolica: %d\n", numero2);

    fscanf(archivo2, "%d", &numero3);
    printf("Solar Fotovoltaiva: %d\n", numero3);

    fscanf(archivo2, "%d", &numero4);
    printf("Solar Termica: %d\n", numero4);
    
    fscanf(archivo2, "%d", &numero5);
    printf("Hidroelectrica: %d\n", numero5);
    
    fscanf(archivo2, "%d", &numero6);
    printf("Otras Renovables: %d\n", numero6);

    fscanf(archivo2, "%d", &numero7);
    printf("Resiudos Renovables: %d\n\n", numero7);

    fscanf(archivo2, "%d", &numero8);
    printf("Generacion Renovable: %d\n\n\n", numero8);

    fscanf(archivo2, "%d", &numero9);
    printf("Turbinacion Bombeo: %d\n", numero9);

    fscanf(archivo2, "%d", &numero10);
    printf("Nuclear: %d\n", numero10);

    fscanf(archivo2, "%d", &numero11);
    printf("Ciclo Bombeado: %d\n", numero11);

    fscanf(archivo2, "%d", &numero12);
    printf("Carbon: %d\n", numero12);

    fscanf(archivo2, "%d", &numero13);
    printf("Motores Diesel: %d\n", numero13);

    fscanf(archivo2, "%d", &numero14);
    printf("Turbina de Gas: %d\n", numero14);

    fscanf(archivo2, "%d", &numero15);
    printf("Turbina de Vapor: %d\n", numero15);

    fscanf(archivo2, "%d", &numero16);
    printf("Fuel Gas: %d\n", numero16);

    fscanf(archivo2, "%d", &numero17);
    printf("Cogeneracion: %d\n", numero17);

    fscanf(archivo2, "%d", &numero18);
    printf("Residuos no renovables: %d\n\n", numero18);

    fscanf(archivo2, "%d", &numero19);
    printf("Generacion no renovable: %d\n\n\n", numero19);

    printf("\n");

    fclose(archivo1);
    fclose(archivo2);
}

void restarInformacionFicheros(int anio1, int anio2) {
    char ruta1[100], ruta2[100];
    sprintf(ruta1, "C:\\Users\\user2\\Desktop\\FicherosAnios\\%d.txt", anio1);
    sprintf(ruta2, "C:\\Users\\user2\\Desktop\\FicherosAnios\\%d.txt", anio2);

    FILE *archivo1 = fopen(ruta1, "r");
    FILE *archivo2 = fopen(ruta2, "r");

    if (archivo1 == NULL || archivo2 == NULL) {
        printf("No se pudieron abrir uno o ambos archivos.\n");
        return;
    }

    const int NUM_CATEGORIAS = 19;
    const char *nombresCategorias[NUM_CATEGORIAS] = {
        "Hidraulica", "Eolica", "Solar Fotovoltaiva", "Solar Termica",
        "Hidroelectrica", "Otras Renovables", "Resiudos Renovables",
        "Generacion Renovable", "Turbinacion Bombeo", "Nuclear",
        "Ciclo Bombeado", "Carbon", "Motores Diesel", "Turbina de Gas",
        "Turbina de Vapor", "Fuel Gas", "Cogeneracion",
        "Residuos no renovables", "Generacion no renovable"
    };

    int numeros1[NUM_CATEGORIAS];
    int numeros2[NUM_CATEGORIAS];
    int resultado[NUM_CATEGORIAS];

    // Leer los valores del primer archivo
    for (int i = 0; i < NUM_CATEGORIAS; i++) {
        fscanf(archivo1, "%d", &numeros1[i]);
    }

    // Leer los valores del segundo archivo
    for (int i = 0; i < NUM_CATEGORIAS; i++) {
        fscanf(archivo2, "%d", &numeros2[i]);
    }

    // Calcular la resta de los valores
    for (int i = 0; i < NUM_CATEGORIAS; i++) {
        resultado[i] = numeros1[i] - numeros2[i];
    }

    // Mostrar los resultados
    for (int i = 0; i < NUM_CATEGORIAS; i++) {
        printf("%s: %d\n", nombresCategorias[i], resultado[i]);
        
    }
      printf("\n\nEsta observando la diferencia del primer anio entre el segundo anio, datos primer anio menos datos segundo anio\n\n");
    fclose(archivo1);
    fclose(archivo2);
}


int main() {
    printf("En nuestra base de datos contamos con informacion desde el anio 2007 hasta el anio 2023.\nPor favor, indique que anios desea comparar.\n\n");

    int anio1, anio2;

    solicitarAnios(&anio1, &anio2);
   Op_Ficheros_Anios( anio1,  anio2);
   restarInformacionFicheros( anio1,  anio2);

    return 0;
}

