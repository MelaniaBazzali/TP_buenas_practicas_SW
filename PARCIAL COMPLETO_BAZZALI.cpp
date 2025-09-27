#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct libros{
	char titulo[100];
	char autor[50];
	int a;
}libro[MAX];

void agregar(struct libros libro[],int *cantidad);
void mostrar(struct libros libro[],int *cantidad);
void buscarT(struct libros libro[],int *cantidad);
void buscarAutor(struct libros libro[],int *cantidad);
void buscarA(struct libros libro[],int *cantidad);
void guardar(struct libros libro[],int *cantidad);
void buscarArchivo(struct libros libro[],int *cantidad);

int main(int argc, char *argv[]) {
	int op,cantidad=0;
	struct libros libro[MAX];
	
	do
	{
		printf("\nELIJA UNA OPCION: \n1-Añadir libro\n2-Mostrar la lista de libros\n3-Buscar un libro por su titulo\n4-Buscar un libro por su autor\n5-Buscar un libro por su año de publicación\n6-Buscar con archivo\n7-Guardar la lista de Libros\n0-Salir\n");
		scanf("%d",&op);
		getchar();
		switch(op)
		{
		case 1:
			agregar(libro,&cantidad);
			break;
		case 2:
			mostrar(libro,&cantidad);
			break;
		case 3:
			buscarT(libro,&cantidad);
			break;
		case 4:
			buscarAutor(libro,&cantidad);
			break;
		case 5:
			buscarA(libro,&cantidad);
			break;
		case 6:
			buscarArchivo(libro,&cantidad);
			break;
		case 7:
			guardar(libro,&cantidad);
			break;
		}
	}while(op!=0);
	
	return 0;
}

void agregar(struct libros libro[],int *cantidad)
{
	if(*cantidad>=MAX)
	{
		printf("\nNo se pueden añadir más libros\n\n");
		return;
	}
	
	do
	{
		printf("Ingrese el titulo del libro: ");
		fgets(libro[*cantidad].titulo,100,stdin);
		
		printf("Ingrese el autor del libro: ");
		fgets(libro[*cantidad].autor,50,stdin);
		
		printf("Ingrese el año de publicacion: ");
		scanf("%d",&libro[*cantidad].a);
	} while(*cantidad>=MAX);
	
	getchar();
	*cantidad=*cantidad+1;
	printf("\nLibro agregado correctamente\n\n");
}

void mostrar(struct libros libro[],int *cantidad)
{
	int i;
	if(*cantidad==0)
	{
		printf("\nNo hay libros registrados\n\n");
		return;
	}
	
	for(i=0;i<*cantidad;i++)
	{
		printf("\nLIBRO: %d\n",i+1);
		printf("Titulo: %s",libro[i].titulo);
		printf("Autor: %s",libro[i].autor);
		printf("Año de publicacion: %d\n",libro[i].a);
	}
	getchar();
}

void buscarT(struct libros libro[],int *cantidad)
{
	int i,a=0;
	char buscartitulo[100];
	
	if(*cantidad==0)
	{
		printf("\nNo hay libros registrados\n");
		return;
	}
	
	printf("\nIngrese el TITULO a buscar:\n");
	fgets(buscartitulo,100,stdin);
	for(i=0;i<*cantidad;i++)
	{
		if(strcmp(libro[i].titulo,buscartitulo)==0)
		{                                             
			printf("\nLibro encontrado exitosamente:\n");
			printf("\nLIBRO: %d\n",i+1);
			printf("Titulo: %s",libro[i].titulo);
			printf("Autor: %s",libro[i].autor);
			printf("Año de publicacion: %d\n",libro[i].a);
			a=1;
		}
	}
	if(a==0)
	{
		printf("\nNo se encontraron libros con ese TITULO\n");
	}
}

void buscarAutor(struct libros libro[],int *cantidad)
{
	int i,a=0;
	char buscarautor[50];
	
	if(*cantidad==0)
	{
		printf("\nNo hay libros registrados\n");
		return;
	}
	
	printf("\nIngrese el AUTOR a buscar:\n");
	fgets(buscarautor,50,stdin);
	for(i=0;i<*cantidad;i++)
	{
		if(strcmp(libro[i].autor,buscarautor)==0)
		{                                             
			printf("\nLibro encontrado exitosamente:\n");
			printf("\nLIBRO: %d\n",i+1);
			printf("Titulo: %s",libro[i].titulo);
			printf("Autor: %s",libro[i].autor);
			printf("Año de publicacion: %d\n",libro[i].a);
			a=1;
		}
	}
	if(a==0)
	{
		printf("\nNo se encontraron libros con ese AUTOR\n");
	}
}

void buscarA(struct libros libro[],int *cantidad)
{
	int i,a=0,pub;
	
	if(*cantidad==0)
	{
		printf("\nNo hay libros registrados\n");
		return;
	}
	
	printf("\nIngrese el AÑO DE PUBLICACION a buscar:\n");
	scanf("%d",&pub);
	for(i=0;i<*cantidad;i++)
	{
		if(libro[i].a==pub)
		{                                             
			printf("\nLibro encontrado exitosamente:\n");
			printf("\nLIBRO: %d\n",i+1);
			printf("Titulo: %s",libro[i].titulo);
			printf("Autor: %s",libro[i].autor);
			printf("Año de publicacion: %d\n",libro[i].a);
			a=1;
		}
	}
	if(a==0)
	{
		printf("\nNo se encontraron libros con ese AÑO DE PUBLICACION\n");
	}
	getchar();
}

void buscarArchivo(struct libros libro[],int *cantidad)
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

void guardar(struct libros libro[],int *cantidad)
{
	int i;
	FILE *lista;
	
	if(*cantidad==0)
	{
		printf("\nNo hay libros registrados\n");
		return;
	}
	
	lista=fopen("lista.txt","w");
	
	if(lista!=NULL)
	{
		for(i=0;i<*cantidad;i++)
		{
			fputs(libro[i].titulo,lista);
			fputs(libro[i].autor,lista);
			fprintf(lista,"%d\n\n",libro[i].a);
		}
		printf("Se ha terminadoo de escribir el archivo...\n");
	}else printf("\nProblemas al abrir el archivo.");
	fclose(lista);
}
