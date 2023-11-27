#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include "user.hpp"
#include "gerenciar_posts.hpp"

class Student : public User, public GerenciarPosts {
    public:

    private:
        std::vector <std::string> _subjectsInterests;
};
