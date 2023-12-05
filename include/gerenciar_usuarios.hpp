#pragma once

#include "repositorio_usuarios.hpp"
#include "repositorio_posts.hpp"
#include "post.hpp"
#include "user.hpp"

#include <vector>

class Gerenciar_usuarios : public RepositorioUsuarios, RepositorioPosts{
    public:
        /**
        * @brief Cria um novo usuario, retorna verdadeiro se o usuario for criado com sucesso.
        * @param email, senha, nome_completo, tipo: email, senha, nome completo, tipo.
        * @retval bool
        * */
        bool create_user(const std::string email, const std::string senha,  std::string const nome_completo, const std::string tipo);
        /**
        * @brief Remove um usuario.
        * @param id_usuario: id de um usuario.
        * @retval none.
        * */
        void remove_user(std::string id_usuario);
        /**
        * @brief Autentica um usuario, retorna verdadeiro se o mesmo existir.
        * @param email, senha: email, senha.
        * @retval none.
        * */
        bool authenticate_user(std::string email, std::string senha);
        /**
        * @brief Encontra um usuario especifico, cria o seu respectivo objeto, e retorna um ponteiro para o mesmo.
        * @param email: email.
        * @retval User*
        * */
        User* find_user(std::string email);
        /**
        * @brief Edita as informações de um usuario.
        * @param id_usuario, email, senha, nome_completo, tipo: id_usuario, email, senha, nome_completo.
        * @retval none.
        * */
        void edit_user(std::string id_usuario, const std::string email, const std::string senha,  std::string const nome_completo, const std::string tipo);
        /**
        * @brief Retorna um vetor com todos os posts já feitos por determinado usuario.
        * @param id_usuario: id do usuario.
        * @retval std::vector<std::string>
        * */
        std::vector<std::string> get_posts(std::string id_usuario);
};
