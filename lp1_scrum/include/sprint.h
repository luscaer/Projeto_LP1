#include "backlog.h"
//#include "dev.h"

class Sprint{
    private:
        Tarefa * cabeca;
        Tarefa * cauda;
        int tempoPassado;//em dias
        int quantidade; //quantidade de tarefas na sprint

    public:
        //construtores e destrutores
        Sprint();
        Sprint(Tarefa * cabeca, Tarefa * cauda);
        ~Sprint();

        //funções
        void setCabeca(Tarefa * h);
        Tarefa* getCabeca();
        void setCauda(Tarefa * t);
        Tarefa* getCauda(); 
        void setTempoPassado(int tempo);
        int getTempoPassado();
        void setQuantidade(int quantidade);
        int getQuantidade();
        void gerarRelatorio(); //gerar relatório pôs ‘n’ tempo passado
        void gerarRelatorioDe(Dev * p);//gerar relatório por desenvolvedor/pessoa (aqui implementa algoritmo de ordenação).
        void addTarefa(Tarefa *t);
        void deletarTarefa(Tarefa *t);
};