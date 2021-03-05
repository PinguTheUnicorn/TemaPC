#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void citire_input( char ***input, int n ) //functie pentru alocare si citire sir de codificat
{
	int i;
	*input = (char **) malloc( n * sizeof(char *) );
	for( i = 0; i < n; i++ )
	{
		(*input)[i] = (char *) malloc( 200 * sizeof(char) );
		fgets((*input)[i], 200, stdin);
		(*input)[i] = (char *) realloc( (*input)[i], ( strlen( (*input)[i] ) + 1 ) * sizeof(char) );
	}
}

void free_all( char ***input, int n ) //functie pentru eliberare memorie
{
	int i;
    for( i = 0; i < n; i++ )
	{
		free( ( (*input)[i] ) );
	}

	free( *input );
}

int verificare_numere( char ***cauta, int n, int m ) //functie pentru verifica daca sirul contine doar numere
{
	int i = 0, ok = 1;
    while( (*cauta)[n][m + i] != ' ' && (*cauta)[n][m + i] != '\n' )
    {
        if( !( (*cauta)[n][m + i] >= 48 && (*cauta)[n][m + i] <= 57 ) )
        {
            ok = 0;
        }
        i++;
    }

	return ok;
}

int main()
{
	/* declarare variabile: sirul in care se introduce textul initial
	variabila pentru codificare, variabila pentru retinerea primului cracter din cuvant */
	char **sir_initial, codex, prima;
	int n, i, j, ok; // declarare variabile: nr linii, contori, variabila pentru verificare

	//cititre numar linii, alocare de memorie si citire text de codificat
	scanf( "%d\n", &n );
	citire_input( &sir_initial, n );

	//codificare
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < strlen( sir_initial[i] ); j++ )
		{
			//se verifica daca actualul caracter este primul pe linie, caz in care se salveaza nemodificat
			if( j == 0 && sir_initial[i][j] != ' ' && sir_initial[i][j] != '\n' )
			{
				codex = sir_initial[i][j];
				printf( "%c", codex );
				prima = sir_initial[i][j];
				ok = verificare_numere( &sir_initial, i, j );
			}
			else
			{
				//se verifica daca caracterul este delimitator de cuvinte, caz in care se salveaza nemodicat
				if( sir_initial[i][j] == ' ' || sir_initial[i][j] == '\n' )
				{
					codex = sir_initial[i][j];
					printf( "%c", codex );
				}
				else
				{
					//se verifica daca caracterul este primul intr-un cuvant
					//caz in care se salveaza si apoi se verifica daca in cuvant sunt doar numere
					if( sir_initial[i][j - 1] == ' ' || sir_initial[i][j] == '\n' )
					{
						codex = sir_initial[i][j];
						printf( "%c", codex );
						prima = sir_initial[i][j];
						ok = verificare_numere( &sir_initial, i, j );
					}
					else
					{
						//se verifica daca in cuvant sunt doar numere; in caz contrar, se face codificarea
						if( ok == 0 )
						{
							codex = ( prima + sir_initial[i][j] ) % 256;
							printf( "%c", codex );
						}
						else
						{
							//se verifica daca in cuvantul actual sunt doar cuvinte
							if( ok == 1 )
							{
								codex = sir_initial[i][j];
								printf( "%c", codex );
							} //daca da, se afiseaza elementul fara codificare
							else
							{
								codex = ( prima + sir_initial[i][j] ) % 256;
								printf( "%c", codex );
							} //in caz contrar, se codifica inainte de afisare
						}
					}
				}
			}
		}
	}

	free_all( &sir_initial, n );

	return 0;
}