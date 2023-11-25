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

    cwi::Style sty_middle_div;
    sty_middle_div.margin("right");
    sty_middle_div.margin("left");
    sty_middle_div.margin(2, "%", "top");
    sty_middle_div.margin("bottom");
    sty_middle_div.border_radius(15);
    sty_middle_div.background_color("#565656");
    sty_middle_div.height(84, "%");
    sty_middle_div.width(76, "%");

    cwi::Style sty_right_div;
    sty_right_div.margin("right");
    sty_right_div.margin(2, "%", "top");
    sty_right_div.margin("bottom");
    sty_right_div.border_radius(15);
    sty_right_div.background_color("#565656");
    sty_right_div.height(84, "%");
    sty_right_div.width(20,"%");
    sty_right_div.display("block");

    cwi::Style sty_search;
    sty_search.display("flex");
    sty_search.margin("left");
    sty_search.margin("right");
    sty_search.margin("top");
    sty_search.width(97, "%");
    sty_search.height(6, "%");
    sty_search.border_radius(25);
    sty_search.background_color("#565656");

    cwi::Style sty_data_users;
    sty_data_users.border_radius(15);
    sty_data_users.height(25, "%");
    sty_data_users.width(100, "%");
    sty_data_users.background_color("white");

    cwi::Style sty_filters;
    sty_filters.border_radius(15);
    sty_filters.margin(5, "%", "top");
    sty_filters.height(60, "%");
    sty_filters.width(100, "%");
    sty_filters.background_color("white");

    cwi::Style sty_create_post_button;
    sty_create_post_button.border_radius(25);
    sty_create_post_button.margin(5, "%", "top");
    sty_create_post_button.height(10, "%");
    sty_create_post_button.width(100, "%");
    sty_create_post_button.background_color("white");

    cwi::Style sty_form_search;
    sty_form_search.height(100, "%");
    sty_form_search.width(100, "%");
    
    cwi::Style sty_input_search;
    sty_input_search.border_radius(25);
    sty_input_search.height(100, "%");
    sty_input_search.width(90, "%");

    cwi::Style sty_enter_search;
    sty_enter_search.border_radius(25);
    sty_enter_search.height(100, "%");
    sty_enter_search.width(9, "%");

    //-----------------------------------------------------------------------//
    cwi::Div principal("principal");
    cwi::Div right_div("right");
    cwi::Div middle_div("middle");

    cwi::Div data_user("data_user");
    cwi::Div filters("filters");
    cwi::Div create_post_button("create_post_button");

    cwi::Div search("search");
    cwi::Form form_search("form_search", "teste.html", "get");
    
    cwi::Div time_line("time_line");
    cwi::Div create_post("create_post");

    //-----------------------------------------------------------------------//
    cwi::TextBox input_search("input_search", "Pesquisar");

    //-----------------------------------------------------------------------//
    input_search.add_style(sty_input_search);
    form_search.add_style(sty_form_search);
    form_search.submit_style(sty_enter_search);
    form_search.insert(&input_search);

    search.child(&form_search);

    principal.child(&search);
    principal.child(&middle_div);
    principal.child(&right_div);

    right_div.child(&data_user);
    right_div.child(&filters);
    right_div.child(&create_post_button);

    data_user.add_style(sty_data_users);
    filters.add_style(sty_filters);
    create_post_button.add_style(sty_create_post_button);

    principal.add_style(sty_principal);
    right_div.add_style(sty_right_div);
    middle_div.add_style(sty_middle_div);
    search.add_style(sty_search);

    //-----------------------------------------------------------------------//
    cwi::Render render1("teste");
    render1.add_style(sty_body);
    render1.insert(&principal);

    render1.generate_html("teste.html");

    return 0;
}