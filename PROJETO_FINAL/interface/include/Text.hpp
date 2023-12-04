#pragma once

#include "Element.hpp"
#include <string>

namespace cwi{

class Text : public Element{
    public:
        Text(std::string type, std::string name, std::string message);
        std::string property();

    private:
        std::string _property;
};

}