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

  std::ofstream FilePosts; // arquivo em que serão escritas as novas informações (novo post)

  try {
    FilePosts.open(RepositorioPosts::_filePath, std::ios::app); // std::ios::app - sobrescreve as informações

    FilePosts << post_id + "$&n&$~~" + titulo + "$&n&$~~" + disciplina +
                     "$&n&$~~" + conteudo + "$&n&$~~" + user_id + "\n"; /* eu não poderia separar uma informação da outra por um caracter comum, como ; ou / pq as chances de
    um post ter esses caracteres são muito  grandes, aí decidi colocar essa string aí */
    FilePosts.close();
  } catch (const std::ofstream::failure &e) {
    std::cerr << e.what();
    return;
  }
}

void RepositorioPosts::remover_post(std::string post_id) {
  // armazena o conteúdo do arquivo na memória
  std::ifstream inputFilePosts; // arquivo vai ser aberto para leitura e checaremos também se o post existe ou não
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
  std::ifstream inputFilePosts;// vai abrir para modo de leitura e ver se o id é válido ou não
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

  std::ifstream inputFilePosts; // vai abrir em modo de leitura
  std::vector<std::string> lines;

  try {
    inputFilePosts.open(RepositorioPosts::_filePath);
    std::string line = "";
    while (std::getline(inputFilePosts, line)) {
      if (line.find(filter) != std::string::npos) {
        stack.push(line); // adiciona a linha na stack se ela corresponder com o filtro procurado
      }
    }
    inputFilePosts.close();
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    return posts_filtrados;
  }

  if (stack.empty()) { // não continuar se o filtro não estiver em nenhum post
    throw std::invalid_argument("filtro inválido");
    return posts_filtrados;
  }

  size_t stack_size = stack.size();
  for (size_t i = 0; i < stack_size;
       i++) { // dessa forma, garantimos que os mais recentes sempre estarão no
              // topo
    posts_filtrados.push_back(stack.top());
    stack.pop();
  }
  /* decidi usar a stack, pois os posts mais recentes devem aparecer primeiro. Como a stack segue essa lógica (FILO) fez mais sentido usar ela.
  coloquei as informações no vector depois pois o vector dá uma facilidade maior para achar um índice específico do que a stack */
  return posts_filtrados;
}
