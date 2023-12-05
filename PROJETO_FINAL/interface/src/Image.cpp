#pragma once

#include "../include/Image.hpp"
#include "../include/Element.hpp"
#include <string>

namespace cwi{

Image::Image(std::string name, std::string locate, std::string description){
    _name = name;
    _property = "<img id=\"" + name + "\" " + "src=\"" + locate + "\" " + "alt=\"" + description + "\">"; 
}

std::string Image::property(){
    return _property;
}

}