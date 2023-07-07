#include "../include/pessoa.hpp"

Pessoa::Pessoa(){
  this->nome = "";
  this->funcao = "";
}

Pessoa::Pessoa(std::string nome){
  this->nome = nome;
  this->funcao = "";
}

Pessoa::Pessoa(string nome, string funcao){
  this->nome = nome;
  this->funcao = funcao;
}

Pessoa::~Pessoa(){}

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