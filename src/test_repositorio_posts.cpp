#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/repositorio_posts.hpp"
#include "doctest.hpp"

TEST_CASE("Testando a adição de posts") {
  RepositorioPosts repositorio;
  repositorio.criar_post("Teste", "PDS2", "projeto final", "Fulano123",
                         "id_post", ":8>9AIjsHoh6rfkH");
}

TEST_CASE("Testando a remoção de posts") {
  RepositorioPosts repositorio;
  SUBCASE("Criando o post que será removido") {
    repositorio.criar_post("Teste2", "PDS2", "projeto final - teste 2",
                           "Fulano123", "id_post2", ":8>9AIjsHoh6rfkH");
  }
  SUBCASE("Removendo de fato") {
    repositorio.remover_post("id_post2");
  }
}