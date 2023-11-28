#include "../include/post.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

std::string generate_post_id() {
  std::string post_id = "";
  // inicializar gerador de número aleatório
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0,
                                          61); // inteiros entre 0 e 61

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

    post_id += alphanumericCharacter;
  }
  return post_id;
}

Post::Post(std::string const &disciplina, std::string const &conteudo,
           std::string const &titulo, std::string const &user_id)
    : _disciplina(disciplina), _conteudo(conteudo), _titulo(titulo),
      _user_id(user_id) {
  Post::_post_id = generate_post_id();
}

Post::Post() : _user_id("default"), _post_id("default") {}

// getters implementation:
std::string Post::getDisciplina() const { return Post::_disciplina; }
std::string Post::getConteudo() const { return Post::_conteudo; }
std::string Post::getTitulo() const { return Post::_titulo; }
std::string Post::getUserId() const { return Post::_user_id; }
std::string Post::getPostId() const { return Post::_post_id; }

// setters
void Post::setDisciplina(std::string const &disciplina) {
  Post::_disciplina = disciplina;
}
void Post::setConteudo(std::string const &conteudo) {
  Post::_conteudo = conteudo;
}
void Post::setTitulo(std::string const &titulo) { Post::_titulo = titulo; }

void Post::setPostId(std::string const &post_id) {
  Post::_post_id = "";

  if (post_id != "default") {
    Post::_post_id = post_id;
    return;
  }
  Post::_post_id = generate_post_id();
}
void Post::setUserId(std::string const &user_id) { Post::_user_id = user_id; }
