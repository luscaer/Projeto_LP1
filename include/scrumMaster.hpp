#ifndef SCRUMMASTER_HPP
#define SCRUMMASTER_HPP

#include "tarefa.hpp"
#include "sprint.hpp"

class ScrumMaster : public Pessoa {
    public:
        //construtores e destrutores
        ScrumMaster();
        ScrumMaster(string nome);
        ~ScrumMaster();

        //funções
        void atribuirTarefaAPessoa(Sprint * s, int id, Pessoa * p); 
};

#endif