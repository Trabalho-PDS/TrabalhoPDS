#pragma once

#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <map>
#include <iostream>
#include <unordered_set>

class GerenciarPosts {
public:
  void new_post(std::string const titulo, std::string const materia, std::string const descricao, std::string const nome_usuario, std::string const id_usuario);

  void delete_post(std::string const id_post);

  void edit_post(std::string const id_post, std::string id_usuario, std::map<std::string, std::string> novas_info);

private: 
  
};