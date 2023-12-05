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
  void new_post(const Post &new_post);

  void delete_post(std::string const id_post);

  void edit_post(const Post &edited_post);

private: 
  
};