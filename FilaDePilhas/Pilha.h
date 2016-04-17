/*
 * Pilha.h
 *
 *  Created on: 14 de abr de 2016
 *      Author: wilson
 */

#ifndef PILHA_H_
#define PILHA_H_
#include<iostream>

using namespace std;

class Item{
public:
	string codigo;
	//string nome;
	Item() {}
	Item (string codigo){
		this->codigo = codigo;
		//this->nome = nome;
	}
	void mostra(){
		cout<<codigo<<"  ";
		//cout<<"\nnome:"<<nome<<endl;
	}
};

class No{
public:
	Item item;
	No *prox;
	No(){};
	No(Item item){
		this->item=item;
		prox=NULL;
	};
};


class Pilha {
public:
	No *fundo;
	No *topo;
	Pilha();
	void empilha(Item item);
	void desempilha(Item &item);
	void mostra();
};



class Fila {
public:
	int primeiro;
	int ultimo,tam;
	Pilha *pilhas;
	Fila(int tam);
	void enfileira(Pilha pilha);
	void desenfileirar();
	void mostra();
};





#endif /* PILHA_H_ */
