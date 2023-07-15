#include <iostream>
#include "../include/dev.hpp"
#include "../include/scrumMaster.hpp"
#include "../include/productOwner.hpp"
#include "../include/backlog.hpp"

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

    Sprint S;

    P.cadastrarDuracaoDaSprint(&S, 21);

    P.cadastrarTarefaSprint(&S, &B, 5);
    P.cadastrarTarefaSprint(&S, &B, 15);
    P.cadastrarTarefaSprint(&S, &B, 20);
    P.cadastrarTarefaSprint(&S, &B, 35);
    P.cadastrarTarefaSprint(&S, &B, 40);

    //Criação dos Devs
    std::string nome;
    std::cout << "Olá Dev, qual o seu nome?" << std::endl;
    std::getline(std::cin, nome);

    Dev x = Dev(nome);

    //Criação do Scrum Master
    ScrumMaster SM = ScrumMaster("Scrum Master");
    
    SM.atribuirTarefaAPessoa(&S, 5, &x);
    SM.atribuirTarefaAPessoa(&S, 15, &x);
    SM.atribuirTarefaAPessoa(&S, 20, &x);
    SM.atribuirTarefaAPessoa(&S, 35, &x);
    SM.atribuirTarefaAPessoa(&S, 40, &x);

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                  Teste 1 - REALIZAÇÕES DE TAREFA               |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    int comando;
    std::cout << "Olá Dev " << x.getNome() << "." << std::endl;
    std::cout << "Escolha o que quer fazer:" << std::endl;
    std::cout << "[1] Atualizar todas as suas tarefas." << std::endl;
    std::cout << "[2] Atualizar tarefa específica." << std::endl;
    std::cin >> comando;

    if(comando == 1){
        std::string comando2;
        std::cout << "Qual o status atual de todas suas tarefas?" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, comando2);

        x.RealizarTarefas(&S, comando2, &x);
    }
    else if(comando == 2){
        int ID;
        char miniComando = 'y';
        std::string comando2;

        while(miniComando == 'y' || miniComando == 'Y'){
            S.gerarRelatorio();
            std::cout << "Deseja atualizar qual tarefa?" << std::endl;
            std::cin >> ID;
            std::cout << "Qual o status atual dessa tarefa?" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, comando2);

            x.RealizarTarefaEspecifica(&S, comando2, ID, &x);
            std::cout << "Deseja atualizar mais uma tarefa? [Y/N]" << std::endl;
            std::cin >> miniComando;
        }
    }
    else{
        std::cout << "Comando não reconhecido.";
    }

    S.gerarRelatorio();

    return 0;
}