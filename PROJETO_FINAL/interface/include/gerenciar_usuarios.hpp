#pragma once

#include "repositorio_usuarios.hpp"
#include "repositorio_posts.hpp"
#include "post.hpp"
#include "user.hpp"

#include <vector>

class Gerenciar_usuarios : public RepositorioUsuarios, RepositorioPosts{
    public:
        //Cria um novo usuario, retorna verdadeiro se o usuario for criado com sucesso;
        bool create_user(const std::string email, const std::string senha,  std::string const nome_completo, const std::string tipo);
        
        //Remove um usuario;
        void remove_user(std::string id_usuario);
        
        //Autentica um usuario, retorna verdadeiro se o mesmo existir;
        bool authenticate_user(std::string email, std::string senha);

        //Encontra um usuario especifico, cria o seu respectivo objeto, e retorna um ponteiro para o mesmo;
        User* find_user(std::string email);

        //Edita as informações de um usuario;
        void edit_user(std::string id_usuario, const std::string email, const std::string senha,  std::string const nome_completo, const std::string tipo);
        
        //Retorna um vetor com todos os posts já feitos por determinado usuario;
        std::vector<std::string> get_posts(std::string id_usuario);
};
