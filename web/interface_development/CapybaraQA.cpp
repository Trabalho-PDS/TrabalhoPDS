#include "CWI/Capybara.hpp"

int main(){
    
    cwi::Style sty_body;
    sty_body.padding(0);
    sty_body.margin(0);

    cwi::Style sty_principal;
    sty_principal.display("flex");
    sty_principal.flex(1);
    sty_principal.flex_wrap("wrap");
    sty_principal.margin(7, "%", "right");
    sty_principal.margin(7, "%", "left");
    sty_principal.margin(5, "%", "top");
    sty_principal.margin(2, "%", "bottom");
    sty_principal.height(110, "%");
    sty_principal.width("auto");
    sty_principal.border_radius(15);
    sty_principal.background_color("black");

    cwi::Style sty_right_div;
    sty_right_div.margin("right");
    sty_right_div.margin("left");
    sty_right_div.margin(2, "%", "top");
    sty_right_div.margin("bottom");
    sty_right_div.border_radius(15);
    sty_right_div.background_color("#565656");
    sty_right_div.height(80, "%");
    sty_right_div.width(76, "%");

    cwi::Style sty_middle_div;
    sty_middle_div.margin("right");
    sty_middle_div.margin(2, "%", "top");
    sty_middle_div.margin("bottom");
    sty_middle_div.border_radius(15);
    sty_middle_div.background_color("#565656");
    sty_middle_div.height(80, "%");
    sty_middle_div.width(20,"%");

    cwi::Style sty_search;
    sty_search.margin("left");
    sty_search.margin("right");
    sty_search.margin("top");
    sty_search.width(97, "%");
    sty_search.height(8, "%");
    sty_search.border_radius(25);
    sty_search.background_color("#565656");

    cwi::Div principal("principal");
    cwi::Div right_div("right");
    cwi::Div middle_div("middle");

    cwi::Div data_user("data_user");
    cwi::Div filters("filters");
    
    cwi::Div search("search");
    
    cwi::Div time_line("time_line");
    cwi::Div create_post("create_post");

    principal.child(&search);
    principal.child(&right_div);
    principal.child(&middle_div);

    principal.add_style(sty_principal);
    right_div.add_style(sty_right_div);
    middle_div.add_style(sty_middle_div);
    search.add_style(sty_search);

    cwi::Render render1("teste");
    render1.add_style(sty_body);
    render1.insert(&principal);

    render1.generate_html("teste.html");

    return 0;
}