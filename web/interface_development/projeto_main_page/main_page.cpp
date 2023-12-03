
#include "../include/Capybara.hpp"

#include "../include/user.hpp"
#include "../include/user_student.hpp"
#include "../include/user_monitor.hpp"
#include "../include/gerenciar_usuarios.hpp"

#include "../include/post.hpp"
#include "../include/gerenciar_posts.hpp"
#include "../include/repositorio_posts.hpp"

#include <map>
#include <vector>
#include <fstream>

std::string EXE_FILE_NAME = "main_page.out";

std::string string_treatment(std::string str){
    std::string aux_str;
    for(auto it : str){
        if(it == '+'){
            aux_str += ' ';
            continue;
        }
        aux_str += it;
    }
    return aux_str;
}

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

    User *user;
    Gerenciar_usuarios user_manage;

    if(options["input_email"] != "" && options["input_pass"] != "" && options["input_type"] != ""){
        if(user_manage.authenticate_user(options["input_email"], options["input_pass"])){
            
            user = user_manage.find_user(options["input_email"]);
        
            std::ofstream log_file("../logs/" + ip_user_log + ".txt", std::ios::out);
        
            if(!log_file){
                return 0;
            }
        
            log_file << user->Id() << std::endl;
            log_file << user->Email() << std::endl;
            log_file << user->Name() << std::endl;
            log_file << user->Type() << std::endl;

            log_file.close();
                
        }else{
            return 0;
        }
    }else{
        std::ifstream log_file("../logs/" + ip_user_log + ".txt", std::ios::in);
        
        if(!log_file){
            return 0;
        }

        std::string rd_line;
        std::vector<std::string> log_infos;

        while(std::getline(log_file, rd_line)){
            log_infos.push_back(rd_line);
        }
        
        if(log_infos[0] == "Aluno"){
            user = new Student(log_infos[0], log_infos[1], log_infos[2], log_infos[3]);
        }else{
            user = new Monitor(log_infos[0], log_infos[1], log_infos[2], log_infos[3]);
        }

        log_file.close();
    }

    if(options["input_title_new_post"] != "" && options["input_body_new_post"] != "" && options["input_theme_new_post"] != ""){
        options["input_theme_new_post"] = string_treatment(options["input_theme_new_post"]);
        options["input_body_new_post"] = string_treatment(options["input_body_new_post"]);
        options["input_title_new_post"] = string_treatment(options["input_title_new_post"]);

        Post new_post(options["input_theme_new_post"],
                      options["input_body_new_post"],
                      options["input_title_new_post"], user->Id());
        
        GerenciarPosts posts_manage;
        posts_manage.new_post(new_post);
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
    sty_post_base.height("auto");
    sty_post_base.margin("left");
    sty_post_base.margin("right");
    sty_post_base.margin(1, "%", "top");
    sty_post_base.border_radius(15);
    sty_post_base.background_color("#90EE90");

    cwi::Style sty_post_theme;
    sty_post_theme.display("inline-flex");
    sty_post_theme.font_size(15);
    sty_post_theme.margin(0);
    sty_post_theme.padding(2);
    sty_post_theme.color("blue");
    cwi::Style sty_post_title;
    sty_post_title.display("inline-flex");
    sty_post_title.margin(0);
    sty_post_title.padding(2);
    sty_post_title.font_size(20);
    cwi::Style sty_post_body;
    sty_post_body.display("flex");
    sty_post_body.margin(0);
    sty_post_body.padding(10);

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

    /*cwi::Div post_base("post");
    cwi::Text user_post("h2", "user_post", "lorem_ipsum");
    cwi::Text theme_post("h2", "theme_post", "lorem_ipsum");
    cwi::Text title_post("h2", "title_post", "lorem_ipsum");
    cwi::Text body_post("h2", "body_post", "lorem_ipsum");*/

    cwi::TextBox input_search("input_search", "Pesquisar");

    cwi::Form button_create_post("btn_create_post", EXE_FILE_NAME + "?create=create_post", "post");

    cwi::Text text_create_new_post("h2", "txt_new_post", "NOVO POST!");
    cwi::TextBox input_title_new_post("input_title_new_post", "Titulo");
    cwi::TextBox input_body_new_post("input_body_new_post", "Questão");
    cwi::TextBox input_theme_new_post("input_theme_new_post", "Materia");
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

    //post_base.add_style(sty_post_base);

    button_create_post.submit("create", "NOVO POST +");
    button_create_post.submit_style(sty_create_post_button);
    button_create_post.add_style(sty_create_post_button);

    form_new_post.add_style(sty_form_new_post);
    form_new_post.submit_style(sty_submit_new_post);
    input_body_new_post.add_style(sty_input_body_new_post);
    input_title_new_post.add_style(sty_input_title_new_post);
    input_theme_new_post.add_style(sty_input_title_new_post);

    form_search.insert(&input_search);

    create_post.child(&button_create_post);

    form_new_post.submit("submit_new_post", "PUBLICAR");
    form_new_post.insert(&input_body_new_post);
    form_new_post.insert(&input_title_new_post);
    form_new_post.insert(&input_theme_new_post);

    principal.child(&search);
    principal.child(&middle_div);
    principal.child(&right_div);

    search.child(&form_search);

    data_user.insert(&user_name);

    right_div.child(&data_user);
    right_div.child(&filters);
    right_div.child(&create_post);

    std::vector<cwi::Div*> main_posts;
    RepositorioPosts posts_repo;

    if(options["create"] == "create_post"){
        middle_div.insert(&text_create_new_post);
        middle_div.child(&form_new_post);
    }else{
        for(auto it : posts_repo.buscar_posts("")){
            std::vector<std::string> posts_properties;
            std::string delimiter = "$&n&$~~";
            size_t pos = 0;
            std::string token;
            while((pos = it.find(delimiter)) != std::string::npos){
                token = it.substr(0, pos);
                posts_properties.push_back(token);
                it.erase(0, pos + delimiter.length());
            }

            posts_properties.push_back(it);

            cwi::Div *post_base = new cwi::Div("post");
            cwi::Text *theme_post = new cwi::Text("h2", "theme_post", posts_properties[2]);
            cwi::Text *title_post = new cwi::Text("h2", "title_post", posts_properties[1]);
            cwi::Text *body_post = new cwi::Text("h2", "body_post", posts_properties[3]);
            post_base->insert(theme_post);
            post_base->insert(title_post);
            post_base->insert(body_post);
            post_base->add_style(sty_post_base);
            theme_post->add_style(sty_post_theme);
            title_post->add_style(sty_post_title);
            body_post->add_style(sty_post_body);
            main_posts.push_back(post_base);
        }

        for(auto it : main_posts){
            middle_div.child(it);
        }
    }

    cwi::Render render_main_page("main_page");
    render_main_page.add_style(sty_body);
    render_main_page.insert(&principal);

    render_main_page.compile();

    return 0;
}