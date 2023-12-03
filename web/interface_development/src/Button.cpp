#pragma once

#include "../include/Button.hpp"
#include "../include/Element.hpp"
#include <string>

namespace cwi{

Button::Button(std::string name, std::string value, std::string onclick){
    _name = name;
    _property = "<button id=\"" + name + "\" onclick=\"" + onclick + "\">" + value + "</button>";
}

std::string Button::property(){
    return _property;
}

}