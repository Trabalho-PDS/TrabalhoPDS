
#include "CWI/Capybara.hpp"
#include <iostream>
#include <map>

int main(int argc, char **argv, char **envp){
    
    std::string query_msg;
    query_msg = std::getenv("QUERY_STRING");

    std::string buffer_option;
    std::string buffer_param;
    std::map<std::string, std::string> options;

    for(int i = 0; query_msg[i] != '\0'; i++){
        if(query_msg[i] != '='){
            buffer_option = buffer_option + query_msg[i];
        }
        else{
            i++;
            for(; query_msg[i] != '&' && query_msg[i] != '\0'; i++){
                if(query_msg[i] == '-'){
                    buffer_param = buffer_param + " ";
                }else{
                    buffer_param = buffer_param + query_msg[i];
                }
            }
            options[buffer_option] = buffer_param;
            buffer_option = "";
            buffer_param = "";
        }
    }

    //-----------------------------------------------------------------------//
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

    cwi::Style sty_create_post;
    sty_create_post.border_radius(25);
    sty_create_post.margin(5, "%", "top");
    sty_create_post.height(10, "%");
    sty_create_post.width(100, "%");
    sty_create_post.background_color("white");

    cwi::Style sty_create_post_button;
    sty_create_post_button.height(100, "%");
    sty_create_post_button.width(100, "%");
    sty_create_post_button.border_radius(25);

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

    cwi::Style sty_post_base;
    sty_post_base.width(98, "%");
    sty_post_base.height(20, "%");
    sty_post_base.margin("left");
    sty_post_base.margin("right");
    sty_post_base.margin(1, "%", "top");
    sty_post_base.border_radius(15);
    sty_post_base.background_color("#90EE90");

    cwi::Style sty_form_new_post;
    sty_form_new_post.display("block");
    sty_form_new_post.width(98, "%");
    sty_form_new_post.height(70, "%");
    sty_form_new_post.margin("left");
    sty_form_new_post.margin("right");

    cwi::Style sty_input_title_new_post;
    sty_input_title_new_post.display("inline");
    sty_input_title_new_post.width(100, "%");
    sty_input_title_new_post.height(10, "%");
    sty_input_title_new_post.border_radius(25);

    cwi::Style sty_input_body_new_post;
    sty_input_body_new_post.display("inline");
    sty_input_body_new_post.width(100, "%");
    sty_input_body_new_post.height(80, "%");
    sty_input_body_new_post.border_radius(15);

    cwi::Style sty_submit_new_post;
    sty_submit_new_post.width(20, "%");
    sty_submit_new_post.height(10, "%");
    sty_submit_new_post.margin(80, "%", "left");
    sty_submit_new_post.margin(2, "%", "top");
    sty_submit_new_post.border_radius(25);

    //-----------------------------------------------------------------------//
    cwi::Style sty_part_login;
    sty_part_login.width(50, "%");
    sty_part_login.height(100, "%");
    sty_part_login.background_color("#0b0b64");
    sty_part_login.border_radius(15);

    cwi::Style sty_part_info;
    sty_part_info.width(50, "%");
    sty_part_info.height(100, "%");
    sty_part_info.background_color("#11119c");
    sty_part_info.border_radius(15);

    cwi::Style sty_form_login;
    sty_form_login.width(60, "%");
    sty_form_login.height(70, "%");
    sty_form_login.margin("left");
    sty_form_login.margin("right");
    sty_form_login.margin(30, "%", "top");

    cwi::Style sty_inputs_login;
    sty_inputs_login.margin(3);
    sty_inputs_login.width(100, "%");
    sty_inputs_login.height(15, "%");
    sty_inputs_login.border_radius(15);

    //-----------------------------------------------------------------------//
    cwi::Div principal("principal");
    cwi::Div right_div("right");
    cwi::Div middle_div("middle");

    cwi::Div data_user("data_user");
    cwi::Div filters("filters");
    cwi::Div create_post("create_post_button");

    cwi::Div search("search");
    cwi::Form form_search("form_search", "teste.out?is_login=1", "post");
    
    cwi::Div time_line("time_line");

    cwi::Div post_base("post");
    
    //-----------------------------------------------------------------------//
    cwi::Div part_login("part_login");
    cwi::Div part_info("part_info");

    cwi::Form form_login("form_login", "teste.out", "get");
    cwi::TextBox input_email("input_email", "Email");
    cwi::TextBox input_passaword("input_pass", "Senha");

    //-----------------------------------------------------------------------//
    cwi::TextBox input_search("input_search", "Pesquisar");

    cwi::Form button_create_post("btn_create_post", "teste.out?create=create_post&is_login=1", "post");

    cwi::Text text_create_new_post("h2", "txt_new_post", "NOVO POST!");
    cwi::TextBox input_title_new_post("input_title_new_post", "Titulo");
    cwi::TextBox input_body_new_post("input_body_new_post", "Questão");
    cwi::Form form_new_post("form_new_post", "teste.out", "get");

    //-----------------------------------------------------------------------//
    part_login.add_style(sty_part_login);
    part_info.add_style(sty_part_info);
    form_login.add_style(sty_form_login);
    form_login.submit_style(sty_inputs_login);
    input_email.add_style(sty_inputs_login);
    input_passaword.add_style(sty_inputs_login);

    //-----------------------------------------------------------------------//
    form_search.insert(&input_search);

    create_post.child(&button_create_post);

    form_new_post.submit("submit_new_post", "PUBLICAR");
    form_new_post.insert(&input_body_new_post);
    form_new_post.insert(&input_title_new_post);

    form_login.insert(&input_passaword);
    form_login.insert(&input_email);
    form_login.submit("submit_login", "ENTRAR");

    //-----------------------------------------------------------------------//
    if(options["input_email"] == "lucas" && options["input_pass"] == "1234"){
        options["is_login"] = "1";
    }

    if(options["is_login"] == "1"){
        principal.child(&search);
        principal.child(&middle_div);
        principal.child(&right_div);
    }else{
        principal.child(&part_info);
        principal.child(&part_login);
    }

    part_login.child(&form_login);

    right_div.child(&data_user);
    right_div.child(&filters);
    right_div.child(&create_post);

    if(options["create"] == "create_post"){
        middle_div.insert(&text_create_new_post);
        middle_div.child(&form_new_post);
    }else{
        middle_div.child(&post_base);
    }

    search.child(&form_search);

    //-----------------------------------------------------------------------//
    input_search.add_style(sty_input_search);
    form_search.add_style(sty_form_search);
    form_search.submit_style(sty_enter_search);

    data_user.add_style(sty_data_users);
    filters.add_style(sty_filters);
    create_post.add_style(sty_create_post);

    principal.add_style(sty_principal);
    right_div.add_style(sty_right_div);
    middle_div.add_style(sty_middle_div);
    search.add_style(sty_search);

    post_base.add_style(sty_post_base);

    button_create_post.submit("create", "NOVO POST +");
    button_create_post.submit_style(sty_create_post_button);
    button_create_post.add_style(sty_create_post_button);

    form_new_post.add_style(sty_form_new_post);
    form_new_post.submit_style(sty_submit_new_post);
    input_body_new_post.add_style(sty_input_body_new_post);
    input_title_new_post.add_style(sty_input_title_new_post);

    //-----------------------------------------------------------------------//
    cwi::Render render1("teste");
    render1.add_style(sty_body);
    render1.insert(&principal);

    render1.compile();

    return 0;
}