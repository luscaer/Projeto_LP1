#include "../include/backlog.hpp"
#include <iostream>

Backlog::Backlog(){
  this->cauda = new Tarefa("CAUDA - NÃO DEVE SER ACESSADO");
  this->cabeca = new Tarefa("CABEÇA - NÃO DEVE SER ACESSADO");

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

bool Backlog::addTarefa(Tarefa * t){
  Tarefa * aux = new Tarefa();
  //Lista vazia, inserir após a cabeça.
  if(this->quantidade == 0){
    aux = t;

    aux->setProximo(this->cabeca->getProximo());
    aux->setAnterior(this->cabeca);
    this->cabeca->setProximo(aux);
    this->cauda->setAnterior(aux);

    this->quantidade++;
    return true;
  }
  //Vai adicionar sempre na posição após a cabeça, para depois usar algum método de ordenação.
  else{
    Tarefa * proximo = new Tarefa();
    proximo = t;
    proximo->setAnterior(cabeca);

    aux = this->cabeca->getProximo();
    proximo->setProximo(aux);
    aux->setAnterior(proximo);
    
    this->cabeca->setProximo(proximo);
    this->quantidade++;
    return true;
  }
}

bool Backlog::deletarTarefa(Tarefa * t){
  Tarefa * atual = this->cabeca->getProximo();
  Tarefa * proximo = new Tarefa();
  Tarefa * aux = new Tarefa();
  
  for(int i = 0;i < this->quantidade; i++){
    if(atual == nullptr){
      std::cout << "Tarefa não encontrada" << std::endl;
      return false;
    }
    else if(atual == t){
      atual->getProximo()->setAnterior(atual->getAnterior());
      atual->getAnterior()->setProximo(atual->getProximo());

      delete atual;

      this->quantidade--;
      return true;
    }
    else if(atual != t){
      //caso a tarefa seja o proximo
      if(atual->getProximo() == t){
        aux = atual->getProximo();
        proximo = aux->getProximo();

        atual->setProximo(proximo);
        proximo->setAnterior(atual);
        delete aux;
        
        this->quantidade--;
        return true;
      }
      else{
        atual = atual->getProximo();
      }  
    }
  }

  return false;
}

//mostrar tarefas do backlog
void Backlog::consultar(){
  if (this->quantidade == 0) {
    std::cout << "Backlog vazio." << std::endl;
    return;
  }

  Tarefa * atual = this->cabeca->getProximo();

  while (atual != this->cauda) {
    atual->imprimirTarefa();
    atual = atual->getProximo();
  }
}

//pega uma tarefa atraves do id
Tarefa * Backlog::getTarefa(int id){
  Tarefa * atual = this->cabeca->getProximo();

  if(atual != this->cauda){
    for(int i=0;i<this->quantidade;i++){
      if(atual->getId()==id){
        return atual;
      }
      else{
        atual = atual->getProximo();
      }
    }
  }

  return nullptr;
}