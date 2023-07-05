#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <string>
#include "dev.hpp"

using namespace std;

class Tarefa {
    private:
        Tarefa * proximo;
        Tarefa * anterior;
        int id;
        int PontosDeEsforco;
        string status;
        string instrucoes;
        Dev * responsavel;

    public:
        //construtores e destrutores
        Tarefa();
        Tarefa(string instrucoes);
        Tarefa(int id, int PontosDeEsforco, string instrucoes);
        Tarefa(int id, int PontosDeEsforco, string instrucoes, Dev * responsavel);
        Tarefa(int id, int PontosDeEsforco, string instrucoes, Dev * responsavel, string status);
        ~Tarefa();

        //funções
        void setProximo(Tarefa * proximo);
        Tarefa* getProximo();
        void setAnterior(Tarefa * proximo);
        Tarefa* getAnterior();
        void setId(int id);
        int getId();
        void setPontosDeEsforco(int PDE); 
        int getPontosDeEsforco();
        void setStatus(string status);
        string getStatus();
        void setInstrucoes(string instrucoes);
        string getInstrucoes();
        void setResponsavel(Dev * responsavel);
        Dev* getResponsavel();
        void imprimirTarefa();
};

#endif