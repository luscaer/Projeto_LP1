#include "../include/scrumMaster.hpp"
#include "../include/pessoa.hpp"

// Construtores
ScrumMaster::ScrumMaster() {}

ScrumMaster::ScrumMaster(string nome) : Pessoa(nome, "Scrum Master") {}

// Destrutor
ScrumMaster::~ScrumMaster() {}

//Atribuições de tarefas
void ScrumMaster::atribuirTarefa(Tarefa * t) {}

void ScrumMaster::atribuirTarefaAPessoa(Tarefa * t, Pessoa * p) {}