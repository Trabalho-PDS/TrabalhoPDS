#pragma once

#include <string>
#include "resposta.hpp"
#include <iostream>
#include <vector>

class RepositorioRespostas {
public:
//std::string const& post_id, std::string const& id_monitor, std::string const& content, std::string const&answer_id
  void answer_post(std::string const& post_id, std::string const& id_monitor, std::string const& content, std::string const&answer_id);

  void delete_answer(std::string const& answer_id);

  std::vector<std::string> answers_by_post_id(std::string const& post_id);
private: 
  //std::string _currentPath = std::filesystem::current_path().string();
  std::string _filePath = "storage/resposta.txt";

};