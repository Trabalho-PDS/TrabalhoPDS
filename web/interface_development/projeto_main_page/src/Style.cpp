#pragma once

#include "../include/Style.hpp"
#include <string>
#include <list>

namespace cwi{

Style::Style(){};

void Style::font_family(std::string font){
    _style.push_back("font-family: " + font + ";");
}
void Style::font_size(int size, std::string unit){
    _style.push_back("font-size: " + std::to_string(size) + unit + ";");
}
void Style::font_weight(int size, std::string unit){
    _style.push_back("font-weight: " + std::to_string(size) + unit + ";");
}

void Style::padding(int size, std::string unit, std::string dir){
    if(dir == ""){
        _style.push_back("padding: " + std::to_string(size) + unit + ";");
    }else{
        _style.push_back("padding-" + dir + ": " + std::to_string(size) + unit + ";");
    }
}


void Style::margin(int size, std::string unit, std::string dir){
    if(dir == ""){
        _style.push_back("margin: " + std::to_string(size) + unit + ";");
    }else{
        _style.push_back("margin-" + dir + ": " + std::to_string(size) + unit + ";");
    }
}
void Style::margin(std::string dir, std::string type){
    if(dir == ""){
        _style.push_back("margin: " + type + ";");
    }else{
        _style.push_back("margin-" + dir + ": " + type + ";");
    }
}


void Style::border(int size, std::string type, std::string color){
    _style.push_back("border: " + std::to_string(size) + "px " + type + " " + color + ";");
}
void Style::border_radius(int radius){
    _style.push_back("border-radius: " + std::to_string(radius) + "px;");
}

void Style::height(int size, std::string unit){
    _style.push_back("height: " + std::to_string(size) + unit + ";");
}
void Style::width(int size, std::string unit){
    _style.push_back("width: " + std::to_string(size) + unit + ";");
}
void Style::width(std::string type){
    _style.push_back("width: " + type + ";");
}
void Style::height(std::string type){
    _style.push_back("height: " + type + ";");
}
void Style::max_width(int size, std::string unit){
    _style.push_back("max-width: " + std::to_string(size) + unit + ";");
}
void Style::max_height(int size, std::string unit){
    _style.push_back("max-height: " + std::to_string(size) + unit + ";");
}


void Style::color(std::string color){
    _style.push_back("color: " + color + ";");
}


void Style::background_color(std::string color){
    _style.push_back("background-color: " + color + ";");
}
void Style::background_image(std::string locate){
    _style.push_back("background-image: url(\"" + locate + "\");");
}
void Style::background_size(std::string config){
    _style.push_back("background-size: " + config + ";");
}
void Style::background_attachment(std::string mode){
    _style.push_back("background-image: " + mode + ";");
}
void Style::background_repeat(std::string mode){
    _style.push_back("background-image: " + mode + ";");
}


void Style::backdrop_filter(std::string config){
    _style.push_back("backdrop-filter: " + config + ";");   
}
void Style::filter(std::string config){
    _style.push_back("filter: " + config + ";");   
}


void Style::display(std::string type){
    _style.push_back("display: " + type + ";");
}


void Style::text_align(std::string type){
    _style.push_back("text-align: " + type + ";");
}


void Style::flex_wrap(std::string type){
    _style.push_back("flex-wrap: " + type + ";");
}
void Style::flex(int size){
    _style.push_back("flex: " + std::to_string(size) + ";");
}


std::list<std::string> Style::property(){
    return _style;
}

}
