#include <iostream>
#include "../include/productOwner.hpp"
#include "../include/backlog.hpp"
#include "../include/sprint.hpp"

int main() {
    //Criação do Product Owner
    std::string nome;

    std::cout << "Digite o nome do Product Owner: ";
    std::getline(std::cin, nome);

    ProductOwner P = ProductOwner(nome);

    std::cout << "Olá " << nome << ". Seja bem vindo ao gerenciador de BackLog!" << std::endl;
    std::cout << "Deseja construir um BackLog? [Y/N]" << std::endl;

    char comando;
    std::cin >> comando;
    if(comando == 'N'){
        std::cout << "Ok, tenha um bom dia!" << std::endl;
        return 0;
    }

    //CRIANDO E INSERINDO  TAREFAS NO BACKLOG
    Backlog b;

    std::cout << "Deseja inserir uma tarefa no BackLog? [Y/N]" << std::endl;
    std::cin >> comando;

    while(comando =='Y'){
        int id, PontosDeEsforco;
        std::string instrucoes, status;

        std::cout << "Digite a ID da tarefa: ";
        std::cin >> id;
        std::cout << "Digite os pontos de prioridade da tarefa: ";
        std::cin >> PontosDeEsforco;
        std::cin.ignore();
        std::cout << "Digite as instruções da tarefa: ";
        std::getline(std::cin, instrucoes);
        std::cout << "Digite o Status da tarefa: ";
        std::getline(std::cin, status);

        Tarefa * t = new Tarefa(id, PontosDeEsforco, instrucoes, nullptr, status);
        //b.addTarefa(t);
        P.cadastrarTarefaBacklog(&b, t);

        std::cout << "Deseja inserir mais uma tarefa no BackLog? [Y/N]" << std::endl;
        std::cin >> comando;
    }

    std::cout << "Teste 1 - CONSULTAR TAREFAS" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    b.consultar();

    std::cout << "Deseja remover uma tarefa do BackLog? [Y/N]" << std::endl;
    std::cin >> comando;

    while(comando == 'Y'){
        int id;
        std::cout << "Digite o ID da tarefa" << std::endl;
        std::cin >> id;

        Tarefa * t = b.getTarefa(id);

        if(t == nullptr){
            std::cout << "Não foi possível encontrar a tarefa com o ID fornecido." << std::endl;
        }

        //b.deletarTarefa(t);
        P.deletarTarefaBacklog(&b, t);

        std::cout << "Deseja remover mais uma tarefa do BackLog? [Y/N]" << std::endl;
        std::cin >> comando;
    }
    
    std::cout << "Teste 2 - DELETAR TAREFAS" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    b.consultar();

    return 0;
}