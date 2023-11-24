#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/repositorio_usuarios.hpp"
#include "doctest.hpp"

TEST_CASE("Testando o login") {
  RepositorioUsuarios repositorio;
  // com o usuário base 907077e91c9c893
  SUBCASE(
      "Após cadastrado, o usuário pode fazer o login com os dados informados") {
    CHECK(repositorio.autenticar_login("fulano1235@gmail.com",
                                       "senha_para_id55"));
  }

  SUBCASE("Após cadastrado, o mesmo e-mail não pode ser cadastrado novamente") {
    REQUIRE_THROWS(repositorio.criar_usuario(
        "fulano1235@gmail.com", "senha_para_id545", "ciclano junior", "aluno"));
  }
}

TEST_CASE("Testando a remoção de usuários") {
  RepositorioUsuarios repositorio;
  SUBCASE("Cadastrando o usuário que vai ser removido") {
    REQUIRE_NOTHROW(repositorio.criar_usuario("fulano12355oioi@gmail.com",
                                              "senha_para_id2", "ciclano alien",
                                              "aluno"));

    REQUIRE(repositorio.autenticar_login("fulano12355oioi@gmail.com",
                                         "senha_para_id2"));
  }
  SUBCASE("Removendo o usuário") {
    std::string idUsuario =
        repositorio.identidade_usuario("fulano12355oioi@gmail.com");
    repositorio.remover_usuario(idUsuario);
  }
  SUBCASE("Após removido, o usuário não pode mais logar") {
    CHECK_FALSE(repositorio.autenticar_login("fulano12355oioi@gmail.com",
                                             "senha_para_id2"));
  }
}

TEST_CASE("Testando a string dos usuários") {
  RepositorioUsuarios repositorio;
  std::string const m_rep = repositorio.dados_usuario(
      repositorio.identidade_usuario("fulano1234@gmail.com"));
  CHECK_EQ(m_rep, "fulano1234@gmail.com ciclano junior aluno");
}
