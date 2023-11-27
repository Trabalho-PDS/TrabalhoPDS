#include "../include/gerenciar_posts.hpp"
#include "../include/gerenciar_respostas.hpp"
#include "../include/post.hpp"
#include "../include/repositorio_posts.hpp"
#include "../include/repositorio_respostas.hpp"
#include "../include/repositorio_usuarios.hpp"
#include "../include/resposta.hpp"
//#include "user.cpp"
#include <iostream>
#include <string>
#include <vector>

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
    nome = nome + " " + sobrenome;
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
    repositorio.criar_usuario(email, senha, nome, tipo, "default");
    std::cout << "Seus dados salvos: " << nome << " " << email << " " << tipo
              << std::endl;
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

    std::string current_user = repositorio.dados_usuario(id_usuario);
    std::vector<std::string> parts;
    std::stringstream ss(current_user);
    std::string part;

    while (std::getline(ss, part, ' ')) {
      parts.push_back(part);
    }

    std::cout << "O que você deseja fazer? [1] - Remover conta [2] - Ver "
                 "meus dados "
                 "dados [3] - Ver posts [4] - Sair \n";

    short int option = 0;
    std::cin >> option;
    if (option == 4)
      return 0;
    switch (option) {
    case 1:
      repositorio.remover_usuario(id_usuario);
      break;
    case 2:
      std::cout << repositorio.dados_usuario(id_usuario);
      break;
    case 3:
      RepositorioPosts repo_posts;
      std::cout << "Esses são os posts: \n";
      std::vector<std::string> posts = repo_posts.buscar_posts("$&n&$~~");
      for (auto i : posts) {
        std::cout << i << std::endl;
      }
      std::cout << "O que você deseja fazer? ";
      if (parts[parts.size() - 1] == "monitor") {
        std::cout << "[1] - responder um post [2] - sair [3] - ver respostas "
                     "de um post\n";
        short int op = 0;
        std::cin >> op;
        if (op == 1) {
          std::cout << "Insira o id do post que deseja responder: ";
          std::string post_id = " ";
          std::cin >> post_id;
          std::cout << "Insira sua resposta: ";
          std::string aux = " ";
          std::getline(std::cin, aux);
          std::string content = " ";
          std::getline(std::cin, content);

          std::string id_monitor = repositorio.identidade_usuario(email);

          Resposta resposta(post_id, id_monitor, content);

          GerenciarRespostas gerenciar_respostas;
          gerenciar_respostas.answer_post(resposta);
        }
      } else {
        std::cout << "[1] - criar um post [2] - sair [3] - ver respostas de um "
                     "post\n";
        short int op = 0;
        std::cin >> op;
        switch (op) {
        case 2:
          return 0;
        case 1:
          std::string disciplina = " ", conteudo = " ", titulo = " ",
                      user_id = repositorio.identidade_usuario(email), aux = "";
          std::getline(std::cin, aux);
          std::cout << "Insira a disciplina: ";
          std::getline(std::cin, disciplina);
          std::cout << "\nInsira o conteudo: ";
          std::getline(std::cin, conteudo);
          std::cout << "\nInsira o titulo: ";
          std::getline(std::cin, titulo);
          Post the_new_post(disciplina, conteudo, titulo, user_id);
          GerenciarPosts manage_posts;
          manage_posts.new_post(the_new_post);
          std::cout << "Post criado! ";
          break;
        }
        if (op == 3) {
          std::cout << "Insira o id de um: ";
          std::string id_post = " ";
          std::cin >> id_post;
          RepositorioRespostas repo_answers;
          std::vector<std::string> my_answers =
              repo_answers.answers_by_post_id(id_post);
          for (auto i : my_answers) {
            std::cout << i << std::endl;
          }
        }
      }
      break;
    }
  }

  return 0;
}