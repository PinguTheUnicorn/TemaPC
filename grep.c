#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_str( char old_string[30], char new_string[40] ) //functie pentru a genera sirul colorat
{
	strcpy( new_string, "\e[0;31m" );
	strcpy( new_string + 7, old_string );
	strcpy( new_string + 7 + strlen( old_string ), "\e[m" );
}

void alocare( char ***sir, int n ) //functie pentru alocare memorie matrice
{
	int i;
	*sir = (char **) malloc( n * sizeof(char *) );

	for( i = 0; i < n; i++ )
	{
		(*sir)[i] = (char *) malloc( 200 * sizeof(char) );
	}
}

void free_all( char ***sir, int n ) //functie pentru eliberare memorie
{
	int i;
	for( i = 0; i < n; i++ )
	{
		free( (*sir)[i] );
	}

	free( *sir );
}

int main()
{
	//declarare variabile: sir de cautat, sir ce va inlocui, matricea in care se cauta
	char lookup_str[30], new_str[40], **sir_input, *auxiliar;
	int n, i, j; //declarare nr. linii, contori, nr, pozitii peste care se face introducerea noului sir

	//input sir cautat si generarea sirului cu care se inlocuieste
	fgets( lookup_str, 30, stdin );
	//exista cazuri cand imi citeste "\n" la finalul lui lookup_str, aceasta apelare imi elimina respectivul caracter
	lookup_str[strcspn( lookup_str, "\n" )] = 0;
	create_str( lookup_str, new_str );

	//alocarea si introducerea sirurilor
	scanf( "%d\n", &n );
	alocare( &sir_input, n );

	for( i = 0; i < n; i++ )
	{
		fgets( sir_input[i], 200, stdin );
		sir_input[i] = (char *) realloc( sir_input[i], ( strlen( sir_input[i]) + 1 ) * sizeof(char) );
	}

	//schimbare sir cautat cu cel colorat
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < strlen( sir_input[i] ); j++ )
		{
			//daca adresa sirului cautat este aceeasi cu adresa actuala, se face schimbarea sirului cu cel colorat
			if( strstr( &sir_input[i][j], lookup_str ) == &sir_input[i][j] )
			{
				//se aloca spatiul pentru matricea auxiliara
				auxiliar = (char *) malloc( ( strlen( strstr( &sir_input[i][j], lookup_str ) ) + 11 ) * sizeof(char) );

				strcpy( auxiliar, new_str ); //se copiaza noul sir in auxiliar
				//se copiaza restul sirului, fara sirul cautat
				strcat( auxiliar, strstr( &sir_input[i][j], lookup_str ) + strlen( lookup_str ) );
				//se copiaza auxiliar la adresa unde s-a gasit sirul cautat
				strcpy( &sir_input[i][j], auxiliar );
				free( auxiliar ); //se elibereaza memoria pentru auxiliar

				j = j + strlen( new_str ); //se sare peste un numar de elemente egal cu continutul noului sir
			}
		}
	}

    //afisare output
	for( i = 0; i < n; i++ )
	{
		if( strstr( sir_input[i], new_str ) )
        {
            printf( "%s", sir_input[i] );
    	}
	}

	free_all( &sir_input, n );

	return 0;
}