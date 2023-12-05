#pragma once

#include <string>
#include "post.hpp"
#include <sstream>
#include <filesystem>
#include <fstream>
#include <map>
#include <iostream>
#include <vector>

class GerenciarPosts {
public:
  /**
   * @brief Criar um novo post.
   * @param new_post: Referencia para um post.
   * @retval none.
   * */ 
  void new_post(const Post &new_post);
  /**
   * @brief Deletar um post.
   * @param id_post: id de um post.
   * @retval none.
   * */
  void delete_post(std::string const id_post);
  /**
   * @brief Editar um post.
   * @param edited_post: Referencia para um post.
   * @retval none.
   * */
  void edit_post(const Post &edited_post);

private: 
  
};