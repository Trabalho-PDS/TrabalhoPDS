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

std::vector<std::string> splitString(const std::string &input, char delimiter) {
  std::vector<std::string> parts;
  std::stringstream ss(input);
  std::string part;

  while (std::getline(ss, part, delimiter)) {
    parts.push_back(part);
  }

  return parts;
}

std::string generate_user_id(std::string const &email,
                             std::string const &password) {
  // Concatenate email and password
  std::string combinedString = email + password;

  // Use std::hash to generate a hash value
  std::hash<std::string> hasher;
  std::size_t hashValue = hasher(combinedString);

  // Convert the hash value to an alphanumeric string
  std::ostringstream ss;
  ss << std::hex << hashValue;

  return ss.str();
}

bool binary_search(std::vector<std::string> vecOfStrings, std::string element) {
  bool return_value =
      std::binary_search(vecOfStrings.begin(), vecOfStrings.end(), element);
  return return_value;
}

void RepositorioUsuarios::criar_usuario(const std::string email,
                                        const std::string senha,
                                        const std::string nome_completo,
                                        std::string const tipo,
                                        std::string id_usuario) {

  // verifica se o usuário já existe:

  if (id_usuario == "default") {
    id_usuario = generate_user_id(email, senha);
  }

  std::ifstream AuthkeysFile;

  std::vector<std::string> authkeysVec;
  authkeysVec.clear();
  try {
    AuthkeysFile.open(RepositorioUsuarios::_authkeysPath);
    std::string line = " ";
    while (std::getline(AuthkeysFile, line)) {
      authkeysVec.push_back(line);
    }
    AuthkeysFile.close();
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    return;
  }

  if (binary_search(authkeysVec, id_usuario)) {
    throw std::invalid_argument("O usuário já existe!");
    return;
  }

  // verifica se já tem um usuário com o e-mail informado:
  if (identidade_usuario(email) != "not found!") {
    throw std::invalid_argument("O e-mail já está cadastrado!");
    return;
  }

  authkeysVec.push_back(id_usuario);

  // Use the custom comparator to ensure stable sort
  std::sort(authkeysVec.begin(), authkeysVec.end());

  std::ofstream AuthkeysFile_out;

  try {
    AuthkeysFile_out.open(RepositorioUsuarios::_authkeysPath);
    for (const auto &currentLine : authkeysVec) {
      AuthkeysFile_out << currentLine << '\n';
    }

    AuthkeysFile_out.close();
  } catch (std::ofstream::failure &e) {
    std::cerr << e.what();
    return;
  }

  authkeysVec.clear();

  std::ofstream FileUsers;

  try {
    FileUsers.open(RepositorioUsuarios::_filePath, std::ios::app);
    FileUsers << id_usuario + " " + email + " " + nome_completo + " " + tipo +
                     "\n";

    FileUsers.close();
  } catch (std::ofstream::failure &e) {
    std::cerr << e.what();
    return;
  }
}

void RepositorioUsuarios::remover_usuario(std::string const id_usuario) {
  // conferindo se o usuário existe realmente:
  std::ifstream AuthkeysFile;

  std::vector<std::string> authkeysVec;
  std::string line = " ";

  try {
    AuthkeysFile.open(RepositorioUsuarios::_authkeysPath);

    while (std::getline(AuthkeysFile, line)) {
      authkeysVec.push_back(line);
    }
    AuthkeysFile.close();
  } catch (std::ifstream::failure &e) {
    std::cerr << e.what();
    return;
  }

  if (!binary_search(authkeysVec, id_usuario)) {
    throw std::invalid_argument("Id informado não existe!");
    return;
  }

  std::ofstream AuthkeysFile_out;

  try {
    AuthkeysFile_out.open(RepositorioUsuarios::_authkeysPath);
    for (const auto &currentLine : authkeysVec) {
      // o ID é a primeira parte da linha
      if (currentLine.find(id_usuario) == std::string::npos) {
        AuthkeysFile_out << currentLine << '\n';
      }
    }

    AuthkeysFile_out.close();
  } catch (std::ofstream::failure &e) {
    std::cerr << e.what();
    return;
  }

  // armazena o conteúdo do arquivo na memória
  std::ifstream inputFileUsers;
  std::vector<std::string> lines;
  try {
    inputFileUsers.open(RepositorioUsuarios::_filePath);

    line = " ";
    while (std::getline(inputFileUsers, line)) {
      lines.push_back(line);
    }

    inputFileUsers.close();
  } catch (std::ifstream::failure &e) {
    std::cerr << e.what();
    return;
  }

  // sobrescrever o arquivo original com o conteúdo atualizado
  std::ofstream outputFileUsers;

  try {
    outputFileUsers.open(RepositorioUsuarios::_filePath);
    for (const auto &currentLine : lines) {
      // o ID é a primeira parte da linha
      if (currentLine.find(id_usuario) == std::string::npos) {
        outputFileUsers << currentLine << '\n';
      }
    }

    outputFileUsers.close();
  } catch (std::ofstream::failure &e) {
    std::cerr << e.what();
    return;
  }

  // escreve as linhas de volta, excluindo a que tem o ID
}

bool RepositorioUsuarios::autenticar_login(std::string email,
                                           std::string senha) {

  std::string id_usuario = generate_user_id(email, senha);

  std::ifstream AuthkeysFile;

  try {
    AuthkeysFile.open(RepositorioUsuarios::_authkeysPath);
    std::vector<std::string> authkeysVec;

    std::string line = " ";

    while (std::getline(AuthkeysFile, line)) {
      authkeysVec.push_back(line);
    }

    AuthkeysFile.close();

    if (!binary_search(authkeysVec, id_usuario)) {
      return false;
    }
    return true;
  } catch (std::ifstream::failure &e) {
    std::cerr << e.what();
    return false;
  }
}

std::string RepositorioUsuarios::identidade_usuario(std::string const email) {
  std::ifstream FileUsers;

  try {
    FileUsers.open(RepositorioUsuarios::_filePath);
    std::string line = " ";

    while (std::getline(FileUsers, line)) {
      std::stringstream str(line);

      std::vector<std::string> auxiliarLogin = splitString(line, ' ');
      if (auxiliarLogin[1] == email) {

        FileUsers.close();
        return auxiliarLogin[0];
      }
    }
    FileUsers.close();
    return "not found!";
  } catch (std::ifstream::failure &e) {
    std::cerr << e.what();
    return "";
  }
}

std::string RepositorioUsuarios::dados_usuario(const std::string idUsuario) {
  std::ifstream FileUsers;

  try {
    FileUsers.open(RepositorioUsuarios::_filePath);
    std::string line = " ";

    while (std::getline(FileUsers, line)) {
      std::stringstream str(line);

      std::vector<std::string> auxiliar_dados = splitString(line, ' ');
      if (auxiliar_dados[0] == idUsuario) {
        std::string final_userstr = "";
        for (std::size_t i = 1; i < auxiliar_dados.size(); i++) {
          final_userstr += auxiliar_dados[i];
          if (i != auxiliar_dados.size() - 1) {
            final_userstr += " ";
          }
        }
        return final_userstr;
      }
    }
    FileUsers.close();
    return "ID inválido";
  } catch (const std::ifstream::failure &e) {
    std::cerr << e.what();
    return "Erro";
  }
}
