#pragma once

#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_set>

class RepositorioPosts {
public:
  /**
  * @brief Realiza o processo concreto da criação de um post, o adicionando no banco de dados.
  * @param titulo, disciplina, conteudo, post_id, user_id: titulo, disciplina, conteudo, post_id, user_id.
  * @retval none.
  * */
  void criar_post(std::string const titulo,
                  std::string const disciplina,
                  std::string const conteudo,
                  std::string const post_id,
                  std::string const user_id);
  /**
  * @brief Realiza o processo concreto da remoção de um post do banco de dados.
  * @param id_post: id do post.
  * @retval none.
  * */
  void remover_post(std::string const id_post);
  /**
  * @brief Realiza o processo concreto da edição de um post no banco de dados.
  * @param titulo, disciplina, conteudo, post_id, user_id: titulo, disciplina, conteudo, post_id, user_id.
  * @retval none.
  * */
  void editar_post(std::string const& titulo, 
                  std::string const& disciplina, 
                  std::string const& conteudo,                   
                  std::string const& post_id,
                  std::string const& user_id);
  /**
  * @brief Retorna todos os posts obtidos, atraves de um vetor, apos uma busca no banco de dados com determinada palavra filtro.
  * @param filter: filtro de pesquisa.
  * @retval std::vector<std::string>
  * */
  std::vector<std::string> buscar_posts(std::string filter);

private: 
  //std::string _currentPath = std::filesystem::current_path().string();
  std::string _filePath = "../storage/post.txt";
};