#pragma once

#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <unordered_set>

class RepositorioPosts {
public:
  void criar_post(std::string const titulo, std::string const materia, std::string const descricao, std::string const nome_usuario, std::string const id_post, std::string const id_usuario);

  void remover_post(std::string const id_post);

  void editar_post(std::string const id_post, std::map<std::string, std::string> novas_info);

  void buscar_posts(std::unordered_set<std::string> filtros);

private: 
  std::vector<std::string> splitString(const std::string &input, char delimiter);
  std::string _currentPath = std::filesystem::current_path().string();
  std::string _filePath = _currentPath + "/storage/post.txt";
};