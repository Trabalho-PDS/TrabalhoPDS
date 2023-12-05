#pragma once

#include <string>
#include <iostream>
#include <ctime>

class Post {
public:
  /**
  * @brief Construtor padrão para a classe Post.
  * @param disciplina, conteudo, titulo, user_id: disciplina, conteudo, titulo, user_id.
  * @retval none.
  * */
  Post(std::string const& disciplina, std::string const& conteudo, std::string const& titulo, std::string const& user_id);
  /**
  * @brief Construtor genérico para a classe Post.
  * @retval none.
  * */
  Post();
  /**
  * @brief Getter disciplina.
  * @retval std::string
  * */
  std::string getDisciplina() const;
  /**
  * @brief Getter conteudo.
  * @param new_resposta: Referencia para uma resposta.
  * @retval std::string
  * */
  std::string getConteudo() const;
  /**
  * @brief Getter titulo.
  * @param new_resposta: Referencia para uma resposta.
  * @retval std::string
  * */
  std::string getTitulo() const;
  /**
  * @brief Getter id do usuario.
  * @param new_resposta: Referencia para uma resposta.
  * @retval std::string
  * */
  std::string getUserId() const;
  /**
  * @brief Getter id do post.
  * @param new_resposta: Referencia para uma resposta.
  * @retval std::string
  * */
  std::string getPostId() const;
  /**
  * @brief Setter disciplina.
  * @param disciplina: disciplina.
  * @retval none
  * */
  void setDisciplina(std::string const& disciplina);
  /**
  * @brief Setter conteudo.
  * @param conteudo: conteudo.
  * @retval none
  * */
  void setConteudo(std::string const& conteudo);
  /**
  * @brief Setter titulo.
  * @param titulo: titulo.
  * @retval none
  * */
  void setTitulo(std::string const& titulo);
  /**
  * @brief Setter id do post.
  * @param post_id: id do post.
  * @retval none
  * */
  void setPostId(std::string const& post_id = "default");
  /**
  * @brief Setter id do usuario.
  * @param user_id: id do usuario.
  * @retval none
  * */
  void setUserId(std::string const& user_id);

private:
  std::string _disciplina;
  std::string _conteudo;
  std::string _titulo;
  std::string _user_id;
  std::string _post_id;
};