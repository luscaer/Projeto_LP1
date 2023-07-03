#include <iostream>
#include "../include/productOwner.hpp"
#include "../include/pessoa.hpp"

// Construtores
ProductOwner::ProductOwner() : Pessoa() {}

ProductOwner::ProductOwner(string nome) : Pessoa(nome) {}

// Destrutor
ProductOwner::~ProductOwner() {}

//Cadastrar tarefa
void cadastrarTarefa(Tarefa * t)
{
    //Para fazer
}