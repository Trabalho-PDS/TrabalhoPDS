#pragma once

#include <string>
#include <iostream>
#include <ctime>

class Post {
public:
  
  Post(std::string const& disciplina, std::string const& conteudo, std::string const& titulo, std::string const& user_id);
  Post();

  // getters
  std::string getDisciplina() const;
  std::string getConteudo() const;
  std::string getTitulo() const;
  std::string getUserId() const;
  std::string getPostId() const;

  // setters
  void setDisciplina(std::string const& disciplina);
  void setConteudo(std::string const& conteudo);
  void setTitulo(std::string const& titulo);
  void setPostId(std::string const& post_id = "default");
  void setUserId(std::string const& user_id);

private:
  std::string _disciplina;
  std::string _conteudo;
  std::string _titulo;
  std::string _user_id;
  std::string _post_id;
};