#include "../include/dev.hpp"
#include "../include/sprint.hpp"

//#include "../include/pessoa.hpp"
//#include "dev.hpp"
//#include "pessoa.hpp"
#include <iostream>


//Construtores
Dev::Dev() : Pessoa ("", "Desenvolvedor") {}
Dev::Dev(string nome) : Pessoa(nome, "Desenvolvedor") {}

//Destrutor
Dev::~Dev() {}

void Dev::setProximo(Dev* proximo)
{
    this->proximo = proximo;
}

Dev* Dev::getProximo()
{
    return this->proximo;
}

void Dev::setAnterior(Dev* anterior)
{
    this->anterior = anterior;
}

Dev* Dev::getAnterior()
{
    return this->anterior;
}

void Dev::imprimirDev(){
    if (this == nullptr) {
    std::cout << "Desenvolvedor inexistente." << endl;
    return;
    }

    std::cout << "Nome: " << this->nome << endl;
    std::cout << "Função: Desenvolvedor" << std::endl;
    cout << "--------------------------------------" << endl;
}

//Realização de tarefas, so vai a ver uma tarefa por vez
// void Dev::RealizarTarefas(string status, int idTarefa, Sprint * s) {
//     Tarefa * tEscolhida = s->getCabeca();

//     for(int i = 0; i<s->getQuantidade(); i++){
//         if(tEscolhida != NULL){
//             if(tEscolhida->getId() == idTarefa){
//                 tEscolhida->setStatus(status);
//                 break;
//             }else{
//                 tEscolhida = tEscolhida->getProximo();
//             }
//         }
        
//     }
// }

