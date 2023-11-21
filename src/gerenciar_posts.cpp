#include "../include/gerenciar_posts.hpp"
#include "../include/repositorio_posts.hpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>

void GerenciarPosts::new_post(const std::string titulo,
                              const std::string materia,
                              const std::string descricao,
                              const std::string nome_usuario,
                              const std::string id_usuario) {
  // gerando o id do post:
  std::string id_post;

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

    id_post += alphanumericCharacter;
  }

  // conferir se o usuario existe antes de mandar criar

  RepositorioPosts repositorio;
  repositorio.criar_post(titulo, materia, descricao, nome_usuario, id_post,
                         id_usuario);
}

void GerenciarPosts::delete_post(std::string const id_post) {
  // conferir se existe antes de mandar o programa remover.
  RepositorioPosts repositorio;
  repositorio.remover_post(id_post);
}

void GerenciarPosts::edit_post(std::string const id_post,
                               std::string id_usuario,
                               std::map<std::string, std::string> novas_info) {
  // conferir se existe antes de mandar o programa editar.
  RepositorioPosts repositorio;
  repositorio.editar_post(id_post, novas_info);
}