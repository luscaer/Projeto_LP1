#ifndef PRODUCTOWNER_HPP
#define PRODUCTOWNER_HPP

#include "tarefa.hpp"
#include "backlog.hpp"

class ProductOwner : public Pessoa {
    public:
        //construtores e destrutores
        ProductOwner();
        ProductOwner(string nome);
        ~ProductOwner();

        void cadastrarTarefa(Backlog b, Tarefa * t);
        void deletarTarefa(Backlog b, Tarefa * t);
};

#endif