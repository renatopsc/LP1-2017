#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct aluno{
	string nome;
	float nota;

};

int main(){
	string linha;	
	string temp;
	ifstream arq("entrada.txt");
	aluno estudante[2];
	int i;
	int numEstudante = 0;
	if(arq.is_open()){
	}else {
		cout << "Arquivo invalido!";
	}
	temp = "";
	int ponto = 1;
	int cont = 0;
	while(!arq.eof()){

		getline(arq, linha);

		for(i = 0; i < (int)linha.size(); i++){
			if(linha[i] != ';'){
				temp = temp + linha[i];


			}else {
				if (cont == 1){
cout <<"nota :"<< temp << endl;
					estudante[numEstudante].nota = atof(temp);
					temp ="";
					cont = 0;
					break;
				}
				cont++;
				estudante[numEstudante].nome = temp;
				temp = "";
			} 
		}
	}

		
		temp = "";
		for(i = i +1; i < (int)linha.size(); i++){ //inicialização i = i +1 ponha isso: for(; i < nomeCompleto.size(); i++)
			temp = temp + linha[i];
		}
	
		//cout << "temp = "<<temp << endl;
		float r = 5;//atof(temp);
		estudante[numEstudante].nota = r;
		numEstudante++;


	
		
	arq.close();

	for(i = 0; i < 2; i++){
	cout << "Nome: " << estudante[i].nome << endl;
	cout << "Nota: " << estudante[i].nota << endl;
	}


	return 0;
}
