#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

using namespace std;

class Pessoa {
    protected:
        string nome;
        string funcao;

    public:
        //construtores e destrutores
        Pessoa();
        Pessoa(string nome);
        Pessoa(string nome, string funcao);
        ~Pessoa();

        //funções
        void setNome(string nome);
        string getNome();
        void setFuncao(string funcao);
        string setFuncao();
};

#endif