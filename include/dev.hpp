#ifndef DEV_HPP
#define DEV_HPP

#include "pessoa.hpp"
//#include "tarefa.hpp"
#include <string>

using namespace std;

class Dev : public Pessoa {
    protected:
        Dev* proximo;
        Dev* anterior;
        //Tarefa* minhaTarefa;

    public:
        //construtores e destrutores
        Dev();
        Dev(string nome);
        ~Dev();

        //funções
        void setProximo(Dev* proximo);
        Dev* getProximo();
        void setAnterior(Dev* anterior);
        Dev* getAnterior();
        void imprimirDev();

        //void RealizarTarefas(string status, int idTarefa);
        //void RealizarTarefas(string status, int idTarefa, Sprint * s);

};

#endif