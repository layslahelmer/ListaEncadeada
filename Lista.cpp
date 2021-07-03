#include <iostream>
#include "tCircuito.cpp"
#include <fstream>
#include <string>

using namespace std;

class No{
  public:
  tCircuito valor;
  No* proximo;

  No(tCircuito elemento){
    this->valor=elemento;
    this->proximo=NULL;
  }

  void definirProximo(No* end){proximo=end;}

  tCircuito obterValor(){return valor;}

  No* obterProximo(){return proximo;}
};

class Lista{
  public:
  No* inicio;
  No* fim;

  Lista(){
    inicio = NULL;
    fim = NULL;
  }

  Lista(tCircuito num){
    inicio = new No(num);
    fim = inicio;
  }

  virtual ~Lista(){delete inicio;}
  bool seVazia(){return (inicio == NULL);}

  void imprimirElementos(){
    cout<<"ELEMENTOS DA LISTA"<<endl;
    No* i = inicio;
    tCircuito d;
    if(seVazia()){cout<<"Lista sem elementos!"<<endl;}
    else{
      while(i){
        d = i -> obterValor();
        cout << "R1: " << d.R1 << " | R2: " << d.R2 << " | V1: " << d.V1 << endl;
        i = i->obterProximo();
      }
      cout<<endl;
    }
  }

  void insereNoInicio(tCircuito valor){
    No* novo = new No(valor);

    if(seVazia()){
      inicio= novo;
      fim=novo;
    }
    else{
      novo -> definirProximo(inicio);
      inicio = novo;
    }
  }

  void insereNoFim(tCircuito valor){
    No* novo = new No(valor);

    if(seVazia()){
      inicio = novo;
      fim = novo;
    }
    else{
      fim -> definirProximo(novo);
      fim = novo;
    }
  }

  int tamanhoLista(){
    if(seVazia()){return 0;}
    No* i = inicio;
    int tamanho = 0;

    do{
      i = i->obterProximo();
      tamanho++;
    }while(i);

    return tamanho;
  }

  void exportarValor(string fn){
      No* i = inicio;
      tCircuito d;
      ofstream thefile(fn);
      while(i){
        d = i -> obterValor();
        thefile << endl << d.R1 << " " << d.R2 << " " << d.V1;
        i = i->obterProximo();
      }
      thefile.close();
  }

/*
  bool existeElemento(tCircuito valor){
    No* i = inicio;
    while(i){
      if(i->obterValor()==valor){return true;}
      else{i = i->obterProximo();}
    }
    return false;
  }
*/
  void removerDaLista(){
    if(!seVazia()){
      if(inicio->obterProximo() == NULL){inicio = NULL;}
      else if(inicio->obterProximo()->obterProximo()==NULL){inicio->definirProximo(NULL);}
      else{
        No* anteriorDoAnterior = inicio;
        No* anterior = inicio->obterProximo();
        No* elo = inicio->obterProximo()->obterProximo();

        while(elo){
          No* auxiliar = anterior;
          anterior = elo;
          anteriorDoAnterior = auxiliar;
          elo= elo->obterProximo();
        }

        delete anteriorDoAnterior->obterProximo();
        anteriorDoAnterior->definirProximo(NULL);
        fim=anteriorDoAnterior;
      }
    }
  }
};
