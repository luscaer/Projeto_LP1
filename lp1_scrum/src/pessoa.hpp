#include "../include/pessoa.h"

Pessoa::Pessoa(){
  this->nome = "";
  this->funcao = "";
  this->proximo = NULL;
}

Pessoa::Pessoa(string nome, string funcao){
  this->nome = nome;
  this->funcao = funcao;
  this->proximo = NULL; 
}

Pessoa::Pessoa(Pessoa *proximo, string nome, string funcao){
  this->nome = nome;
  this->funcao = funcao;
  this->proximo = proximo; 
}

Pessoa::~Pessoa(){}


void Pessoa::setProximo(Pessoa* proximo){
  this->proximo = proximo;
}

Pessoa* Pessoa::getProximo(){
  return this->proximo;
}

void Pessoa::setNome(string nome){
  this->nome = nome;
}

string Pessoa::getNome(){
  return this->nome;
}

void Pessoa::setFuncao(string funcao){
  this->funcao = funcao;
}

string Pessoa::setFuncao(){
  return this->funcao;
}