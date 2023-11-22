#include "../include/repositorio_usuarios.hpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <unordered_set>
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
  std::string idUsuario;

  // inicializar gerador de número aleatório
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0,
                                          61); // inteiros entre 0 e 25

  for (int i = 0; i < 16; i++) {
    int randomNumber = dist(gen);

    // converte o número aleatório para alfanumérico
    char alphanumericCharacter = ' ';
    if (randomNumber < 26) {
      alphanumericCharacter = (char)('a' + randomNumber); // letras minúsculas
    } else if (randomNumber < 36) {
      alphanumericCharacter =
          (char)('A' + randomNumber - 26); // letras maiúsculas
    } else {
      alphanumericCharacter = (char)('0' + randomNumber - 36);
    }

    idUsuario += alphanumericCharacter;
  }

  return idUsuario;
}

void RepositorioUsuarios::criar_usuario(const std::string email,
                                        const std::string senha,
                                        const std::string tipo,
                                        std::string id_usuario) {
  std::cout << "Attempting to open file: " << RepositorioUsuarios::_filePath
            << std::endl;

  std::ofstream FileUsers =
      openFileUsers<std::ofstream>(RepositorioUsuarios::_filePath, 1);

  if (!FileUsers.is_open()) {
    std::cerr << "Error opening file: " << RepositorioUsuarios::_filePath
              << '\n';
    return; // Exit the function if the file couldn't be opened
  }

  if (id_usuario == "default") {
    id_usuario = generate_id_usuario();
  }

  FileUsers << id_usuario + " " + email + " " + senha + " " + tipo + "\n";

  if (FileUsers.fail()) {
    std::cerr << "Error writing to file: " << _filePath << '\n';
  }

  FileUsers.close();
}

void RepositorioUsuarios::remover_usuario(std::string id_usuario) {
  // armazena o conteúdo do arquivo na memória
  std::ifstream inputFileUsers =
      openFileUsers<std::ifstream>(RepositorioUsuarios::_filePath, 2);

  if (!inputFileUsers.is_open()) {
    std::cerr << "Erro ao abrir para a ler: " << _filePath << '\n';
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
      RepositorioUsuarios::_filePath, 2); // para sobrescrever, precisa do 2

  if (!outputFileUsers.is_open()) {
    std::cerr << "Erro ao abrir o arquivo para escrever: " << _filePath << '\n';
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
      openFileUsers<std::ifstream>(RepositorioUsuarios::_filePath, 2);

  if (!FileUsers.is_open()) {
    std::cerr << "Erro ao abrir o arquivo para ler: " << _filePath << '\n';
    return false;
  }

  std::string line = " ";

  while (std::getline(FileUsers, line)) {
    std::stringstream str(line);

    std::vector<std::string> auxiliarLogin = splitString(line, ' ');

    if (auxiliarLogin[1] == email && auxiliarLogin[2] == senha) {
      return true;
    }
  }
  FileUsers.close();
  return false;
}

void RepositorioUsuarios::editar_usuarios(std::string id_usuario,
                                          const std::string novo_email,
                                          const std::string nova_senha,
                                          const std::string tipo) {
  // existing implementation

  remover_usuario(id_usuario);
  criar_usuario(novo_email, nova_senha, tipo, id_usuario);
}

std::string RepositorioUsuarios::identidade_usuario(std::string email,
                                                    std::string senha) {
  std::ifstream FileUsers =
      openFileUsers<std::ifstream>(RepositorioUsuarios::_filePath, 2);
  std::string errorMessage = "Login inválido\n";

  if (!FileUsers.is_open()) {
    return "Erro ao abrir o arquivo para ler\n";
  }

  std::string line = " ";

  while (std::getline(FileUsers, line)) {
    std::stringstream str(line);

    std::vector<std::string> auxiliarLogin = splitString(line, ' ');
    if (auxiliarLogin[1] == email && auxiliarLogin[2] == senha) {
      return auxiliarLogin[0];
    }
  }
  FileUsers.close();

  return errorMessage;
}

std::string RepositorioUsuarios::dados_usuario(const std::string idUsuario) {
  std::ifstream FileUsers =
      openFileUsers<std::ifstream>(RepositorioUsuarios::_filePath, 2);
  std::string errorMessage = "ID inválido\n";

  if (!FileUsers.is_open()) {
    return "Erro ao abrir o arquivo para ler\n";
  }

  std::string line = " ";

  while (std::getline(FileUsers, line)) {
    std::stringstream str(line);

    std::vector<std::string> auxiliarLogin = splitString(line, ' ');
    if (auxiliarLogin[0] == idUsuario) {
      return auxiliarLogin[1] + " " + auxiliarLogin[2] + " " + auxiliarLogin[3];
    }
  }
  FileUsers.close();

  return errorMessage;
}