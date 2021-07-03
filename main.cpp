#include <iostream>
#include <locale>
#include "Lista.cpp"
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    Lista alista;
    tCircuito a;
    int q, op;
    string fn;

    cout << "Este programa armazena dados de circuitos em uma lista encadeada." << endl << "Digite 1 para entrar com os dados manualmente," << endl<< "Digite 2 para entrar com os dados de um arquivo," << endl << "Digite qualquer outro valor para sair" << endl;
    cin >> op;
    switch(op){
        case 1 :{
            cout << "Digite quantos elementos existem na lista: ";
            cin >> q;
            for(int b=0; b<q; b++){
                cout << "Digite R1 do elemento " << b << " da lista: ";
                cin >> a.R1;
                cout << "Digite R2 do elemento " << b << " da lista: ";
                cin >> a.R2;
                cout << "Digite V1 do elemento " << b << " da lista: ";
                cin >> a.V1;
                alista.insereNoFim(a);}
            cout << "Digite o nome do arquivo que deseja salvar a lista, com a extenção: ";
            cin >> fn;
            alista.exportarValor(fn);
            main();
            break;}
        case 2 :{
            cout << "Digite o nome do arquivo a ser lido: ";
            cin >> fn;
            ifstream file(fn);
            while(file.eof()==0){
                file >> a.R1 >> a.R2 >> a.V1;
                alista.insereNoFim(a);
            }
            alista.imprimirElementos();
            main();
            break;}
    }
    return 0;
}
