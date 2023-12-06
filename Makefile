# Compiler
CXX := g++
# Flags para o compilador
CXXFLAGS := -std=c++17 -Wall -Wextra -I include

# Diretórios
BIN_DIR := bin
BIN_TESTS_DIR := bin_tests
OBJ_DIR := obj
INCLUDE_DIR := include
SRC_DIR := src
TEST_DIR := tests

# Arquivos fonte
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Arquivos fonte para o código de teste
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)

# Nome do executável
TARGET := $(BIN_DIR)/main.exe

# Nome do executável de testes
TEST_TARGET := $(patsubst $(TEST_DIR)/%.cpp, $(BIN_TESTS_DIR)/%.exe, $(TEST_SRCS))

# Regras de compilação
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_TESTS_DIR)/%.exe: $(TEST_DIR)/%.cpp $(filter-out $(OBJ_DIR)/main.o, $(OBJS))
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# Regras principais
build: $(TARGET) $(TEST_TARGET)

# Essa regra não funciona corretamente, isso foi o mais próximo que cheguei do que deveria ser
test:
	$(foreach var, $(TEST_TARGET), ./$(var);)

#Caso use um navegador diferente, altere a linha abaixo para o mesmo.
run:
	firefox localhost/cgi-bin/forum/login_page.out

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Limpar arquivos intermediários e executáveis
clean:
# Próxima linha: clean para Linux
#	@rm -rf $(OBJ_DIR)/* $(BIN_DIR)/* $(BIN_TESTS_DIR)/* $(OBJ_TEST_DIR)/*
	del $(OBJ_DIR)\* $(BIN_DIR)\* $(BIN_TESTS_DIR)\*

# Fazer clean e build
rebuild: clean build

.PHONY: build test run clean rebuild
