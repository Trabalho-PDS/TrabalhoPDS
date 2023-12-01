#include "../include/Capybara.hpp"

#include "../include/user.hpp"
#include "../include/repositorio_usuarios.hpp"

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

    RepositorioUsuarios users_repo;

    if(options["input_type"] == "Aluno" || options["input_type"] == "Monitor"){
        cwi::Div principal("principal");
        cwi::Text status("h1", "status", "CONTA CRIADA");
        principal.insert(&status);
        cwi::Render render("Signin");
        render.insert(&principal);
        render.compile();
        users_repo.criar_usuario(options["input_email"], options["input_pass"], options["input_type"]);
        return 0;
    }else{
        cwi::Div principal("principal");
        cwi::Text status("h1", "status", "ERRO AO CRIAR CONTA");
        principal.insert(&status);
        cwi::Render render("Signin");
        render.insert(&principal);
        render.compile();
        return 0;
    }

}