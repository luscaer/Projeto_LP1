#include "../include/dev.hpp"
#include "../include/pessoa.hpp"

//Construtores
Dev::Dev() {}
Dev::Dev(string nome) : Pessoa(nome, "Desenvolvedor") {}

//Destrutor
Dev::~Dev() {}

//Realização de tarefas
void Dev::RealizarTarefas(string status) {}

void Dev::RealizarTarefaEspecifica(string status, int idTarefa) {}