#include<iostream>
int main (){
int i, num, j;
std::cout << "Entre com um valor inteiro: ";
std::cin >> num;
for (i=1; i<num; ++i)
	j=j*i;    
std::cout << "O fatorial de " << num << " eh: " << j << 
std::endl;
return 0;
}

//obs: erro no for e j deve ser inicializado em 1
/*
$ gdb bug
$ run
$ breakpoint 8 (8 é a linha) $ b (número linha)
$ print var (para ver as variaveis)
$ ctrl l (limpa tela)


*/
