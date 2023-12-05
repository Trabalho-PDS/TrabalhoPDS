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
  void criar_post(std::string const titulo,
                  std::string const disciplina,
                  std::string const conteudo,
                  std::string const post_id,
                  std::string const user_id);

  void remover_post(std::string const id_post);

  void editar_post(std::string const& titulo, 
                  std::string const& disciplina, 
                  std::string const& conteudo,                   
                  std::string const& post_id,
                  std::string const& user_id);

  std::vector<std::string> buscar_posts(std::string filter);

private: 
  //std::string _currentPath = std::filesystem::current_path().string();
  std::string _filePath = "../storage/post.txt";
};