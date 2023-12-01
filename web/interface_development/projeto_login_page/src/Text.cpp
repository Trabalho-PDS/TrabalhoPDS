#pragma once

#include "../include/Text.hpp"
#include "../include/Element.hpp"
#include <string>

namespace cwi{

Text::Text(std::string type, std::string name, std::string message){
    _name = name;
    _property = "<" + type + " id=\"" + name + "\">" + message + "</" + type + ">";
}

std::string Text::property(){
    return _property;
}

}