//#include "pessoa.h"
//#include "dev.h"
#include "tarefa.hpp"

class Tester : public Pessoa {
    public:
        //construtores e destrutores
        Tester();
        Tester(string nome);
        Tester(string nome, Pessoa * proximo);
        ~Tester();

        //funções
        void validarTarefasDe(Dev * p);
        void declinarTarefasDe(Dev * p);
        void validarTarefa(Tarefa * t);
        void declinarTarefa(Tarefa * t);
};