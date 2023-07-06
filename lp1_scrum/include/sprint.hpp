#ifndef SPRINT_HPP
#define SPRINT_HPP

#include "tarefa.hpp"
#include "backlog.hpp"

class Sprint{
    private:
        Tarefa * cabeca;
        Tarefa * cauda;
        int tempoDaSprint; //Em dias.
        int quantidade; //Quantidade de tarefas na sprint.

    public:
        //construtores e destrutores
        Sprint();
        ~Sprint();

        //funções
        void setTempoPassado(int tempo);
        int getTempoPassado();
        void setQuantidade(int quantidade);
        int getQuantidade();
        void gerarRelatorio(); //Gerar relatório pôs ‘n’ tempo passado
        void gerarRelatorioDeDev(Dev * p); //Gerar relatório do desenvolvedor/pessoa.
        bool addTarefa(Backlog b, int id); //Recebe um backlog com as tarefas definidas pelo Product Owner e o ID da tarefa que será adicionada na sprint.
        bool deletarTarefa(Tarefa *t);
        //bool ordenarAlfabetico();
        //bool ordenarPorPrioridade();
};

#endif