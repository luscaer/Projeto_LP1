#include "../include/sprint.hpp"
#include <iostream>

Sprint::Sprint(){
  this->cabeca = NULL;
  this->cauda = NULL;
  this->tempoPassado=0;//tempo passado em dias
  this->quantidade=0;//quantidade de tarefas na sprint
}

Sprint::Sprint(Tarefa * cabeca, Tarefa * cauda){
  this->cabeca = cabeca;
  this->cauda = cauda;
  this->tempoPassado=0;//tempo passado em dias
  this->quantidade=0;//quantidade de tarefas na sprint
}

Sprint::~Sprint(){}

void Sprint::setCabeca(Tarefa * h){
  this->cabeca = h;
}
Tarefa* Sprint::getCabeca(){
  return this->cabeca;
}
void Sprint::setCauda(Tarefa * t){
  this-> cauda = t;
}
Tarefa* Sprint::getCauda(){
  return this->cauda;
}
void Sprint::setTempoPassado(int tempo){
  this->tempoPassado=tempo;
}
int Sprint::getTempoPassado(){
  return tempoPassado;
}
void Sprint::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}
int Sprint::getQuantidade(){
  return this->quantidade;
}



//gerar relatório pôs ‘n’ tempo passado
void Sprint::gerarRelatorio(){
  Tarefa * atual = this->cabeca;
    for(int i=0;i<this->quantidade;i++){
      if(atual != NULL){
        atual->imprimirTarefa();
        atual = atual->getProximo(); 
      }
    }
}

void Sprint::gerarRelatorioDe(Dev * p){
  
}//gerar relatório por desenvolvedor/pessoa (aqui implementa algoritmo de ordenação).


//SPRINT SO ADICIONA TAREFA DO BACKLOG AJUSTAR ISSO NA MAIN
void Sprint::addTarefa(Tarefa * t){
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


void Sprint::deletarTarefa(Tarefa * t){
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

