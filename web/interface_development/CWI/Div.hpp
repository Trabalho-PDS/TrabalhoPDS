#pragma once

#include "Element.hpp"
#include "Style.hpp"
#include <string>
#include <vector>

namespace cwi{

class Div{
    public:
        Div(std::string name);
        virtual void insert(cwi::Element *element);
        void child(Div *child);
        void add_style(cwi::Style style);
        std::string type() const;
        std::string name() const;
        virtual std::string property() const;
        std::vector<cwi::Element *> elements() const;
        std::vector<Div *> children() const;
        std::list<cwi::Style> styles() const;

    protected:
        std::string _type = "common";
        std::string _name;
        std::vector<cwi::Element *> _elements;
        std::vector<Div *> _children;
        std::list<cwi::Style> _styles;
};

}