#include "../include/tarefa.hpp"
#include <iostream>

//status de tarefa, não iniciada, em andamento, em teste, concluida
using namespace std;

Tarefa::Tarefa(){
  this->id = 0;//id começa em 1
  this->PontosDeEsforco = 0; 
  this->instrucoes="";
  this->responsavel= NULL;
  this->status="";
}

Tarefa::Tarefa(string instrucoes){
  this->id = 0;//id começa em 1
  this->PontosDeEsforco = 0; 
  this->instrucoes=instrucoes;
  this->responsavel= NULL;
  this->status="";
}

Tarefa::Tarefa(int id, int PontosDeEsforco, string instrucoes){
  this->id = id;//id começa em 1
  this->PontosDeEsforco = PontosDeEsforco; 
  this->instrucoes=instrucoes;
  this->responsavel= NULL;
  this->status="não iniciada";
}

Tarefa::Tarefa(int id, int PontosDeEsforco, string instrucoes, Dev * responsavel){
  this->id = id;//id começa em 1
  this->PontosDeEsforco = PontosDeEsforco; 
  this->instrucoes=instrucoes;
  this->responsavel= responsavel;
  this->status="não iniciada";
}

Tarefa::Tarefa(int id, int PontosDeEsforco, string instrucoes, Dev * responsavel, string status){
  this->id = id;//id começa em 1
  this->PontosDeEsforco = PontosDeEsforco; 
  this->instrucoes =instrucoes;
  this->responsavel = responsavel;
  this->status = status;
}

Tarefa::~Tarefa() {}

void Tarefa::setProximo(Tarefa * proximo){
  this->proximo = proximo;
}
Tarefa* Tarefa::getProximo(){
  return this->proximo;
}
void Tarefa::setAnterior(Tarefa * anterior){
  this->anterior = anterior;
}
Tarefa* Tarefa::getAnterior(){
  return this->anterior;
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

void Tarefa::imprimirTarefa(){
    if (this == nullptr) {
    cout << "Tarefa inexistente." << endl;
    return;
    }

    cout << "id: " << this->id << endl;
    cout << "Pontos de esforço: " << this->PontosDeEsforco << endl;
    cout << "Status: " << this->status << endl;
    cout << "Instruções: " << this->instrucoes << endl;
    if(this->responsavel != NULL) cout << "Responsavel: " << this->responsavel->getNome() << endl;
    else cout << "Responsavel: NENHUM" << endl;
    cout << "------------------------------------------------------------------" << endl;
}