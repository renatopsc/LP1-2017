/**
 * @file	anterior.c
 * @brief	Programa que determina o maior numero primo inteiro anterior ao
 *			fatorial de um numero fornecido pelo usuario via linha de comando
 * @author	Everton Cavalcante (everton@dimap.ufrn.br)
 * @author	Silvio Sampaio (silviocs@imd.ufrn.br)
 * @since	14/02/2017
 * @date	15/02/2017
 */

#include <stdlib.h>
#include <stdio.h>


/**
 * @brief Funcao que calcula de forma recursiva o fatorial de um numero inteiro
 * @param n Numero inteiro cujo fatorial sera calculado
 * @return Fatorial do numero em questao
 */
long int fatorial(int n) {
	if (n == 0) {				// Caso base da recursao
		return 1;
	}
	return n * fatorial(n-1);	// Chamada recursiva
}


/**
 * @brief Funcao que verifica se um dado numero inteiro e primo
 * @details Um numero e dito primo quando ele nao possui outro divisor
 *			(ou seja, o resto da divisao e zero) alem de 1 e ele mesmo
 * @param n Numero em questao
 * @param d Divisor a ser testado
 * @return 0, se o numero for primo, ou 1, caso contrario
 */
int ehPrimo(int n, int d) {
	if (n == 1) {
		return 0;						// 1 nao e numero primo
	} else {
		if (d == 1) {
			return 1;					// Caso base da recursao
		} else {
			if (n % d == 0) {
				return 0;				// Divisor encontrado: o numero nao e primo
			} else {
				return ehPrimo(n, d-1);	// Chamada recursiva
			}
		}
	}
}


/**
 * @brief Retorna o maior numero primo que seja menor que o numero em questao
 * @param n Numero
 * @return Maior numero primo menor que o numero
 */
long int maiorPrimo(int n) {
	for (int i = n; i > 2; i--) {
		if (ehPrimo(i, i-1)) {
			return i;
		}
	}
	return n;
}


/** 
 * @brief Funcao principal 
 * @param argc Numero de argumentos na linha de comando
 * @param argv Argumentos fornecidos na linha de comando
 */
int main(int argc, char* argv[]) {
	
	/* Verifica se o usuario forneceu argumento de linha de comando
     * corretamente. Em caso negativo, o programa e encerrado */
	if (argc != 2) {
		printf("Execucao incorreta do programa\n");
		printf("Modo de uso: ./anterior <numero inteiro>\n");
		return 0;
	} else {
		int n = atoi(argv[1]);			// Numero fornecido pelo usuario
		if (n <= 1) {
			printf("Nao e possivel determinar numero primo\n");
			return 0;
		} else {
			long int fat = fatorial(n);		// Calculo do fatorial do numero
			long int p = maiorPrimo(fat);	// Determinacao do maior primo

			// Impressao do resultado
			printf("Maior numero primo anterior ao fatorial de %d (%ld) e %ld\n", n, fat, p);
			return 0;
		}
	}
}
