#include <stdio.h>
#include <stdlib.h>
#include "guloso.h"

int main(int argc, char *argv[])
{
	
	if((argv[1][0] == '-') && (argv[1][1] == 'a'))
	{	
		if((argv[2][0] == 'A') && (argv[2][1] == 'G'))
		{
			ler_dados();			
		} // Fim do algoritmo guloso
	} // fim casos do arg
	
	return 0;
}
