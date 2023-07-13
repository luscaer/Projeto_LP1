#include "dev.hpp"

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
void Dev::RealizarTarefas(Sprint * s, string status, Dev * dev) {
    s->realizarTarefas(dev, status);
}

void Dev::RealizarTarefaEspecifica(Sprint * s, string status, int idTarefa, Dev * dev) {
    Tarefa * t = s->getTarefa(idTarefa);
    
    s->RealizarTarefaEspecifica(dev, status, t);
}