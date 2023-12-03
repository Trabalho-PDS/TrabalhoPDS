#pragma once

#include "repositorio_usuarios.hpp"
#include "repositorio_posts.hpp"
#include "post.hpp"
#include "user.hpp"

#include <vector>

class Gerenciar_usuarios : public RepositorioUsuarios, RepositorioPosts{
    public:
        bool create_user(const std::string email, const std::string senha,  std::string const nome_completo, const std::string tipo);
        void remove_user(std::string id_usuario);
        bool authenticate_user(std::string email, std::string senha);
        User* find_user(std::string email);
        void edit_user(std::string id_usuario, const std::string email, const std::string senha,  std::string const nome_completo, const std::string tipo);
        std::vector<std::string> get_posts(std::string id_usuario);
};
