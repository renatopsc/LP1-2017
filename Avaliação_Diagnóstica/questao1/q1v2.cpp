#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>     /* strtof */

using namespace std;

struct Aluno{
	string nome;
	string nota;

};

int main(){
	string nomeCompleto;
	string temp;
	int i;
	int numEstudante = 0;
	ifstream arq("entrada.txt");
	Aluno estudante[2];
	if(arq.is_open()){
		while(getline(arq, nomeCompleto)){
			temp = "";
			for(i = 0; i < (int)nomeCompleto.size(); i++){
				if(nomeCompleto[i] != ';'){
					temp = temp + nomeCompleto[i];
				}else{
					break;
				}
			}
				estudante[numEstudante].nome = temp;
				temp = "";
				for(i = i + 1; i < (int)nomeCompleto.size(); i++){
					if(nomeCompleto[i] == ';'){
					
					}else{
						temp = temp + nomeCompleto[i];
					}
					
				}
				estudante[numEstudante].nota = temp;
				numEstudante++;
		}
	}else{
		cout << "Arquivo invalido!" << endl;				
	}
	arq.close();

	cout << "Lendo Registros... " << endl;
	for(i = 0; i < 2; i++){
		cout << "Lendo nome: " << estudante[i].nome << endl;
		cout << "Lendo nota: " << estudante[i].nota << endl;
	}
	cout << "Convertendo..." << endl;
	/*Array para armazenar notas e calcular media*/
	float array[2];
	/* Convertendo para float */
	//float aNumero=strtof((estudante[0].nota).c_str(),0); // string to float
	//float bNumero=strtof((estudante[1].nota).c_str(),0);
	//cout << "A = " << aNumero << " e B = " << bNumero << endl;

	for(i = 0; i < 2; i++){
		array[i] = strtof((estudante[i].nota).c_str(),0);
	}
	float media;
	for(i = 0; i < 2; i++){
		cout << "nota " << i + 1 << " = " << array[i] << endl;
		media = media + array[i];
	}
	media = media / 2;
	cout << "Media das notas dos alunos: " << media << endl;
	return 0;
}
