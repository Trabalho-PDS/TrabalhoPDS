#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include "user.hpp"
#include "gerenciar_posts.hpp"

class Monitor : public User, public GerenciarPosts {
    public:
        Monitor();

        void choseFields(std::string field);
        void calculateStars(int newEvaluation);

        void seeFields();
        double seeStars();

    private:
        std::vector <std::string> _fields;
        int _numberOfEvaluations;
        double _starRange;
};
