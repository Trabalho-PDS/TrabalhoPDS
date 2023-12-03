#pragma once

#include "../include/Form.hpp"
#include "../include/Style.hpp"
#include "../include/Div.hpp"
#include "../include/Element.hpp"
#include <cstdlib>
#include <string>
#include <list>

namespace cwi{

Form::Form(std::string name, std::string action, std::string method) : Div(name){
    _type = "form";
    _namesubmit = "enter";
    _submit = "<input id=\"enter\" type=\"submit\" value=\"Enter\">";
    _property = "<form id=\"" + name + "\" action=\"" + action + "\" method=\"" + method + "\">";
    _name = name;
    _submit_element = new Submit(_namesubmit, _submit);
    _elements.push_back(_submit_element);
}

Form::~Form(){
    std::free(_submit_element);
}

void Form::submit(std::string name, std::string value){
    _namesubmit = name;
    _submit = "<input id=\"" + name + "\" type=\"submit\" value=\"" + value +"\">";
    std::free(_submit_element);
    _submit_element = new Submit(_namesubmit, _submit);
    for(auto it : _stylesubimit){
        (*_submit_element).add_style(it);
    }
}

void Form::submit_style(cwi::Style style){
    _stylesubimit.push_back(style);
    (*_submit_element).add_style(style);
}

void Form::insert(cwi::Element *element){
    _elements.insert(_elements.begin(), element);
}

std::string Form::get_submit(){
    return _submit;
}

std::string Form::property() const{
    return _property;
}

std::list<cwi::Style> Form::styles_submit(){
    return (*_submit_element).styles();
}

Form::Submit::Submit(std::string name, std::string property){
    _name = name;
    _property = property;
}

std::string Form::Submit::property(){
    return _property;
}

}