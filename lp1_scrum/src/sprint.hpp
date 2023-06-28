#include "../include/sprint.h"

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
int Sprint::gerarRelatorio(int tempo){
  
} //gerar relatório pôs ‘n’ tempo passado

int Sprint::gerarRelatorioDe(Dev * p){
  
}//gerar relatório por desenvolvedor/pessoa (aqui implementa algoritmo de ordenação).