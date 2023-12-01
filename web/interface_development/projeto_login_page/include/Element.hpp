#pragma once

#include "Style.hpp"
#include <string>
#include <list>

namespace cwi{

class Element{
    public:
        void add_style(cwi::Style style);
        std::string name() const;
        std::list<cwi::Style> styles() const;
        virtual std::string property() = 0;

    protected:
        std::string _name;
        std::list<cwi::Style> _styles;
};

}
