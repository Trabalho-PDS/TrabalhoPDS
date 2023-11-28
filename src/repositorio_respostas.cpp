#include "../include/repositorio_respostas.hpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <vector>

void RepositorioRespostas::answer_post(std::string const &post_id,
                                       std::string const &id_monitor,
                                       std::string const &content,
                                       std::string const &answer_id) {

  std::ofstream FileAnswers;

  try {
    FileAnswers.open(RepositorioRespostas::_filePath, std::ios::app);

    FileAnswers << answer_id + "$&n&$~~" + post_id + "$&n&$~~" + id_monitor +
                       "$&n&$~~" + content + "\n";
    FileAnswers.close();
  } catch (const std::ofstream::failure &e) {
    std::cerr << e.what();
    return;
  }
}

void RepositorioRespostas::delete_answer(std::string const &answer_id) {
  // armazena o conteúdo do arquivo na memória
  std::ifstream inputFileAnswers;
  bool exists = false;
  std::vector<std::string> lines;

  try {
    inputFileAnswers.open(RepositorioRespostas::_filePath);
    std::string line = "";
    while (std::getline(inputFileAnswers, line)) {
      lines.push_back(line);
      if (line.find(answer_id) != std::string::npos) {
        exists = true;
      }
    }
    inputFileAnswers.close();
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    return;
  }

  if (!exists) { // não continuar se o post não existir
    throw std::invalid_argument("resposta não existe ou tem id inválido");
    return;
  }

  // sobrescrever o arquivo original com o conteúdo atualizado
  std::ofstream outputFileAnswers;

  try {
    outputFileAnswers.open(RepositorioRespostas::_filePath);
    // escreve as linhas de volta, excluindo a que tem o ID
    for (const auto &currentLine : lines) {
      // o ID é a primeira parte da linha
      if (currentLine.find(answer_id) == std::string::npos) {
        outputFileAnswers << currentLine << '\n';
      }
    }
    outputFileAnswers.close();
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    return;
  }
}

std::vector<std::string>
RepositorioRespostas::answers_by_post_id(std::string const &post_id) {
  // vamos usar um stack para armazenar as informações do arquivo e liberá-lo em
  // um vector.
  std::vector<std::string> respostas_filtradas;

  std::stack<std::string> stack;

  std::ifstream inputFileAnswers;
  std::vector<std::string> lines;

  try {
    inputFileAnswers.open(RepositorioRespostas::_filePath);
    std::string line = "";
    while (std::getline(inputFileAnswers, line)) {
      if (line.find(post_id) != std::string::npos) {
        stack.push(line);
      }
    }
    inputFileAnswers.close();
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    return respostas_filtradas;
  }

  if (stack.empty()) { // não continuar se o filtro não estiver em nenhum post
    throw std::invalid_argument("post inválido");
    return respostas_filtradas;
  }

  size_t stack_size = stack.size();
  for (size_t i = 0; i < stack_size;
       i++) { // dessa forma, garantimos que os mais recentes sempre estarão no
              // topo
    respostas_filtradas.push_back(stack.top());
    stack.pop();
  }

  return respostas_filtradas;
}