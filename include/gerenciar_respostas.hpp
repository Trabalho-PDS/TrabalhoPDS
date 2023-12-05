#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "resposta.hpp"

class GerenciarRespostas {
public:
  /**
   * @brief Adicionar uma resposta a um post.
   * @param new_resposta: Referencia para uma resposta.
   * @retval none.
   * */ 
  void answer_post(const Resposta &new_resposta);
  /**
   * @brief Deletar uma resposta.
   * @param id_resposta: id de uma resposta.
   * @retval none.
   * */
  void delete_answer(std::string const &id_resposta);
  /**
   * @brief Retorna todas as respostas relacionada a um determinado post.
   * @param post_id: id de um post.
   * @retval std::vector<Resposta>
   * */
  std::vector<Resposta> respostas_do_post(std::string const &post_id);

private: 

};