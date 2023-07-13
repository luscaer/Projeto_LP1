#ifndef TESTER_HPP
#define TESTER_HPP

#include "tarefa.hpp"

class Tester : public Pessoa {
    public:
        //construtores e destrutores
        Tester();
        Tester(string nome);
        Tester(string nome, Pessoa * proximo);
        ~Tester();

        //funções
        void validarTarefasDe(Pessoa * p);
        void declinarTarefasDe(Pessoa * p);
};

#endif