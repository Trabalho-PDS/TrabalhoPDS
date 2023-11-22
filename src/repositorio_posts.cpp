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
#include <unordered_set>
#include <vector>

template <typename T> T openFilePosts(const std::string &filePath, short mode) {
  T file;
  switch (mode) {
  case 1:
    file.open(filePath, std::ios::app);
    break;
  case 2:
    file.open(filePath);
    break;
  }

  return file;
}

std::vector<std::string> splitString(const std::string &input, char delimiter) {
  std::vector<std::string> parts;
  std::stringstream ss(input);
  std::string part;

  while (std::getline(ss, part, delimiter)) {
    parts.push_back(part);
  }

  return parts;
}

void RepositorioPosts::criar_post(std::string const titulo,
                                  std::string const materia,
                                  std::string const descricao,
                                  std::string const nome_usuario,
                                  std::string const id_post,
                                  std::string const id_usuario) {

  std::ofstream FilePosts =
      openFilePosts<std::ofstream>(RepositorioPosts::_filePath, 1);

  if (!FilePosts.is_open()) {
    std::cerr << "Error opening file: " << RepositorioPosts::_filePath << '\n';
    return; // Exit the function if the file couldn't be opened
  }

  FilePosts << id_post + " " + titulo + " " + materia + " " + descricao + " " +
                   nome_usuario + " " + id_post + " " + id_usuario + "\n";

  if (FilePosts.fail()) {
    std::cerr << "Error writing to file: " << _filePath << '\n';
  }

  FilePosts.close();
}

void RepositorioPosts::remover_post(std::string id_post) {
  // armazena o conteúdo do arquivo na memória
  std::ifstream inputFilePosts =
      openFilePosts<std::ifstream>(RepositorioPosts::_filePath, 2);

  if (!inputFilePosts.is_open()) {
    std::cerr << "Erro ao abrir para a ler: " << _filePath << '\n';
    return;
  }

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(inputFilePosts, line)) {
    lines.push_back(line);
  }

  inputFilePosts.close();

  // sobrescrever o arquivo original com o conteúdo atualizado
  std::ofstream outputFilePosts = openFilePosts<std::ofstream>(
      RepositorioPosts::_filePath, 2); // para sobrescrever, precisa do 2

  if (!outputFilePosts.is_open()) {
    std::cerr << "Erro ao abrir o arquivo para escrever\n";
    return;
  }

  // escreve as linhas de volta, excluindo a que tem o ID
  for (const auto &currentLine : lines) {
    // o ID é a primeira parte da linha
    if (currentLine.find(id_post) == std::string::npos) {
      outputFilePosts << currentLine << '\n';
    }
  }

  outputFilePosts.close();
}

void RepositorioPosts::editar_post(
    std::string const id_post, std::map<std::string, std::string> novas_info) {
  remover_post(id_post);
  criar_post(novas_info.find("titulo")->second,
             novas_info.find("materia")->second,
             novas_info.find("descricao")->second,
             novas_info.find("nome_usuario")->second, id_post,
             novas_info.find("id_usuario")->second);
}

void RepositorioPosts::buscar_posts(std::unordered_set<std::string> filtros) {}