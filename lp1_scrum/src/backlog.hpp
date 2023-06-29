#include "../include/backlog.h"
#include <iostream>

Backlog::Backlog(){
  this->cauda = NULL;
  this->cabeca = NULL;
  this->quantidade = 0;
}

Backlog::Backlog(Tarefa * cabeca, Tarefa * cauda, int quantidade){
  this->cauda = cauda;
  this->cabeca = cabeca;
  this->quantidade = 0;
}

Backlog::~Backlog(){}

void Backlog::setCabeca(Tarefa * h){
  this->cabeca = h;
}

Tarefa* Backlog::getCabeca(){
  return this->cabeca;
}

void Backlog::setCauda(Tarefa * t){
  this->cauda = t;  
}

Tarefa* Backlog::getCauda(){
  return this->cauda;  
}

void Backlog::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}

int Backlog::getQuantidade(){
  return this->quantidade;          
}

void Backlog::addTarefa(Tarefa * t){
  Tarefa * aux;
  Tarefa * proximo;
  //lista esta vazia
  if(this->cabeca == NULL){
    this->cabeca = t;
    this->quantidade++;
  }
  //vai add sempre na segunda posição
  else{
    aux = this->cabeca->getProximo();
    proximo = t;
    this->cabeca->setProximo(proximo);
    proximo->setProximo(aux);

    this->quantidade++;
  }
}

void Backlog::deletarTarefa(Tarefa * t){
  Tarefa * atual = this->cabeca;
  Tarefa * proximo;
  Tarefa * aux;
  
  for(int i=0;i<this->quantidade;i++){
    if(atual != t){
      //caso a tarefa seja o proximo
      if(atual->getProximo() == t){
        aux = atual->getProximo();
        proximo = aux->getProximo();

        atual->setProximo(proximo);
        
        this->quantidade--;
        break;
      }
        
      else{
        atual = atual->getProximo();
      }
        
    //caso o atual seja NULL
    }else if(atual == NULL){
      std::cout << "Tarefa não encontrada" << std::endl; break;
      }
    //caso o atual for a cabeça
    else if(atual == cabeca){
        cabeca = atual->getProximo();
        this->quantidade--;
        break;
      }
    }
}

void Backlog::consultar(){
Tarefa * atual = this->cabeca;
    for(int i=0;i<this->quantidade;i++){
      if(atual != NULL){
        atual->imprimirTarefa();
        atual = atual->getProximo(); 
      }
    }
} //mostrar tarefas do backlog
