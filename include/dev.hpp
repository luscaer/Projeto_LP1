#ifndef DEV_HPP
#define DEV_HPP

#include "pessoa.hpp"
#include "tarefa.hpp"
#include <string>

using namespace std;

class Dev : public Pessoa {
    protected:
        Dev* proximo;
        Dev* anterior;
        Tarefa* minhaTarefa;

    public:
        //construtores e destrutores
        Dev();
        Dev(string nome);
        ~Dev();

        //funções
        void RealizarTarefas(string status);
        void RealizarTarefaEspecifica(string status, int idTarefa);
};

#endif