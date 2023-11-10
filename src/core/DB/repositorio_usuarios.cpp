#include "repositorio_usuarios.hpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

template <typename T> T openFileUsers(const std::string &filePath, short mode) {
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

std::string generate_id_usuario() {
  static const char alphanum[] = "0123456789"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "abcdefghijklmnopqrstuvwxyz";
  std::string id_usuario;
  id_usuario.reserve(16);

  std::srand(
      std::time(0)); // Seed the random number generator with the current time

  for (int i = 0; i < 16; ++i) {
    id_usuario += alphanum[std::rand() % (sizeof(alphanum) - 1)];
  }
  return id_usuario;
}

void RepositorioUsuarios::criar_usuario(const std::string email,
                                        const std::string senha,
                                        const std::string tipo,
                                        std::string id_usuario) {
  std::cout << "Current working directory: " << RepositorioUsuarios::currentPath
            << std::endl;
  std::cout << "Attempting to open file: " << RepositorioUsuarios::filePath
            << std::endl;

  std::ofstream FileUsers =
      openFileUsers<std::ofstream>(RepositorioUsuarios::filePath, 1);

  if (!FileUsers.is_open()) {
    std::cerr << "Error opening file: " << filePath << '\n';
    return; // Exit the function if the file couldn't be opened
  }

  if (id_usuario == "default") {
    id_usuario = generate_id_usuario();
  }

  FileUsers << id_usuario + " " + email + " " + senha + " " + tipo + " &n8**" +
                   "\n";

  std::cerr << "written" << std::endl;
  if (FileUsers.fail()) {
    std::cerr << "Error writing to file: " << filePath << '\n';
  }

  FileUsers.close();
}

void RepositorioUsuarios::remover_usuario(std::string id_usuario) {
  // armazena o conteúdo do arquivo na memória
  std::ifstream inputFileUsers =
      openFileUsers<std::ifstream>(RepositorioUsuarios::filePath, 2);

  if (!inputFileUsers.is_open()) {
    std::cerr << "Erro ao abrir para a ler: " << filePath << '\n';
    return;
  }

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(inputFileUsers, line)) {
    lines.push_back(line);
  }

  inputFileUsers.close();

  // sobrescrever o arquivo original com o conteúdo atualizado
  std::ofstream outputFileUsers = openFileUsers<std::ofstream>(
      RepositorioUsuarios::filePath, 2); // para sobrescrever, precisa do 2

  if (!outputFileUsers.is_open()) {
    std::cerr << "Erro ao abrir o arquivo para escrever: " << filePath << '\n';
    return;
  }

  // escreve as linhas de volta, excluindo a que tem o ID
  for (const auto &currentLine : lines) {
    // o ID é a primeira parte da linha
    if (currentLine.find(id_usuario) == std::string::npos) {
      outputFileUsers << currentLine << '\n';
    }
  }

  outputFileUsers.close();
}

bool RepositorioUsuarios::autenticar_login(std::string email,
                                           std::string senha) {

  std::ifstream FileUsers =
      openFileUsers<std::ifstream>(RepositorioUsuarios::filePath, 2);

  if (!FileUsers.is_open()) {
    std::cerr << "Erro ao abrir o arquivo para ler: " << filePath << '\n';
    return false;
  }

  std::string line = " ";

  while (std::getline(FileUsers, line)) {
    std::stringstream str(line);

    std::vector<std::string> auxiliar_login = splitString(line, ' ');

    if (auxiliar_login[1] == email) {
      if (auxiliar_login[2] == senha) {
        return true;
      } else {
        return false;
      }
    }
  }
  return false;
}

void RepositorioUsuarios::editar_usuarios(std::string id_usuario,
                                          const std::string novo_email,
                                          const std::string nova_senha,
                                          const std::string tipo) {

  remover_usuario(id_usuario);
  criar_usuario(novo_email, nova_senha, tipo, id_usuario);
}