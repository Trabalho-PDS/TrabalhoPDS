#pragma once

#include <string>
#include "resposta.hpp"
#include <iostream>
#include <vector>

class RepositorioRespostas {
public:
  /**
  * @brief Realiza o processo concreto da criação de uma resposta, a adicionando no banco de dados.
  * @param post_id, id_monitor, content, answer_id: post_id, id_monitor, content, answer_id.
  * @retval none.
  * */
  void answer_post(std::string const& post_id, std::string const& id_monitor, std::string const& content, std::string const&answer_id);
  /**
  * @brief Realiza o processo concreto da remoção de uma resposta no banco de dados.
  * @param answer_id: id de uma resposta.
  * @retval none.
  * */
  void delete_answer(std::string const& answer_id);
  /**
  * @brief Retorna todas as respostas relacionadas a um determinado post.
  * @param post_id: id do post.
  * @retval std::vector<std::string>
  * */
  std::vector<std::string> answers_by_post_id(std::string const& post_id);
private: 
  //std::string _currentPath = std::filesystem::current_path().string();
  std::string _filePath = "../storage/resposta.txt";

};