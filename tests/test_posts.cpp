#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/gerenciar_posts.hpp"
#include "../include/post.hpp"
#include "../include/repositorio_posts.hpp"
#include "doctest.hpp"
#include <iostream>
#include <vector>

TEST_CASE("Testando a adição e edição de posts") {

  RepositorioPosts repo;
  SUBCASE("Adicionando o post diretamente pela classe RepositorioPosts") {
    repo.criar_post(
        "titulo", "const std::string disciplina", "const std::string conteudo",
        "const std::string post_id",
        "const std::string user_id"); // como as partes de criar id e de
                                      // verificação de usuário não são da
                                      // responsabilidade dessa classe, não
                                      // houve um rigor na criação desse post
  }

  SUBCASE("Adicionando o post corretamente pelo Post e GerenciarPosts") {
    /*
    std::string const& disciplina, std::string const& conteudo, std::string
    const& titulo, std::string const& user_id
    */
    Post new_post("matemática discreta", "tenho dúvidas em isso, aquilo e etc.",
                  "Dúvida - MD", "907077e91c9c893");

    GerenciarPosts manager;
    REQUIRE_NOTHROW(
        manager.new_post(new_post)); // verifica se não deu erro ao criar
  }

  SUBCASE("Editando o post diretamente pela classe RepositorioPosts") {
    repo.editar_post(
        "titulo", "const std::string &disciplina", "const std::string &cont",
        "const std::string post_id",
        "const std::string &user_id"); // testando diretamente de novo.
  }

  SUBCASE("Editando o post corretamente pelo Post e GerenciarPosts") {
    Post new_post("PDS2", "duvida", "Algo", "907077e91c9c893");
    GerenciarPosts manager;
    REQUIRE_NOTHROW(manager.new_post(new_post));

    std::string id = new_post.getPostId();

    repo.editar_post("Algo", "PDS2", "const std::string &cont",
                     new_post.getPostId(), "907077e91c9c893");

    new_post.setConteudo("ola");
    REQUIRE(new_post.getConteudo() == "ola");
    REQUIRE(new_post.getPostId() == id);

    manager.edit_post(new_post);
  }
}

TEST_CASE("Testando a remoção dos posts") {
  RepositorioPosts repo;

  SUBCASE("Removendo o post diretamente pela classe RepositorioPosts") {
    REQUIRE_NOTHROW(repo.remover_post("const std::string post_id"));
  }

  SUBCASE("Removendo o post pelas classes Post e GerenciarPosts") {
    Post my_rm_post("PDS2", "duvida007 aaa", "Algo123", "907077e91c9c893");
    GerenciarPosts manager;
    REQUIRE_NOTHROW(manager.new_post(my_rm_post));
    REQUIRE_NOTHROW(manager.delete_post(my_rm_post.getPostId()));
  }
}

TEST_CASE("Testando a busca por posts") {
  RepositorioPosts repo;
  std::vector<std::string> my_vec;
  std::vector<std::string> my_vec2;

  my_vec = repo.buscar_posts("PDS2");
  REQUIRE(!my_vec.empty());

  CHECK(my_vec[my_vec.size() - 1].find("907077e91c9c893") != std::string::npos);
}
