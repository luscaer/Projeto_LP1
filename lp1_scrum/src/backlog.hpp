#include "../include/backlog.h"

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
          
}

void Backlog::deletarTarefa(Tarefa * t){
          
}

Tarefa* Backlog::consultar(){
        
} //mostrar tarefas do backlog
