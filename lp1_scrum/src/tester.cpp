#include "../include/tester.hpp"
#include "../include/pessoa.hpp"

//Construtores
Tester::Tester() {}
Tester::Tester(string nome) : Pessoa(nome) {}
Tester::Tester(string nome, Pessoa * proximo) : Pessoa(nome, proximo) {}

//Destrutor
Tester::~Tester() {}

//Validar ou Declinar
void Tester::validarTarefasDe(Dev * p){
  
}
void Tester::declinarTarefasDe(Dev * p){
  
}
void Tester::validarTarefa(Tarefa * t){
  
}

void Tester::declinarTarefa(Tarefa * t){
  
}