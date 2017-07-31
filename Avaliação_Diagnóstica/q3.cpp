#include <stdio.h>
#include <stdlib.h>

int somaA(int a, int b){
	++a;
	b++;
	int result = a+ b;
	return result;

}


int somaB(int* a, int b){
	int *x = (int*)malloc(sizeof(int));
	(*x) = (*a);
	(*x) *= 2;
	int result = (*x) +b;
	return result;
}


void somaC(int a, int b, int* result){
	a++;
	(*result) += a+b;

}

int main(int argc, char* argv[]){

	int arg1 = 5;
	int arg2 = 6;

	printf("somaA (%d,%d) = %d\n", arg1, arg2, somaA(arg1, arg2));
	printf("somaB (%d,%d) = %d\n", arg1, arg2, somaB(&arg1, arg2));
	
	int resultado = 0;

	somaC(arg1, arg2, &resultado);
	printf("somaC (%d,%d,resultado) => resultado = %d\n", arg1, arg2, resultado);

	return 0;
}
