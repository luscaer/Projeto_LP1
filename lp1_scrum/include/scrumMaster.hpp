#ifndef SCRUMMASTER_HPP
#define SCRUMMASTER_HPP

#include "tarefa.hpp"

class ScrumMaster : public Pessoa {
    public:
        //construtores e destrutores
        ScrumMaster();
        ScrumMaster(string nome);
        ~ScrumMaster();

        //funções
        void atribuirTarefa(Tarefa * t);
        void atribuirTarefaAPessoa(Tarefa * t, Pessoa * p); 
};

#endif