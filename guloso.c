#include <stdio.h>
#include <stdlib.h>
#include "guloso.h"

int guloso(int *vetor, int n, int k)
{
	int l, c, len_l, len_c;
	len_c = n + 1;
	len_l = (n - k) + 1;
	
	int matriz[len_l][len_c];
	int indice_menor;
	int menor = 100000, posicao = 0;
	
	// Zero a matriz
	for(l = 0; l < len_l; l++)
	{
		for(c = 0; c < len_c; c++)
		{
			matriz[l][c] = 0;
		}
	}
			
	// Preencho a primeira linha "a mao"
	for(c = 0; c < len_c; c++)
	{
		matriz[0][c] = vetor[c];
	}
		
	// Faco as operacoes com matriz
	for(l = 1; l < len_l; l++)
	{	
		menor = 10000;
		posicao = 0;
		for(c = 0; c < len_c; c++)
		{
			// copio a linha anterior
			matriz[l][c] = matriz[l-1][c];
			
		} // end for col
		
		for(c = 0; c < len_c; c++)
		{
			if(menor > matriz[l][c] && matriz[l][c] != -1)
			{
				menor = matriz[l][c];
				posicao = c;
			}	
		}
		
		// Agora que sei quem eh o menor, faco as operacoes
		if((matriz[l][posicao+1]) == -1 && posicao+1 != len_c)
		{
			int aux;
			aux = posicao;
			while((matriz[l][posicao+1]) == -1 && posicao+1 != len_c)
				posicao++;
			
			matriz[l][posicao+1] += matriz[l][aux];
			matriz[l][aux] = 0;
			
		}
		else if (posicao+1 != len_c)
		{
			matriz[l][posicao + 1] += matriz[l][posicao];
			matriz[l][posicao] = -1;
		}
	} // end for line


	int maior = 0;
	for(c = 0; c < len_c; c++)
	{
		if(maior < matriz[len_l-1][c] && matriz[len_l-1][c] != -1)
			maior = matriz[len_l-1][c];	
	}
	
	return maior;
} // fim da funcao do guloso

void ler_dados()
{
	int entradas, n, k;
	int i, j;
	int indice, soma;
	
	scanf("%d", &entradas);
	
	for(i = 0; i < entradas; i++)
	{
		indice = 0;
		scanf("%d %d", &n, &k);
		if(n > 500 || n < 0 || k < 0 || k > 250) break;

		int peso[n + 1];
		for(j = 0; j < n + 1; j++)
		{
			peso[j] = 0;
			scanf("%d", &peso[j]);
		}	

		int result;
		result = guloso(peso, n, k);

		printf("%d\n", result);
	}	

}

