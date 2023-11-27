#include "../include/gerenciar_respostas.hpp"
#include "../include/post.hpp"
#include "../include/repositorio_respostas.hpp"
#include "../include/repositorio_usuarios.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string> split_string_by_substring(std::string inputString) {
  std::vector<std::string> my_vector;
  std::string delimiter = "$&n&$~~";
  size_t pos = 0;
  std::string token;

  while ((pos = inputString.find(delimiter)) != std::string::npos) {
    token = inputString.substr(0, pos);
    my_vector.push_back(token);
    inputString.erase(0, pos + delimiter.length());
  }

  return my_vector;
}

void GerenciarRespostas::answer_post(const Resposta &new_resposta) {
  // conferir se o usuario existe antes de mandar criar
  RepositorioUsuarios repositorio_users;
  if (repositorio_users.dados_usuario(new_resposta.getIdMonitor()) ==
      "ID inválido") {
    throw std::invalid_argument("Inválido: " + new_resposta.getIdMonitor());
    return;
  }

  // Partir para a criação do Post:
  std::string post_id = new_resposta.getPostId();
  std::string id_monitor = new_resposta.getIdMonitor();
  std::string content = new_resposta.getContent();
  std::string answer_id = new_resposta.getAnswerId();
  RepositorioRespostas repositorio_posts;
  /*
    std::string const &post_id,
    std::string const &id_monitor,
    std::string const &content,
    std::string const &answer_id
  */

  repositorio_posts.answer_post(post_id, id_monitor, content, answer_id);
}

void GerenciarRespostas::delete_answer(std::string const &id_resposta) {
  RepositorioRespostas repo;
  repo.delete_answer(id_resposta);
}

std::vector<Resposta>
GerenciarRespostas::respostas_do_post(std::string const &post_id) {
  RepositorioRespostas repositorio;
  std::vector<std::string> my_vec = repositorio.answers_by_post_id(post_id);
  std::vector<Resposta> answers;

  for (size_t i = 0; i < my_vec.size(); i++) {
    std::vector<std::string> parts;

    parts = split_string_by_substring(my_vec[i]);

    answers[i].setAnswerId(parts[0]);
    answers[i].setPostId(parts[1]);
    answers[i].setIdMonitor(parts[2]);
    answers[i].setContent(parts[3]);
  }

  return answers;
}