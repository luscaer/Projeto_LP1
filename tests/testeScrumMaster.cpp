#include <iostream>
#include "../include/scrumMaster.hpp"
#include "../include/productOwner.hpp"
#include "../include/backlog.hpp"
#include "../include/dev.hpp"

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
    Dev v = Dev("Nome 1");
    Dev w = Dev("Nome 2");
    Dev x = Dev("Nome 3");
    Dev y = Dev("Nome 4");
    Dev z = Dev("Nome 5");

    //Criação da lista encadeada de devs (Por enquanto não vai servir para nada).

    v.setAnterior(nullptr);
    v.setProximo(&w);
    w.setAnterior(&v);
    w.setProximo(&x);
    x.setAnterior(&w);
    x.setProximo(&y);
    y.setAnterior(&x);
    y.setProximo(&z);
    z.setAnterior(&y);
    z.setProximo(nullptr);

    //Criação do Scrum Master
    std::string nome;
    std::cout << "Digite o nome do Scrum Master: ";
    std::getline(std::cin, nome);

    ScrumMaster SM = ScrumMaster(nome);
    
    std::cout << "Olá " << nome << ". Seja bem vindo ao atribuidor de Tarefas!" << std::endl;

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                 Teste 1 - ATRIBUIR TAREFAS A DEVS              |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    std::cout << "Deseja atribuir uma tarefa? [Y/N]" << std::endl;

    char comando;
    std::cin >> comando;

    if(comando == 'N' || comando == 'n'){
        std::cout << "Ok, tenha um bom dia!" << std::endl;
        return 0;
    }

    Dev * atual = &v;
    int ID;

    while(atual != nullptr){
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "|                           SPRINT ATUAL                         |" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        S.gerarRelatorio();

        std::cout << "Dev Atual: " << atual->getNome() << "." << std::endl;
        std::cout << "Deseja atribuir alguma tarefa ao " << atual->getNome() << "? [Y/N]" << std::endl;
        std::cin >> comando;

        while(comando == 'Y' || comando == 'y'){
            std::cout << "Qual tarefa deseja atribuir? [DIGITE O ID]" << std::endl;
            std::cin >> ID;

            SM.atribuirTarefaAPessoa(&S, ID, atual);

            std::cout << "Deseja atribuir mais alguma tarefa ao " << atual->getNome() << "? [Y/N]" << std::endl;
            std::cin >> comando;
        }

        atual = atual->getProximo();
    }

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                  TAREFAS ATRIBUIDAS COM SUCESSO                |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "|                           SPRINT ATUAL                         |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    S.gerarRelatorio();

    return 0;
}