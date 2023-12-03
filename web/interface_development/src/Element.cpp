#pragma once

#include "../include/Element.hpp"
#include "../include/Style.hpp"
#include <list>

namespace cwi{

void Element::add_style(cwi::Style style){
    _styles.push_back(style);
}

std::string Element::name() const{
    return _name;
}

std::list<cwi::Style> Element::styles() const{
    return _styles;
}

}