#pragma once

#include "Element.hpp"
#include <string>

namespace cwi{

class Image : public Element{
    public:
        Image(std::string name, std::string locate, std::string description);
        std::string property();

    private:
        std::string _property;
};

}