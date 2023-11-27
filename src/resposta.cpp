#include "../include/resposta.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

std::string generate_answer_id() {
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

Resposta::Resposta(std::string const &post_id, std::string const &id_monitor,
                   std::string const &content)
    : _post_id(post_id), _id_monitor(id_monitor), _content(content) {
  Resposta::_answer_id = generate_answer_id();
}

Resposta::Resposta() {}

std::string Resposta::getPostId() const { return _post_id; }

std::string Resposta::getIdMonitor() const { return _id_monitor; }

std::string Resposta::getContent() const { return _content; }

std::string Resposta::getAnswerId() const { return _answer_id; }

void Resposta::setPostId(std::string const &post_id) { _post_id = post_id; }

void Resposta::setIdMonitor(std::string const &id_monitor) {
  _id_monitor = id_monitor;
}

void Resposta::setContent(std::string const &content) { _content = content; }

void Resposta::setAnswerId(std::string const &answer_id) {
  _answer_id = answer_id;
}