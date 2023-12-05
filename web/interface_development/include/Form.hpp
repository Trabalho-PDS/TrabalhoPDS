#pragma once

#include "Style.hpp"
#include "Div.hpp"
#include "Element.hpp"
#include <cstdlib>
#include <string>
#include <list>

namespace cwi{

class Form : public Div{
    public:
        Form(std::string name, std::string action, std::string method);
        ~Form();
        void submit(std::string name, std::string value);
        void submit_style(cwi::Style style);
        void insert(cwi::Element *element);
        std::string get_submit();
        std::string property() const;
        std::list<cwi::Style> styles_submit();

    private:
        class Submit : public Element{
            public:
                Submit(std::string name, std::string property);
                std::string property();
            private:
                std::string _property;
        };

        std::string _property;
        std::string _namesubmit;
        std::string _submit;
        std::list<cwi::Style> _stylesubimit;
        Submit *_submit_element;

};

}