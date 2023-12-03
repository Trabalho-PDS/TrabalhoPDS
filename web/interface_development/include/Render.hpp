#pragma once

#include "Div.hpp"
#include "Element.hpp"
#include "Style.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

namespace cwi{

class Render{
    public:
        Render(std::string name);
        Render(std::list<cwi::Div *> divs_render);
        
        void insert(cwi::Div *div);

        void add_style(cwi::Style style);  
        std::list<cwi::Style> styles();

        void insert_head(std::string confg);
        
        void compile();
        void generate_html(std::string name_file);

    private:
        void read_div(cwi::Div *div, int inden_count);
        void read_styles(std::string id_element, std::list<cwi::Style> styles);

        std::list<cwi::Div *> _divs_render;
        std::list<std::string> _page_compiled;

        std::list<std::string> _head;
        std::list<std::string> _styles_render;

        std::list<cwi::Style> _styles;

};

}