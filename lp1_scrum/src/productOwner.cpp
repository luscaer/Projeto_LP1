#include <iostream>
#include "../include/productOwner.h"
#include "../include/pessoa.h"

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