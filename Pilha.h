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
	int indicePilha;
	bool finalizado;
	No(){};
	No(Item item){
		finalizado=false;
		this->item=item;
		prox=NULL;
	};
	void setIndice(int indicePilha) {
		this->indicePilha = indicePilha;
	}
	int getIndice() {
			return indicePilha;
	}

	bool isFinalizado() const {
		return finalizado;
	}

	void setFinalizado(bool finalizado) {
		this->finalizado = finalizado;
	}

	const Item& getItem() const {
		return item;
	}

	void setItem(const Item& item) {
		this->item = item;
	}
};


class Pilha {
public:
	No *fundo;
	No *topo;
	int indice;
	int tam;
	string estado;

	Pilha();
	void empilha(Item item);
	void desempilha(Item &item);
	void mostra();
	bool busca(Item item);
	void setIndice(int indice) {
		this->indice = indice;
	}

	void setEstado(string estado) {
			this->estado = estado;
	}

	string getEstado() {
			return estado;
	}
	void calculaTam(){
		int tamanho=0;
		No *aux;
		aux=topo->prox;
		while(aux!=NULL)
		{
			tamanho++;
			aux=aux->prox;
		}
		this->tam=tamanho;
	}

	int getTam() {
		calculaTam();
		return tam;
	}
<<<<<<< HEAD


=======


>>>>>>> 8ee02e857d8525f9933e1f955f0ef04010eb560c
};

class Controle {
public:

<<<<<<< HEAD
	int primeiro,origem,destino,*temporario;
	int ultimo,tam,ultimaPosicaoValida;
=======
	int origem,destino,*temporario;
	int tam,ultimaPosicaoValida,numeroDeMovimentos;
>>>>>>> 8ee02e857d8525f9933e1f955f0ef04010eb560c
	Pilha *pilhas;
	Controle(int tam);
	void aloca(Pilha pilha);
	void mostra();
	int busca(Item item);

	void setDestino(int destino) {
			this->destino = destino;
	}

	int getDestino(){
		return destino;
	}

	void setOrigem(int origem) {
				this->origem = origem;
	}

	int getOrigem(){
		return origem;
	}


	void classifica(Item item,int destino){

<<<<<<< HEAD

		int indiceDaPilha;
		bool achou;

		for(indiceDaPilha=0;indiceDaPilha<=ultimaPosicaoValida;indiceDaPilha++){
			achou=pilhas[indiceDaPilha].busca(item);
			if(achou)//se achou
			{

				// classifica a origen e o destino
				pilhas[destino].setEstado("d");
				this->destino=destino;
				if(destino==indiceDaPilha)
				{
					pilhas[indiceDaPilha].setEstado("od");
					this->origem=destino;
				}else{
					pilhas[indiceDaPilha].setEstado("o");
					this->origem=indiceDaPilha;
				}

			}
		}
		// classifica os temporarios
		string aux="o";
		int j=0;
		for(int i=0;i<ultimaPosicaoValida;i++)
		{

			aux=pilhas[i].getEstado();
			if(aux!="o" && aux!="d" && aux!="od")
			{
					cout<<aux<<endl;
					cout<<i<<endl;
					this->temporario[j]=i;
					j++;
			}
=======
		this->destino=destino;
		int indiceDaPilha;
		bool achou;

		for(indiceDaPilha=0;indiceDaPilha<=ultimaPosicaoValida;indiceDaPilha++)
		{
			achou=pilhas[indiceDaPilha].busca(item);
			if(achou)//se achou
			{
					this->origem=indiceDaPilha;
			}
		}

		//delimitador fim do vetor temporario

		for(int t=0;t<tam;t++)
		{
					this->temporario[t]=-1;
		}

		// classifica os temporarios
		int j=0;
		for(int i=0;i<ultimaPosicaoValida;i++)
		{
				if(i!=this->origem && i!=this->destino)
				{
					this->temporario[j]=i;
					j++;
				}
>>>>>>> 8ee02e857d8525f9933e1f955f0ef04010eb560c
		}
		//delimitador fim do vetor temporario
		temporario[j]=-1;



		if(!achou){
			cout<<"nao encontrado\n";
		}
	}

	void TrocaDePilha(int origem,int destino,Item item){
<<<<<<< HEAD

				pilhas[origem].desempilha(item);
				cout<<"\nmovendo o item ";
				item.mostra();
				pilhas[destino].empilha(item);
	}
	void mostraT(){

		int i=0;
				while(temporario[i]!=-1){
					cout<<"\n valor do temporario "<<temporario[i]<<endl;
						i++;
				}
	}

	int melhorTemporario(){
		int i=0,tamDaMenorPilha=1000,tamAtual=0,melhorIndice;//vou guardar o menor contador possivel

		while(temporario[i]!=-1){
			tamAtual=pilhas[temporario[i]].getTam();
				  if(tamDaMenorPilha>tamAtual){
					  tamDaMenorPilha=tamAtual;
					  melhorIndice=temporario[i];
				  }
				i++;
		}
		return melhorIndice;
=======
				pilhas[origem].desempilha(item);
				cout<<"\nmovendo o item ";
				item.mostra();
				cout<<"da pilha "<<origem<<" para a pilha "<<destino<<endl;
				pilhas[destino].empilha(item);
				this->numeroDeMovimentos++;
>>>>>>> 8ee02e857d8525f9933e1f955f0ef04010eb560c
	}
	void mostraT(){

<<<<<<< HEAD
	void move(Item item, int origem,int destino,int temp){
		if(pilhas[this->destino].topo->item.codigo==item.codigo)
		{//se topo do destino tiver o item
			cout<<"fim da ordenacao"<<endl;//pilha de origem for == a item
		}else{
			//calcula o melhor temporario posivel
			temp=melhorTemporario();
=======
		int i=0;
				while(temporario[i]!=-1){
					cout<<"\n valor do temporario "<<temporario[i]<<endl;
						i++;
				}
	}

	int piorTemporario(){
		int i=0,tamDaMaiorPilha=0,tamAtual=0,piorIndice=this->temporario[0];
				//vou guardar o maior contador possivel

				while(this->temporario[i]!=-1){
					tamAtual=pilhas[this->temporario[i]].getTam();
					//cout<<pilhas[this->temporario[i]].getTam()<<endl;
						if(tamDaMaiorPilha<tamAtual){
							  tamDaMaiorPilha=tamAtual;
							  piorIndice=this->temporario[i];
						  }
						i++;
				}
				return piorIndice;

	}
	int melhorTemporario(){
		int i=0,tamDaMenorPilha=1000,tamAtual=0,melhorIndice=this->temporario[0];
		//vou guardar o menor contador possivel
//o temp estiva vazio ele retorna -1
		while(this->temporario[i]!=-1){
			tamAtual=pilhas[this->temporario[i]].getTam();
			//cout<<pilhas[this->temporario[i]].getTam()<<endl;
				if(tamDaMenorPilha>tamAtual){
					  tamDaMenorPilha=tamAtual;
					  melhorIndice=this->temporario[i];
				  }
				i++;
		}
		return melhorIndice;
	}
>>>>>>> 8ee02e857d8525f9933e1f955f0ef04010eb560c

	void move(Item item, int origem,int destino,int temp)
	{
		//calcula o melhor temporario posivel
		temp=melhorTemporario();

<<<<<<< HEAD
				TrocaDePilha(destino,temp,item);
				cout<<"da pilha "<<destino<<" para a pilha "<<temp<<endl;
=======
		if(this->origem==this->destino && pilhas[this->origem].topo->prox->item.codigo==item.codigo)
		{
			temp=piorTemporario();
			TrocaDePilha(origem,temp,item);
			this->origem=temp;
			classifica(item,this->destino);
			temp=melhorTemporario();
			move(item,this->origem,this->destino,temp);
		}else{
			//limpa a pilha origem
			if(pilhas[this->origem].topo->prox->item.codigo!=item.codigo)
			{
				TrocaDePilha(origem,temp,item);
>>>>>>> 8ee02e857d8525f9933e1f955f0ef04010eb560c
				move(item,origem,destino,temp);

			}else{
				//TERMINA O PROCESSAMENTO caso que finalza a recursividade
				if(pilhas[this->destino].topo->prox==NULL || pilhas[this->destino].topo->prox->isFinalizado())
				{

					TrocaDePilha(origem,destino,item);
					//marcando o no como finalizado
					pilhas[this->destino].topo->prox->setFinalizado(true);
					pilhas[this->destino].topo->prox->item.mostra();
				}else{
<<<<<<< HEAD

					TrocaDePilha(origem,temp,item);
					cout<<"da pilha "<<origem<<" para a pilha "<<temp<<endl;
					move(item,origem,destino,temp);
				}
=======
					//limpa o destino
>>>>>>> 8ee02e857d8525f9933e1f955f0ef04010eb560c

					TrocaDePilha(destino,temp,item);
					move(item,origem,destino,temp);
				}
			}
		}

	}




	void organiza(Item &item){
<<<<<<< HEAD

		move(item,this->origem,this->destino,this->temporario[0]);

=======
		move(item,this->origem,this->destino,this->temporario[0]);
>>>>>>> 8ee02e857d8525f9933e1f955f0ef04010eb560c
	}

};



#endif /* PILHA_H_ */
