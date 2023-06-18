//#include "pessoa.h"
#include "tarefa.h"

class ProductOwner : public Pessoa {
    public:
        //construtores e destrutores
        ProductOwner();
        ProductOwner(string nome);
        ~ProductOwner();

        void cadastrarTarefa(Tarefa * t);
};