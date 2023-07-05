# Configurações do compilador
CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11

# Diretórios
BIN_DIR = bin
BUILD_DIR = build
CODE_DIR = codigos_auxiliares
DATA_DIR = data
DOCS_DIR = docs
INCLUDE_DIR = include
MAIN_DIR = main
SRC_DIR = src
TEST_DIR = tests

# Arquivos fonte e objeto
MAIN_SRC = $(MAIN_DIR)/main.cpp
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Nome do executável
EXECUTABLE = $(BIN_DIR)/lp1_scrum

# Comandos
RM = rm -rf

# Regra padrão
all: $(EXECUTABLE)

# Regra para o executável
$(EXECUTABLE): $(OBJ_FILES) $(MAIN_SRC)
	$(CC) $(CFLAGS) $^ -o $@

# Regra para os objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regras para os testes
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_EXECS = $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/%,$(TEST_FILES))

$(BIN_DIR)/%: $(TEST_DIR)/%.cpp $(OBJ_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ -o $@

tests: $(TEST_EXECS)

# Regra para limpar os arquivos gerados
clean:
	$(RM) $(BIN_DIR) $(BUILD_DIR)

.PHONY: all tests clean