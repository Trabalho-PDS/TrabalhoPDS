#pragma once

#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>

class RepositorioUsuarios {
public:
  /**
  * @brief Realiza o processo concreto da criação de um usuario no banco de dados.
  * @param email, senha, nome_completo, tipo, id_usuario: email, senha, nome_completo, tipo, id_usuario.
  * @retval none.
  * */
  void criar_usuario(const std::string email, const std::string senha,  std::string const nome_completo, const std::string tipo, std::string id_usuario = "default");
  /**
  * @brief Realiza o processo concreto da remoção de um usuario no banco de dados.
  * @param id_usuario: id do usuario.
  * @retval none.
  * */
  void remover_usuario(std::string id_usuario);
  /**
  * @brief Realiza a busca dos dados no banco, e verifica a vericidade das informações, retornando true se os dados existirem.
  * @param email, senha: email, senha.
  * @retval bool
  * */
  bool autenticar_login(std::string email, std::string senha);
  /**
  * @brief Busca um id relacionado a um determinado email no banco de dados, e o retorna.
  * @param email: email.
  * @retval std::string
  * */
  std::string identidade_usuario(std::string email);
  /**
  * @brief Busca os dados de um usuario no banco de dados e os retorna.
  * @param idUsuario: id do usuario.
  * @retval none.
  * */
  std::string dados_usuario(const std::string idUsuario);
private: 
  //std::string _currentPath = std::filesystem::current_path().string();
  std::string _authkeysPath = "../storage/authkeys.txt";
  std::string _filePath = "../storage/usuario.txt";
};