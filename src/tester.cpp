#include "../include/tester.hpp"
#include "../include/pessoa.hpp"

#include <iostream>

using namespace std;
//Construtores
Tester::Tester() {}
Tester::Tester(string nome) : Pessoa(nome, "Tester") {}

//Destrutor
Tester::~Tester() {}

//Validar ou Declinar
void Tester::validarTarefas(Tarefa * tarefaParaSerValidada){
    char c;

    tarefaParaSerValidada->imprimirTarefa();
    cout << "VALIDAR OU RETORNAR TAREFA (V = VALIDAR, R = RETORNAR)" << endl;
                                                                       
    cout << "[V/R]:" << endl;
    cin >> c;

    if(c == 'v' || c == 'V'){
        tarefaParaSerValidada->setStatus("CONCLUIDA");
        cout << "Validando tarefa..." << endl;
    }else if(c == 'r' || c == 'R'){
        tarefaParaSerValidada->setStatus("REVISAR");
        cout << "Declinando tarefa..." << endl;
    }else{
        cout << "Escreva uma opção válida!" << endl;
    }
    return;
}