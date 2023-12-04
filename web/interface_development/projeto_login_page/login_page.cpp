#include "../include/Capybara.hpp"
#include <map>

std::string EXE_MAIN_FILE = "main_page.out";
std::string EXE_SIGNIN_FILE = "signin_page.out";
std::string EXE_CURRENT_FILE = "login_page.out";

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

    cwi::Style sty_body;
    sty_body.height(100, "%");
    sty_body.width(100, "%");
    sty_body.padding(0);
    sty_body.margin(0);
    sty_body.display("block");
    sty_body.flex(1);

    cwi::Style sty_part_login;
    sty_part_login.margin(10);
    sty_part_login.width(50, "%");
    sty_part_login.height(100, "%");
    sty_part_login.background_color("#0b0b64");
    sty_part_login.border_radius(15);

    cwi::Style sty_part_info;
    sty_part_info.margin(10);
    sty_part_info.width(50, "%");
    sty_part_info.height(100, "%");
    sty_part_info.background_color("#11119c");
    sty_part_info.border_radius(15);

    cwi::Style sty_form_login;
    sty_form_login.width(60, "%");
    sty_form_login.height(70, "%");
    sty_form_login.margin("left");
    sty_form_login.margin("right");
    sty_form_login.margin(20, "%", "top");

    cwi::Style sty_inputs_login;
    sty_inputs_login.margin(3);
    sty_inputs_login.width(100, "%");
    sty_inputs_login.height(15, "%");
    sty_inputs_login.border_radius(15);

    cwi::Style sty_buttons_options;
    sty_buttons_options.width("auto");
    sty_buttons_options.height("auto");

    cwi::Style sty_top;
    sty_top.margin(2, "%", "top");
    sty_top.height(5, "%");
    sty_top.width(100, "%");
    sty_top.display("inline-flex");
    sty_top.padding(90, "%", "left");

    cwi::Style sty_bottom;
    sty_bottom.height(90, "%");
    sty_bottom.width(100, "%");
    sty_bottom.display("flex");
    
    cwi::Div top("top");
    cwi::Div bottom("bottom");
    cwi::Div part_login("part_login");
    cwi::Div part_info("part_info");

    cwi::Form form_login("form_login", EXE_MAIN_FILE, "get");
    cwi::Form form_signin("form_signin", EXE_SIGNIN_FILE, "get");
    
    cwi::TextBox input_name("input_name", "Nome de Usuario:");
    cwi::TextBox input_email("input_email", "Email");
    cwi::TextBox input_passaword("input_pass", "Senha");
    cwi::TextBox input_type("input_type", "Realizar login como:");

    cwi::Form button_login("form_button_login", EXE_CURRENT_FILE + "?page=0", "post");
    button_login.submit("button_login", "LOGIN");
    cwi::Form button_signin("form_button_signin", EXE_CURRENT_FILE + "?page=1", "post");
    button_signin.submit("button_signin", "SIGNIN");

    top.add_style(sty_top);
    bottom.add_style(sty_bottom);
    part_login.add_style(sty_part_login);
    part_info.add_style(sty_part_info);
    form_login.add_style(sty_form_login);
    form_login.submit_style(sty_inputs_login);
    form_signin.add_style(sty_form_login);
    form_signin.submit_style(sty_inputs_login);
    input_name.add_style(sty_inputs_login);
    input_email.add_style(sty_inputs_login);
    input_passaword.add_style(sty_inputs_login);
    input_type.add_style(sty_inputs_login);
    button_login.add_style(sty_buttons_options);
    button_signin.add_style(sty_buttons_options);

    form_login.insert(&input_type);
    form_login.insert(&input_passaword);
    form_login.insert(&input_email);
    form_login.submit("submit_login", "ENTRAR");

    form_signin.insert(&input_type);
    form_signin.insert(&input_passaword);
    form_signin.insert(&input_email);
    form_signin.insert(&input_name);
    form_signin.submit("submit_login", "INSCREVER");

    if(options["page"] == "0" || options["page"].empty()){
        part_login.child(&form_login);
    }else if(options["page"] == "1"){
        part_login.child(&form_signin);
    }

    top.child(&button_login);
    top.child(&button_signin);

    bottom.child(&part_info);
    bottom.child(&part_login);

    cwi::Render render_login_page("login");
    render_login_page.add_style(sty_body);
    render_login_page.insert(&top);
    render_login_page.insert(&bottom);

    render_login_page.compile();

    std::cout << query_msg << std::endl;

    return 0;
}