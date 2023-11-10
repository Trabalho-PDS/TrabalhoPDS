#pragma once

#include <string>
#include <filesystem>
#include <fstream>

class RepositorioUsuarios {
public:
  void criar_usuario(const std::string email, const std::string senha, const std::string tipo, std::string id_usuario = "default");

  void remover_usuario(std::string id_usuario);

  bool autenticar_login(std::string email, std::string senha);

  void editar_usuarios(std::string id_usuario, const std::string novo_email, const std::string nova_senha, const std::string tipo);

private: 
  std::string currentPath = std::filesystem::current_path().string();
  std::string filePath = currentPath + "/src/storage/DB/usuario.txt";
};