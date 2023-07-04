#ifndef PRODUCTOWNER_HPP
#define PRODUCTOWNER_HPP

#include "tarefa.hpp"

class ProductOwner : public Pessoa {
    public:
        //construtores e destrutores
        ProductOwner();
        ProductOwner(string nome);
        ~ProductOwner();

        void cadastrarTarefa(Tarefa * t);
};

#endif