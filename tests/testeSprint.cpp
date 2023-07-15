#include <iostream>
#include "../include/productOwner.hpp"
#include "../include/backlog.hpp"
#include "../include/sprint.hpp"

int main() {

    //Criação do Product Owner, Do ProductBackLog e da Sprint
    ProductOwner P = ProductOwner("Product Owner");
    Backlog B;

    Tarefa a = Tarefa(5, 10, "Teste 1", nullptr, "PARA FAZER");
    Tarefa b = Tarefa(10, 20, "Teste 2", nullptr, "PARA FAZER");
    Tarefa c = Tarefa(15, 30, "Teste 3", nullptr, "PARA FAZER");
    Tarefa d = Tarefa(20, 40, "Teste 4", nullptr, "PARA FAZER");
    Tarefa e = Tarefa(25, 50, "Teste 5", nullptr, "PARA FAZER");
    Tarefa f = Tarefa(30, 60, "Teste 6", nullptr, "PARA FAZER");
    Tarefa g = Tarefa(35, 70, "Teste 7", nullptr, "PARA FAZER");
    Tarefa h = Tarefa(40, 80, "Teste 8", nullptr, "PARA FAZER");

    P.cadastrarTarefaBacklog(&B, &a);
    P.cadastrarTarefaBacklog(&B, &b);
    P.cadastrarTarefaBacklog(&B, &c);
    P.cadastrarTarefaBacklog(&B, &d);
    P.cadastrarTarefaBacklog(&B, &e);
    P.cadastrarTarefaBacklog(&B, &f);
    P.cadastrarTarefaBacklog(&B, &g);
    P.cadastrarTarefaBacklog(&B, &h);

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                           BACKLOG ATUAL                         |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    B.consultar();

    Sprint SP;

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|               Teste 1 - CADASTRAR DURAÇÃO DA SPRINT            |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    int duracao;

    std::cout << "Qual a duração da SPRINT?" << std::endl;
    std::cin >> duracao;
    P.cadastrarDuracaoDaSprint(&SP, duracao);

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                         DURAÇÃO CADASTRADA                     |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "DURAÇÃO DA SPRINT: " << SP.getTempoDaSprint() << " DIAS" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                  Teste 2 - INSERIR TAREFAS SPRINT              |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    char comando;
    std::cout << "Deseja inserir uma tarefa na Sprint? [Y/N]" << std::endl;
    std::cin >> comando;
    if(comando == 'N'){
        std::cout << "Ok, tenha um bom dia!" << std::endl;
        return 0;
    }

    Sprint S;
    int ID;

    while(comando == 'Y' || comando == 'y'){
        std::cout << "Qual Tarefa deseja inserir na Sprint? (Informe o ID)" << std::endl;
        std::cin >> ID;

        P.cadastrarTarefaSprint(&S, &B, ID);
        S.gerarRelatorio();
        ID = 0;

        std::cout << "Deseja inserir mais uma tarefa na Sprint? [Y/N]" << std::endl;
        std::cin >> comando;
    }

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                         TAREFAS INSERIDAS                      |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    S.gerarRelatorio();

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                  Teste 4 - REMOVER TAREFAS SPRINT              |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    std::cout << "Deseja remover uma tarefa da Sprint? [Y/N]" << std::endl;
    std::cin >> comando;

    if(comando == 'N'){
        std::cout << "Ok, tenha um bom dia!" << std::endl;
        return 0;
    }

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                          TAREFAS NA SPRINT                     |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    S.gerarRelatorio();

    while(comando == 'Y' || comando == 'y'){
        int id;
        std::cout << "Digite o ID da tarefa" << std::endl;
        std::cin >> id;

        Tarefa * t = S.getTarefa(id);

        if(t == nullptr){
            std::cout << "Não foi possível encontrar a tarefa com o ID fornecido." << std::endl;
        }

        P.deletarTarefaSprint(&S, t);

        std::cout << "Deseja remover mais uma tarefa da Sprint? [Y/N]" << std::endl;
        std::cin >> comando;
    }
    
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                   TAREFAS DELETADA COM SUCESSO                 |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                           SPRINT ATUAL                         |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    S.gerarRelatorio();

    return 0;
}