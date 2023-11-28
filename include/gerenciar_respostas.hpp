#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "resposta.hpp"

class GerenciarRespostas {
public:
  void answer_post(const Resposta &new_resposta);

  void delete_answer(std::string const &id_resposta);

  std::vector<Resposta> respostas_do_post(std::string const &post_id);

private: 

};