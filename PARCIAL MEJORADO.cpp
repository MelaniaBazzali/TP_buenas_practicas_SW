#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 10 // Mejora: constante con nombre significativo para evitar "número mágico"

// Mejora: Se renombró la estructura a Libro (nombres en singular para entidades individuales)
typedef struct {
	char titulo[100];
	char autor[50];
	int anio_publicacion; // Mejora: nombre descriptivo
} libro;

// Mejora: se agregaron comentarios descriptivos sobre la función
void agregar_libro(libro libros[], int *cantidad);
void mostrar_libros(const libro libros[], int cantidad);
void buscar_por_titulo(const libro libros[], int cantidad);
void buscar_por_autor(const libro libros[], int cantidad);
void buscar_por_anio(const libro libros[], int cantidad);
void guardar_libros(const libro libros[], int cantidad);
void buscar_en_archivo();

// Mejora: Función principal clara y ordenada, nombres descriptivos y sin código innecesario
int main(int argc, char *argv[]) {
	int opcion, cantidad_libros = 0;
	libro libros[MAX_LIBROS];
	
	do {
		printf("\nELIJA UNA OPCION:\n");
		printf("1 - Añadir libro\n");
		printf("2 - Mostrar lista de libros\n");
		printf("3 - Buscar libro por título\n");
		printf("4 - Buscar libro por autor\n");
		printf("5 - Buscar libro por año\n");
		printf("6 - Buscar desde archivo\n");
		printf("7 - Guardar libros\n");
		printf("0 - Salir\n");
		printf("Opción: ");
		scanf("%d", &opcion);
		getchar(); // Mejora: limpiar buffer luego del scanf
		
		switch(opcion) {
		case 1: 
			agregar_libro(libros, &cantidad_libros); 
			break;
		case 2: 
			mostrar_libros(libros, cantidad_libros); 
			break;
		case 3: 
			buscar_por_titulo(libros, cantidad_libros); 
			break;
		case 4: 
			buscar_por_autor(libros, cantidad_libros); 
			break;
		case 5: 
			buscar_por_anio(libros, cantidad_libros); 
			break;
		case 6: 
			buscar_en_archivo(); 
			break;
		case 7: 
			guardar_libros(libros, cantidad_libros); 
			break;
		case 0: 
			printf("Saliendo...\n"); 
			break;
		default: 
			printf("Opción no válida.\n"); 
			break;
		}
	} while (opcion != 0);
	
	return 0;
}

/*
 Agrega un nuevo libro a la lista
 libros arreglo de libros
 cantidad puntero a cantidad actual de libros
*/
void agregar_libro(libro libros[], int *cantidad) 
{
	if (*cantidad >= MAX_LIBROS) 
	{
		printf("No se pueden añadir más libros.\n");
		return;
	}
	
	printf("Ingrese el título del libro: ");
	fgets(libros[*cantidad].titulo, sizeof(libros[*cantidad].titulo), stdin);
	
	printf("Ingrese el autor del libro: ");
	fgets(libros[*cantidad].autor, sizeof(libros[*cantidad].autor), stdin);
	
	printf("Ingrese el año de publicación: ");
	scanf("%d", &libros[*cantidad].anio_publicacion);
	getchar();
	
	(*cantidad)++;
	printf("Libro agregado correctamente.\n");
}

//Muestra todos los libros registrados
void mostrar_libros(const libro libros[], int cantidad) 
{
	int i;
	if (cantidad == 0) 
	{
		printf("No hay libros registrados.\n");
		return;
	}
	
	for (i = 0; i < cantidad; i++) 
	{
		printf("\nLIBRO %d\n", i + 1);
		printf("Título: %s", libros[i].titulo);
		printf("Autor: %s", libros[i].autor);
		printf("Año de publicación: %d\n", libros[i].anio_publicacion);
	}
	getchar();
}

//Busca un libro por su título
void buscar_por_titulo(const libro libros[], int cantidad) 
{
	if (cantidad == 0) 
	{
		printf("No hay libros registrados.\n");
		return;
	}
	
	char titulo_buscado[100];
	int encontrado = 0, i;
	
	printf("Ingrese el título a buscar: ");
	fgets(titulo_buscado, sizeof(titulo_buscado), stdin);
	
	for (i = 0; i < cantidad; i++) 
	{
		if (strcmp(libros[i].titulo, titulo_buscado) == 0) 
		{
			printf("\nLibro encontrado:\n");
			printf("Título: %s", libros[i].titulo);
			printf("Autor: %s", libros[i].autor);
			printf("Año de publicación: %d\n", libros[i].anio_publicacion);
			encontrado = 1;
		}
	}
	
	if (encontrado == 0) 
	{
		printf("No se encontró ningún libro con ese título.\n");
	}
}

//Busca libros por autor
void buscar_por_autor(const libro libros[], int cantidad) 
{
	if (cantidad == 0) 
	{
		printf("No hay libros registrados.\n");
		return;
	}
	
	char autor_buscado[50];
	int encontrado = 0, i;
	
	printf("Ingrese el autor a buscar: ");
	fgets(autor_buscado, sizeof(autor_buscado), stdin);
	
	for (i = 0; i < cantidad; i++) 
	{
		if (strcmp(libros[i].autor, autor_buscado) == 0) 
		{
			printf("\nLibro encontrado:\n");
			printf("Título: %s", libros[i].titulo);
			printf("Autor: %s", libros[i].autor);
			printf("Año de publicación: %d\n", libros[i].anio_publicacion);
			encontrado = 1;
		}
	}
	
	if (encontrado == 0) 
	{
		printf("No se encontró ningún libro con ese autor.\n");
	}
}

//Busca libros por año de publicación
void buscar_por_anio(const libro libros[], int cantidad) 
{
	if (cantidad == 0) 
	{
		printf("No hay libros registrados.\n");
		return;
	}
	
	int anio_buscado, encontrado = 0, i;
	printf("Ingrese el año de publicación a buscar: ");
	scanf("%d", &anio_buscado);
	getchar();
	
	for (i = 0; i < cantidad; i++) 
	{
		if (libros[i].anio_publicacion == anio_buscado) 
		{
			printf("\nLibro encontrado:\n");
			printf("Título: %s", libros[i].titulo);
			printf("Autor: %s", libros[i].autor);
			printf("Año de publicación: %d\n", libros[i].anio_publicacion);
			encontrado = 1;
		}
	}
	
	if (encontrado == 0) 
	{
		printf("No se encontró ningún libro con ese año.\n");
	}
}

//Lee un archivo de texto y muestra su contenido
void buscar_en_archivo() 
{
	char titulo[100];
	FILE *parcial;
	
	parcial=fopen("parcial.txt","r");
	if(parcial!=NULL)
	{
		int i=0;
		while( !feof(parcial) ) {
			titulo[i]=fgetc(parcial);
			i++;        
		}
		titulo[i]='\0';
		printf("Se ha terminadoo de leer el archivo...\n");
	}else printf("\nProblemas al abrir el archivo.");
	fclose(parcial);
	printf("\nLIBROS ENCONTRADOS:\n");
	printf("%s",titulo);
}

//Guarda los libros en un archivo de texto
void guardar_libros(const libro libros[], int cantidad) 
{
	int i;
	FILE *lista;
	
	if(cantidad == 0)
	{
		printf("\nNo hay libros registrados\n");
		return;
	}
	
	lista=fopen("lista.txt","w");
	
	if(lista!=NULL)
	{
		for(i = 0; i < cantidad; i++)
		{
			fputs(libros[i].titulo,lista);
			fputs(libros[i].autor,lista);
			fprintf(lista,"%d\n\n",libros[i].anio_publicacion);
		}
		printf("Se ha terminadoo de escribir el archivo...\n");
	}else printf("\nProblemas al abrir el archivo.");
	fclose(lista);
}
