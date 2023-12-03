#pragma once

#include "../include/TextBox.hpp"
#include "../include/Element.hpp"
#include <string>

namespace cwi{

TextBox::TextBox(std::string name, std::string placeholder){
    _name = name;
    _property = "<input id=\"" + name + "\" " + "type=\"text\" name=\"" + name + "\" " + "placeholder=\"" + placeholder + "\">";
}

std::string TextBox::property(){
    return _property;
}

}