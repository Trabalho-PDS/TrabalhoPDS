#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include "user.hpp"
#include "gerenciar_posts.hpp"

class Student : public User, public GerenciarPosts {
    public:
        //Construtor
        Student(std::string id_user, std::string email, std::string name, std::string type);
        
        //Implementação do metodo virtual herdado;
        std::string Type();

    private:
        std::string _type;
};
