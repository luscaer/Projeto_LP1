//#include "pessoa.h"
#include "tarefa.h"

class ScrumMaster : public Pessoa {
    public:
        //construtores e destrutores
        ScrumMaster();
        ScrumMaster(string nome);
        ~ScrumMaster();

        //funções
        void atribuirTarefa(Tarefa * t);
        void atribuirTarefaAPessoa(Tarefa * t); 
};