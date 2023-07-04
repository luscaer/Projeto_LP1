#include "../include/backlog.hpp"
#include <iostream>

Backlog::Backlog(){
  this->cauda = new Tarefa();
  this->cabeca = new Tarefa();

  this->cabeca->setProximo(cauda);
  this->cabeca->setAnterior(nullptr);

  this->cauda->setProximo(nullptr);
  this->cauda->setAnterior(cabeca);

  this->quantidade = 0;
}

Backlog::~Backlog(){
  Tarefa* aux = this->cabeca;

  while(aux != nullptr)
  {
    Tarefa* proximo = aux->getProximo();
    delete aux;
    aux = proximo;
  }
}

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
  //lista esta vazia
  if(this->cabeca == nullptr){
    aux = t;

    aux->setProximo(cabeca->getProximo());
    aux->setAnterior(cabeca->getAnterior());

    this->cabeca = aux;
    this->quantidade++;
  }
  //vai add sempre na segunda posição
  else{
    Tarefa * proximo;
    proximo = t;
    proximo->setAnterior(cabeca);

    aux = this->cabeca->getProximo();
    proximo->setProximo(aux);
    aux->setAnterior(proximo);
    
    this->cabeca->setProximo(proximo);
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

//pega uma tarefa atraves do id
Tarefa * Backlog::getTarefa(int id){
  
Tarefa * atual = this->cabeca;

  if(atual != NULL){
    for(int i=0;i<this->quantidade;i++){
      if(atual->getId()==id){
        return atual; break;
      }
      else{
        atual = atual->getProximo();
      }
    }
  }else{
    return NULL;
  }
}