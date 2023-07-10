#include "../include/productOwner.hpp"
#include "../include/pessoa.hpp"

// Construtores
ProductOwner::ProductOwner() : Pessoa("", "Product Owner") {}
ProductOwner::ProductOwner(string nome) : Pessoa(nome, "Product Owner") {}

// Destrutor
ProductOwner::~ProductOwner() {}

//Cadastrar ou Deletar tarefa
void ProductOwner::cadastrarTarefaBacklog(Backlog * b, Tarefa * t)
{
    b->addTarefa(t);
}

void ProductOwner::deletarTarefaBacklog(Backlog * b, Tarefa * t)
{
    b->deletarTarefa(t);
}

void ProductOwner::cadastrarDuracaoDaSprint(Sprint s, int dias)
{
    s.setTempoDaSprint(dias);
}

void ProductOwner::cadastrarTarefaSprint(Sprint * s, Backlog * b, int id)
{
    s->addTarefa(b, id);
}

void ProductOwner::deletarTarefaSprint(Sprint * s, Tarefa * t)
{
    s->deletarTarefa(t);
}