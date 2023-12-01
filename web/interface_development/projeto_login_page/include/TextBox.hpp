#pragma once

#include "Element.hpp"
#include <string>

namespace cwi{

class TextBox : public Element{
    public:
        TextBox(std::string name, std::string placeholder);
        std::string property();
        
    private:
        std::string _property;
};

}