#include "../include/scrumMaster.hpp"
#include "../include/pessoa.hpp"

// Construtores
ScrumMaster::ScrumMaster() : Pessoa ("", "Scrum Master"){}
ScrumMaster::ScrumMaster(string nome) : Pessoa(nome, "Scrum Master") {}

// Destrutor
ScrumMaster::~ScrumMaster() {}

//Atribuições de tarefas

void ScrumMaster::atribuirTarefaAPessoa(Sprint * s, int id, Dev * p)
{
    Tarefa * aux = s->getTarefa(id);
    aux->setResponsavel(p);
}

void ScrumMaster::atribuirTarefa(Dev * d, Tarefa * t){
    t->setResponsavel(d);
}