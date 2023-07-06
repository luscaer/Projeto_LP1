#ifndef PRODUCTOWNER_HPP
#define PRODUCTOWNER_HPP

#include "tarefa.hpp"
#include "backlog.hpp"
#include "sprint.hpp"

class ProductOwner : public Pessoa {
    public:
        //construtores e destrutores
        ProductOwner();
        ProductOwner(string nome);
        ~ProductOwner();

        void cadastrarTarefaBacklog(Backlog b, Tarefa * t);
        void deletarTarefaBacklog(Backlog b, Tarefa * t);
        void cadastrarDuracaoDaSprint(Sprint s, int dias);
        void cadastrarTarefaSprint(Sprint s, Backlog b, int id);
        void deletarTarefaSprint(Sprint s, Tarefa * t);
};

#endif