#pragma once

#include "Element.hpp"
#include <string>

namespace cwi{

class Button : public Element{
    public:
        Button(std::string name, std::string value, std::string onclick);
        std::string property();

    private:
        std::string _property;
};

}