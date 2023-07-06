#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

using namespace std;

class Pessoa {
    protected:
        Pessoa* proximo;
        Pessoa* anterior;
        string nome;
        string funcao;

    public:
        //construtores e destrutores
        Pessoa();
        Pessoa(string nome);
        Pessoa(string nome, string funcao);
        Pessoa(string nome, Pessoa* proximo);
        Pessoa(string nome, string funcao, Pessoa* proximo);
        ~Pessoa();

        //funções
        void setProximo(Pessoa* proximo);
        Pessoa* getProximo();
        void setAnterior(Pessoa* anterior);
        Pessoa* getAnterior();
        void setNome(string nome);
        string getNome();
        void setFuncao(string funcao);
        string setFuncao();
};

#endif