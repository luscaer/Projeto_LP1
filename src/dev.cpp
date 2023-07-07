//#include "../include/dev.hpp"
//#include "../include/pessoa.hpp"
#include "dev.hpp"
#include "pessoa.hpp"


//Construtores
Dev::Dev() {}
Dev::Dev(string nome) : Pessoa(nome, "Desenvolvedor") {}

//Destrutor
Dev::~Dev() {}

void Dev::setProximo(Dev* proximo)
{
    this->proximo = proximo;
}

Dev* Dev::getProximo()
{
    return this->proximo;
}

void Dev::setAnterior(Dev* anterior)
{
    this->anterior = anterior;
}

Dev* Dev::getAnterior()
{
    return this->anterior;
}

//Realização de tarefas
void Dev::RealizarTarefas(string status) {}

void Dev::RealizarTarefaEspecifica(string status, int idTarefa) {}