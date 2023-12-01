
#include "../include/Capybara.hpp"

#include "../include/user.hpp"
#include "../include/user_student.hpp"
#include "../include/user_monitor.hpp"
#include "../include/repositorio_usuarios.hpp"

#include <map>
#include <vector>
#include <fstream>

std::string EXE_FILE_NAME = "main_page.out";

int main(int argc, char **argv, char **envp){

    std::string query_msg;
    std::string ip_user_log;
    query_msg = std::getenv("QUERY_STRING");
    ip_user_log = std::getenv("REMOTE_ADDR");
    
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

    User *user = new Student();
    RepositorioUsuarios users_repo;

    if(options["input_type"] == "Aluno"){
        if(users_repo.autenticar_login(options["input_email"], options["input_pass"])){
            std::string id_user = users_repo.identidade_usuario(options["input_email"], options["input_pass"]);
            std::vector<std::string> login_infos;
            std::string aux_string;
            for(int i = 0; i <= (users_repo.dados_usuario(id_user).length()+1); i++){
                if(users_repo.dados_usuario(id_user)[i] != ' ' && users_repo.dados_usuario(id_user).length() != i){
                    aux_string += users_repo.dados_usuario(id_user)[i];
                    continue;
                }
                login_infos.push_back(aux_string);
                aux_string = "";
            }
        
            std::ofstream log_file("logs/" + ip_user_log + ".txt", std::ios::out);
        
            if(!log_file){
                return 0;
            }
        
            log_file << "Aluno" << std::endl;
            log_file << login_infos[0] << std::endl;
            log_file << login_infos[2] << std::endl;
            log_file << login_infos[0] << std::endl;
            log_file << id_user << std::endl;

            log_file.close();
        
            user = new Student(login_infos[0], login_infos[2], login_infos[0], id_user);
        
        }else{
            return 0;
        }
    }
    else if(options["input_type"] == "Monitor"){
        if(users_repo.autenticar_login(options["input_email"], options["input_pass"])){
            std::string id_user = users_repo.identidade_usuario(options["input_email"], options["input_pass"]);
            std::vector<std::string> login_infos;
            std::string aux_string;
            for(int i = 0; i <= (users_repo.dados_usuario(id_user).length()+1); i++){
                if(users_repo.dados_usuario(id_user)[i] != ' ' && users_repo.dados_usuario(id_user).length() != i){
                    aux_string += users_repo.dados_usuario(id_user)[i];
                    continue;
                }
                login_infos.push_back(aux_string);
                aux_string = "";
            }
        
            std::ofstream log_file("logs/" + ip_user_log + ".txt", std::ios::out);
        
            if(!log_file){
                return 0;
            }
        
            log_file << "Monitor" << std::endl;
            log_file << login_infos[0] << std::endl;
            log_file << login_infos[2] << std::endl;
            log_file << login_infos[0] << std::endl;
            log_file << id_user << std::endl;

            log_file.close();
        
            user = new Monitor(login_infos[0], login_infos[2], login_infos[0], id_user);
        
        }else{
            return 0;
        }
    }else{
        std::ifstream log_file("logs/" + ip_user_log + ".txt", std::ios::in);
        
        if(!log_file){
            return 0;
        }

        std::string rd_line;
        std::vector<std::string> log_infos;

        while(std::getline(log_file, rd_line)){
            log_infos.push_back(rd_line);
        }
        
        if(log_infos[0] == "Aluno"){
            user = new Student(log_infos[1], log_infos[2], log_infos[3], log_infos[4]);
        }else{
            user = new Monitor(log_infos[1], log_infos[2], log_infos[3], log_infos[4]);
        }
    }
    
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
    sty_data_users.display("flex");
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

    cwi::Div principal("principal");
    cwi::Div right_div("right");
    cwi::Div middle_div("middle");

    cwi::Div data_user("data_user");
    cwi::Div filters("filters");
    cwi::Div create_post("create_post_button");

    cwi::Div search("search");
    cwi::Form form_search("form_search", EXE_FILE_NAME, "post");
    
    cwi::Div time_line("time_line");

    cwi::Div post_base("post");

    cwi::TextBox input_search("input_search", "Pesquisar");

    cwi::Form button_create_post("btn_create_post", EXE_FILE_NAME + "?create=create_post", "post");

    cwi::Text text_create_new_post("h2", "txt_new_post", "NOVO POST!");
    cwi::TextBox input_title_new_post("input_title_new_post", "Titulo");
    cwi::TextBox input_body_new_post("input_body_new_post", "Questão");
    cwi::Form form_new_post("form_new_post", EXE_FILE_NAME, "get");

    cwi::Text user_name("h4", "user_name", user->Name());

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

    form_search.insert(&input_search);

    create_post.child(&button_create_post);

    form_new_post.submit("submit_new_post", "PUBLICAR");
    form_new_post.insert(&input_body_new_post);
    form_new_post.insert(&input_title_new_post);

    principal.child(&search);
    principal.child(&middle_div);
    principal.child(&right_div);

    search.child(&form_search);

    data_user.insert(&user_name);

    right_div.child(&data_user);
    right_div.child(&filters);
    right_div.child(&create_post);

    if(options["create"] == "create_post"){
        middle_div.insert(&text_create_new_post);
        middle_div.child(&form_new_post);
    }else{
        middle_div.child(&post_base);
    }

    cwi::Render render_main_page("main_page");
    render_main_page.add_style(sty_body);
    render_main_page.insert(&principal);

    render_main_page.compile();

    return 0;
}