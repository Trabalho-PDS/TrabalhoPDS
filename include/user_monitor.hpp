#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include "user.hpp"
#include "gerenciar_posts.hpp"

class Monitor : public User, public GerenciarPosts {
    public:
        Monitor();

        void calculateStars (int newGrade);

        double seeStars ();

    private:
        std::vector <std::string> _subjectsArea;
        int _numberOfEvaluations;
        double _starRange;
};