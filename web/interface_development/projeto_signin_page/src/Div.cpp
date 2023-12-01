#pragma once

#include "../include/Element.hpp"
#include "../include/Div.hpp"
#include <string>
#include <vector>

namespace cwi{

Div::Div(std::string name){
    _name = name;
}

void Div::insert(cwi::Element *element){
    _elements.push_back(element);
}

void Div::child(Div *child){
    _children.push_back(child);
}

void Div::add_style(cwi::Style style){
    _styles.push_back(style);
}

std::string Div::type() const{
    return _type;
}

std::string Div::name() const{
    return _name;
}

std::string Div::property() const{
    return "none";
}


std::vector<cwi::Element *> Div::elements() const{
    return _elements;
}

std::vector<Div *> Div::children() const{
    return _children;
}

std::list<cwi::Style> Div::styles() const{
    return _styles;
}

}

