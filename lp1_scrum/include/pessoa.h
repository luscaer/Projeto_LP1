#include <string>

using namespace std;

class Pessoa {
    protected:
        Pessoa* proximo;
        string nome;
        string funcao;

    public:
        //construtores e destrutores
        Pessoa();
        Pessoa(string nome, string funcao);
        Pessoa(Pessoa* proximo, string nome, string funcao);
        ~Pessoa();

        //funções
        void setProximo(Pessoa* proximo);
        Pessoa* getProximo();
        void setNome(string nome);
        string getNome();
        void setFuncao(string funcao);
        string setFuncao();
};
