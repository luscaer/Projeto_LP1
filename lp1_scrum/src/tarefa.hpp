#include "../include/tarefa.h"

void Tarefa::setProximo(Tarefa * proximo){
  this->proximo = proximo;
}
Tarefa* Tarefa::getProximo(){
  return this->proximo;
}
void Tarefa::setId(int id){
  this->id = id;
}
int Tarefa::getId(){
  return this->id;
}
void Tarefa::setPontosDeEsforco(int PDE){
  this->PontosDeEsforco = PDE;
}
int Tarefa::getPontosDeEsforco(){
  return this->PontosDeEsforco;
}
void Tarefa::setStatus(string status){
  this->status = status;
}
string Tarefa::getStatus(){
  return this->status;
}
void Tarefa::setInstrucoes(string instrucoes){
  this->instrucoes = instrucoes;
}
string Tarefa::getInstrucoes(){
  return this->instrucoes;
}
void Tarefa::setResponsavel(Dev * responsavel){
  this->responsavel = responsavel;
}
Dev* Tarefa::getResponsavel(){
  return this->responsavel;
}