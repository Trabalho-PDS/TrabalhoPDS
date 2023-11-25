#include "../include/repositorio_usuarios.hpp"
//#include "user.cpp"
#include <iostream>
#include <string>

int main() {
  /*  std::string input_email, input_name, input_surname;

    std::cin >> input_email;

    User user(input_name, input_surname);
    user.changeEmail(input_email);

      while (!user.isEmail(input_email)) {
        std::cout << "Insira um email válido" << std::endl;
        std::cin >> input_email;
        user.changeEmail(input_email);
      }

      std::cin >> input_name;
      std::cin >> input_surname;

      std::cout << user.seeEmail() << std::endl;
      std::cout << user.seeName() << std::endl;
    */

  std::cout << "O que você deseja fazer? [1] - cadastro [2] - login";
  short int option = 0;
  std::cin >> option;
  if (option == 1) {
    std::cout << "Insira seu nome: ";
    std::string nome = " ", sobrenome = " ";
    std::cin >> nome;
    std::cout << "\nInsira seu sobrenome: ";
    std::cin >> sobrenome;
    nome = nome + sobrenome;
    std::cout << "\nInsira seu email: ";
    std::string email = " ";
    std::cin >> email;
    std::cout << "\nInsira sua senha: ";
    std::string senha = " ";
    std::cin >> senha;
    std::cout << "\nQual é seu tipo de usuario? (monitor ou aluno)";
    std::string tipo = " ";
    std::cin >> tipo;
    RepositorioUsuarios repositorio;
    repositorio.criar_usuario(email, senha, nome, tipo);
    std::cout << "Seus dados: " << nome << std::endl;
    return 0;
  }
  std::cout << "Insira seu email: ";
  std::string email = " ";
  std::cin >> email;
  std::cout << "\nInsira sua senha: ";
  std::string senha = " ";
  std::cin >> senha;
  RepositorioUsuarios repositorio;

  if (repositorio.autenticar_login(email, senha)) {
    std::string id_usuario = repositorio.identidade_usuario(email);
    std::cout
        << "O que você deseja fazer? [1] - Remover conta [2] - Ver meus dados "
           "dados [3] - Sair \n";

    short int option = 0;
    std::cin >> option;
    
    switch (option) {
    case 1:
      repositorio.remover_usuario(id_usuario);
      break;
    case 2:
      std::cout << repositorio.dados_usuario(id_usuario);
      break;
    case 3:
      return 0;
    }
  }

  return 0;
}
