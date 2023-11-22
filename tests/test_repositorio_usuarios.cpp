#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/repositorio_usuarios.hpp"
#include "doctest.hpp"

TEST_CASE("Testando o cadastro de usuários e o login") {
  RepositorioUsuarios repositorio;
  repositorio.criar_usuario("fulano123@gmail.com", "senha123", "aluno");

  CHECK(repositorio.autenticar_login("fulano123@gmail.com", "senha123"));
}

TEST_CASE("Testando a remoção de usuários") {
  RepositorioUsuarios repositorio;
  SUBCASE("Cadastrando o usuário que vai ser removido") {
    repositorio.criar_usuario("fulano1234@gmail.com", "senha1234", "monitor");

    CHECK(repositorio.autenticar_login("fulano1234@gmail.com", "senha1234"));
  }
  SUBCASE("Removendo o usuário") {
    std::string idUsuario =
        repositorio.identidade_usuario("fulano1234@gmail.com", "senha1234");
    repositorio.remover_usuario(idUsuario);
  }
  SUBCASE("Após removido, o usuário não pode mais logar") {
    CHECK(!repositorio.autenticar_login("fulano1234@gmail.com", "senha1234"));
  }
}

TEST_CASE("Testando a edição de usuários") {
  RepositorioUsuarios repositorio;

  SUBCASE("Criando o usuário que vai ser eidtado") {
    repositorio.criar_usuario("ciclano123@gmail.com", "senha1235", "professor");

    CHECK(repositorio.autenticar_login("ciclano123@gmail.com", "senha1235"));
  }
  SUBCASE("Editando o usuário") {
    std::string idUsuario =
        repositorio.identidade_usuario("ciclano123@gmail.com", "senha1235");
    repositorio.editar_usuarios(idUsuario, "ciclano2123@gmail.com",
                                "senhaaa55S2", "professor");
  }
  SUBCASE("Após editado, o usuário não pode logar com os dados antigos, "
          "somente com os novos") {
    CHECK(!repositorio.autenticar_login("ciclano123@gmail.com", "senha1235"));
    CHECK(repositorio.autenticar_login("ciclano2123@gmail.com", "senhaaa55S2"));
  }
}

TEST_CASE("Testando a string dos usuários") {
  RepositorioUsuarios repositorio;
  std::string const m_rep = repositorio.dados_usuario(
      repositorio.identidade_usuario("ciclano2123@gmail.com", "senhaaa55S2"));
  CHECK_EQ(m_rep, "ciclano2123@gmail.com senhaaa55S2 professor");
}