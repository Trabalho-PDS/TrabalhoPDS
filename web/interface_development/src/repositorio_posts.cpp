#include "../include/repositorio_posts.hpp"
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

void RepositorioPosts::criar_post(std::string const titulo,
                                  std::string const disciplina,
                                  std::string const conteudo,
                                  std::string const post_id,
                                  std::string const user_id) {

  std::ofstream FilePosts;

  try {
    FilePosts.open(RepositorioPosts::_filePath, std::ios::app);

    FilePosts << post_id + "$&n&$~~" + titulo + "$&n&$~~" + disciplina +
                     "$&n&$~~" + conteudo + "$&n&$~~" + user_id + "\n";
    FilePosts.close();
  } catch (const std::ofstream::failure &e) {
    std::cerr << e.what();
    return;
  }
}

void RepositorioPosts::remover_post(std::string post_id) {
  // armazena o conteúdo do arquivo na memória
  std::ifstream inputFilePosts;
  bool exists = false;
  std::vector<std::string> lines;

  try {
    inputFilePosts.open(RepositorioPosts::_filePath);
    std::string line = "";
    while (std::getline(inputFilePosts, line)) {
      lines.push_back(line);
      if (line.find(post_id) != std::string::npos) {
        exists = true;
      }
    }
    inputFilePosts.close();
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    return;
  }

  if (!exists) { // não continuar se o post não existir
    throw std::invalid_argument("ID inválido");
    return;
  }

  // sobrescrever o arquivo original com o conteúdo atualizado
  std::ofstream outputFilePosts;

  try {
    outputFilePosts.open(RepositorioPosts::_filePath);
    // escreve as linhas de volta, excluindo a que tem o ID
    for (const auto &currentLine : lines) {
      // o ID é a primeira parte da linha
      if (currentLine.find(post_id) == std::string::npos) {
        outputFilePosts << currentLine << '\n';
      }
    }
    outputFilePosts.close();
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    return;
  }
}

void RepositorioPosts::editar_post(std::string const &titulo,
                                   std::string const &disciplina,
                                   std::string const &conteudo,
                                   std::string const &post_id,
                                   std::string const &user_id) {
  std::ifstream inputFilePosts;
  std::vector<std::string> lines;
  bool exists = false;

  try {
    inputFilePosts.open(RepositorioPosts::_filePath);
    std::string line = "";
    while (std::getline(inputFilePosts, line)) {
      lines.push_back(line);
      if (line.find(post_id) != std::string::npos) {
        exists = true;
      }
    }
    inputFilePosts.close();
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    return;
  }

  if (!exists) { // não continuar se o post não existir
    throw std::invalid_argument("edit - ID inválido " + post_id);
    return;
  }

  // hora de atualizar o arquivo txt:
  std::ofstream outputFilePosts;

  try {
    outputFilePosts.open(RepositorioPosts::_filePath,
                         std::ios::out | std::ios::trunc);
    // modificando os dados da que tem o ID:
    for (const auto &currentLine : lines) {
      // o ID é a primeira parte da linha
      if (currentLine.find(post_id) == std::string::npos) {
        outputFilePosts << currentLine << '\n';
      } else {
        outputFilePosts << post_id + "$&n&$~~" + titulo + "$&n&$~~" +
                               disciplina + "$&n&$~~" + conteudo + "$&n&$~~" +
                               user_id + "\n";
      }
    }
    outputFilePosts.close();
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    return;
  }
}

std::vector<std::string> RepositorioPosts::buscar_posts(std::string filter) {
  // vamos usar um stack para armazenar as informações do arquivo e liberá-lo em
  // um vector.
  std::vector<std::string> posts_filtrados;

  std::stack<std::string> stack;

  std::ifstream inputFilePosts;
  std::vector<std::string> lines;

  try {
    inputFilePosts.open(RepositorioPosts::_filePath);
    std::string line = "";
    while (std::getline(inputFilePosts, line)) {
      if (line.find(filter) != std::string::npos) {
        stack.push(line);
      }
    }
    inputFilePosts.close();
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    posts_filtrados.clear();
    return posts_filtrados;
  }

  if (stack.empty()) { // não continuar se o filtro não estiver em nenhum post
    //throw std::invalid_argument("filtro inválido");
    posts_filtrados.clear();
    return posts_filtrados;
  }

  size_t stack_size = stack.size();
  for (size_t i = 0; i < stack_size;
       i++) { // dessa forma, garantimos que os mais recentes sempre estarão no
              // topo
    posts_filtrados.push_back(stack.top());
    stack.pop();
  }

  return posts_filtrados;
}