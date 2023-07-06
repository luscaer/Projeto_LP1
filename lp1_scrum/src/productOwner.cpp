#include "../include/productOwner.hpp"
#include "../include/pessoa.hpp"

// Construtores
ProductOwner::ProductOwner() : Pessoa() {}
ProductOwner::ProductOwner(string nome) : Pessoa(nome, "Product Owner") {}

// Destrutor
ProductOwner::~ProductOwner() {}

//Cadastrar ou Deletar tarefa
void ProductOwner::cadastrarTarefa(Backlog b, Tarefa * t)
{
    b.addTarefa(t);
}

void ProductOwner::deletarTarefa(Backlog b, Tarefa * t)
{
    b.deletarTarefa(t);
}