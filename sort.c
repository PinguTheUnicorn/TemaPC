#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alocare( float ***v, int **a, int n ) //functie pentru alocare memorie
{
	*v = (float **) malloc( n * sizeof(float *) );
	*a = (int *) calloc( n, sizeof(int) );
}

void free_all( float ***v, int **a, int n ) //functie pentru eliberare momorie
{
	int i;
	for( i = 0; i < n; i++ )
	{
		free( (*v)[i] );
	}

	free( *v );
	free( *a );
}

int main()
{
	/* declarare variabile intregi: numar de linii matrice, contori, vector pt. numar de elemente de pe liniile matricei
	variabila pentru alocarea de memorie, auxiliar pentru nr. intregi */
	int n, i, j, *element, cap, aux_i;
	float **note, *auxiliar;   //declarare variabile tip float: matricea notelor, auxiliar pentru float

	//citire nr. de linii ale matricei si alocare de memorie
	scanf( "%d", &n );
	alocare( &note, &element, n );

	//citire elemente matrice
	for( i = 0; i < n; i++ )
	{
		cap = 3;
		note[i] = (float *) malloc( cap * sizeof(float) );

		do
		{
			scanf( "%f", &note[i][element[i]] );
			element[i]++;
			if( element[i] >= cap ) //verificare atingere nr. maxim de elemente alocate
			{
				cap = cap + 3;
				note[i] = (float *) realloc( note[i], cap * sizeof(float) );
			}
		}
		while( note[i][element[i] - 1] != 0 );

		note[i] = (float *) realloc( note[i], element[i] * sizeof(float) );	//alocare de memorie atat cat este necesar
	}

	//calcul valoare medie
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < element[i] - 1; j++ )
		{
			note[i][element[i] - 1] += note[i][j];
		}

		note[i][element[i] - 1] = (float) note[i][element[i] - 1]/(element[i] - 1);
	}

	//sortarea matricei folosind metoda bubble sort
	for( i = 0; i < n - 1; i++ )
	{
		for( j = 0; j < n - i - 1; j++ )
		{
			if( note[j][element[j] - 1] < note[j + 1][element[j + 1] - 1] ) //se verifica daca elementele nu sunt in ordine
			{
				auxiliar = note[j];
				note[j] = note[j + 1];
				note[j + 1] = auxiliar;

				aux_i=element[j];
				element[j]=element[j+1];
				element[j+1]=aux_i;
			} //caz in care se fac permutarile necesare
		}
	}

	//printare matrice
	for( i = 0; i < n; i++ )
	{
		printf( "%-10.3f", note[i][element[i] - 1] );

		for( j = 0; j < element[i] - 1; j++ )
		{
			printf( "%.0f ", note[i][j] );
		}

		printf("\n");
	}

	free_all( &note, &element, n );

	return 0;
}