#include "../include/dev.hpp"
#include "../include/pessoa.hpp"

//Construtores
Dev::Dev() {}
Dev::Dev(string nome) : Pessoa(nome) {}
Dev::Dev(string nome, Pessoa * proximo) : Pessoa(nome, proximo) {}

//Destrutor
Dev::~Dev() {}

//Realização de tarefas
void Dev::RealizarTarefas(string status) {}

void Dev::RealizarTarefaEspecifica(string status, int idTarefa) {}