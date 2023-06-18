#include "pessoa.h"
//#include "tarefa.h"
#include <string>

using namespace std;

class Dev : public Pessoa {
    public:
        //construtores e destrutores
        Dev();
        Dev(string nome);
        Dev(string nome, Pessoa * proximo);
        ~Dev();

        //funções
        void RealizarTarefas(string status);
        void RealizarTarefaEspecifica(string status, int idTarefa);
};