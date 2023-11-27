#include "../include/gerenciar_posts.hpp"
#include "../include/post.hpp"
#include "../include/repositorio_posts.hpp"
#include "../include/repositorio_usuarios.hpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <stdexcept>

void GerenciarPosts::new_post(const Post &new_post) {
  // conferir se o usuario existe antes de mandar criar
  RepositorioUsuarios repositorio_users;
  if (repositorio_users.dados_usuario(new_post.getUserId()) == "ID inválido") {
    throw std::invalid_argument("Inválido: " + new_post.getUserId());
    return;
  }

  // Partir para a criação do Post:
  std::string titulo = new_post.getTitulo();
  std::string user_id = new_post.getUserId();
  std::string post_id = new_post.getPostId();
  std::string disciplina = new_post.getDisciplina();
  std::string conteudo = new_post.getConteudo();

  RepositorioPosts repositorio_posts;

  repositorio_posts.criar_post(titulo, disciplina, conteudo, post_id, user_id);
}

void GerenciarPosts::delete_post(std::string const id_post) {
  RepositorioPosts repositorio;
  repositorio.remover_post(
      id_post); // o próprio remover_post já verifica se o post existe ou não.
}

void GerenciarPosts::edit_post(const Post &edited_post) {
  RepositorioUsuarios repositorio_users;
  if (repositorio_users.dados_usuario(edited_post.getUserId()) ==
      "ID inválido") {
    throw std::invalid_argument("Inválido: " + edited_post.getUserId());
    return;
  }

  RepositorioPosts repositorio;

  std::string titulo = edited_post.getTitulo();
  std::string disciplina = edited_post.getDisciplina();
  std::string user_id = edited_post.getUserId();
  std::string post_id = edited_post.getPostId();
  std::string conteudo = edited_post.getConteudo();
  /*void RepositorioPosts::editar_post(std::string const &titulo,
                                     std::string const &disciplina,
                                     std::string const &conteudo,
                                     std::string const &post_id,
                                     std::string const &user_id)*/
  repositorio.editar_post(
      titulo, disciplina, conteudo, post_id,
      user_id); // ele também verifica se o post existe antes de editar
}