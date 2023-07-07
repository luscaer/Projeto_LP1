#include "../include/scrumMaster.hpp"
#include "../include/pessoa.hpp"

// Construtores
ScrumMaster::ScrumMaster() {}
ScrumMaster::ScrumMaster(string nome) : Pessoa(nome, "Scrum Master") {}

// Destrutor
ScrumMaster::~ScrumMaster() {}

//Atribuições de tarefas

void ScrumMaster::atribuirTarefaAPessoa(Sprint * s, int id, Dev * p)
{
    Tarefa * aux = s->getTarefa(id);
    aux->setResponsavel(p);
}