#pragma once

#include "../include/Render.hpp"
#include "../include/Div.hpp"
#include "../include/Element.hpp"
#include "../include/Style.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

namespace cwi{

Render::Render(std::string name){
    _head.push_back("<html lang=\"en\">");
    _head.push_back("<head>");
    _head.push_back("    <meta charset=\"UTF-8\">");
    _head.push_back("    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">");
    _head.push_back("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    _head.push_back("    <title>" + name + "</title>");
    _head.push_back("    <style>");
}

Render::Render(std::list<cwi::Div *> divs_render) : Render::Render("none"){
    _divs_render = divs_render;
}

void Render::insert(cwi::Div *div){
    _divs_render.push_back(div);
}

void Render::add_style(cwi::Style style){
    _styles.push_back(style);
}

std::list<cwi::Style> Render::styles(){
    return _styles;
}

void Render::insert_head(std::string config){
    for(std::list<std::string>::iterator it = _head.begin(); it != _head.end(); it++){
        if(*it == "    <style>"){
            _head.insert(it, config);
            break;
        }
    }
}


void Render::read_styles(std::string name, std::list<cwi::Style> styles){
    bool is_list = false;
    for(auto it : _styles_render){
        if("\t\t#" + name + "{" == it){
            is_list = true;
            break;
        }
    }
    if(!is_list){
        _styles_render.push_back("\t\t#" + name + "{");
        for(auto it : styles){
            for(auto it_propertys : it.property()){
                _styles_render.push_back("\t\t\t" + it_propertys);
            }
        }
        _styles_render.push_back("\t\t}");
    }
}

void Render::read_div(cwi::Div *div, int inden_count){

    if(!(div->styles()).empty()){
        read_styles(div->name(), div->styles());
    }

    std::string tabs(inden_count, '\t');

    if(div->type() == "common"){
        _page_compiled.push_back(tabs + "<div id=\"" + div->name() + "\">");
        for(auto it : div->elements()){
            _page_compiled.push_back(tabs + '\t' + (it)->property());
            if(!((it)->styles()).empty()){
                read_styles((it)->name(), (it)->styles());
            }
        }
        for(auto it : div->children()){
            read_div(it, 1 + inden_count);
        }
        _page_compiled.push_back(tabs + "</div>");
    }
    else if(div->type() == "form"){
        _page_compiled.push_back(tabs + div->property());
        for(auto it : div->elements()){
            _page_compiled.push_back(tabs + '\t' + (it)->property());
            if(!((it)->styles()).empty()){
                read_styles((it)->name(), (it)->styles());
            }
        }
        for(auto it : div->children()){
            read_div(it, 1 + inden_count);
        }
        _page_compiled.push_back(tabs + "</form>");
    }
    
}

void Render::compile(){

    _page_compiled = _head;
    _styles_render.erase(_styles_render.begin(), _styles_render.end());

    _page_compiled.push_back("    </style>");
    _page_compiled.push_back("</head>");
    _page_compiled.push_back("<body id=\"main\">");

    if(!_styles.empty()){
        read_styles("main", _styles);
    }
    
    for(auto it : _divs_render){
        read_div(it, 0);
    }

    for(std::list<std::string>::iterator it = _page_compiled.begin(); it != _page_compiled.end(); it++){
        if(*it == "    </style>"){
            for(auto it_styles : _styles_render){
                _page_compiled.insert(it, it_styles);
            }
            break;
        }
    }

    _page_compiled.push_back("</body>");

    std::cout << "Content-type: text/html" << std::endl << std::endl;
    for(auto it : _page_compiled){
        std::cout << (it) << std::endl;
    }

}

void Render::generate_html(std::string name_file){

    _page_compiled = _head;
    _styles_render.erase(_styles_render.begin(), _styles_render.end());


    _page_compiled.push_back("    </style>");
    _page_compiled.push_back("</head>");
    _page_compiled.push_back("<body id=\"main\">");

    if(!_styles.empty()){
        read_styles("main", _styles);
    }

    std::ofstream out_file;
    out_file.open(name_file, std::ios::out);

    for(auto it : _divs_render){
        read_div(it, 0);
    }

    for(std::list<std::string>::iterator it = _page_compiled.begin(); it != _page_compiled.end(); it++){
        if(*it == "    </style>"){
            for(auto it_styles : _styles_render){
                _page_compiled.insert(it, it_styles);
            }
            break;
        }
    }

    _page_compiled.push_back("</body>");

    for(auto it : _page_compiled){
        out_file << (it) << std::endl;
    }

    out_file.close();

}

}
