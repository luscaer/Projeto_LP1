# Variáveis
CXX = g++
CXXFLAGS = -Wall -Wextra
MAINDIR = main
SRCDIR = src
BUILDDIR = build
BINDIR = bin
TESTDIR = tests
DOCDIR = docs

# Alvos
all: $(BINDIR)/meu_programa

# Regra para compilar o programa principal
$(BINDIR)/meu_programa: $(MAINDIR)/main.cpp $(BUILDDIR)/backlog.o $(BUILDDIR)/dev.o $(BUILDDIR)/pessoa.o $(BUILDDIR)/productOwner.o $(BUILDDIR)/scrumMaster.o $(BUILDDIR)/sprint.o $(BUILDDIR)/tarefa.o $(BUILDDIR)/tester.o
	$(CXX) $(CXXFLAGS) -Iinclude -o $@ $^

# Regras para compilar os arquivos de código-fonte
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Regras para compilar os arquivos de teste
$(TESTDIR)/%Test: $(TESTDIR)/%Test.cpp $(BUILDDIR)/%.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $^

# Regra para gerar a documentação usando Doxygen
doc:
	doxygen Doxyfile

# Regra para limpar os arquivos gerados durante a compilação
clean:
	rm -rf $(BINDIR)/*
	rm -rf $(BUILDDIR)/*
	rm -rf $(DOCDIR)/*

# Regra para limpar os arquivos gerados durante a compilação e excluir os executáveis de teste
clean-all: clean
	rm -rf $(TESTDIR)/*Test

# Regra para rodar todos os testes unitários
test: $(BINDIR)/backlogTest $(BINDIR)/devTest $(BINDIR)/pessoaTest $(BINDIR)/productOwnerTest $(BINDIR)/scrumMasterTest $(BINDIR)/sprintTest $(BINDIR)/tarefaTest $(BINDIR)/testerTest
	@for test in $^; do \
		echo "Running $$test..."; \
		./$$test; \
		echo; \
	done
