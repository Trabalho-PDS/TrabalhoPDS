#pragma once

#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>

class RepositorioUsuarios {
public:
  void criar_usuario(const std::string email, const std::string senha, const std::string tipo, std::string id_usuario = "default");

  void remover_usuario(std::string id_usuario);

  bool autenticar_login(std::string email, std::string senha);

  void editar_usuarios(std::string id_usuario, const std::string novo_email, const std::string nova_senha, const std::string tipo);

  std::string identidade_usuario(std::string email,std::string senha);

  std::string dados_usuario(const std::string idUsuario);
private: 
  std::string _currentPath = std::filesystem::current_path().string();
  std::string _filePath = _currentPath + "/storage/usuario.txt";
};