#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include "user.hpp"
#include "gerenciar_posts.hpp"

class Student : public User, public GerenciarPosts {
    public:
        /**
        * @brief Construtor da classe Student.
        * @param id_user, email, name, type: id_user, email, name, type.
        * @retval none.
        * */
        Student(std::string id_user, std::string email, std::string name, std::string type);
        /**
        * @brief Retorna o tipo do usuario.
        * @retval std::string
        * */
        std::string Type();

    private:
        std::string _type;
};
