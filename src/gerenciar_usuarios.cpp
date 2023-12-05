
#include "../include/gerenciar_usuarios.hpp"
#include "../include/repositorio_posts.hpp"
#include "../include/repositorio_usuarios.hpp"
#include "../include/user.hpp"
#include "../include/user_student.hpp"
#include "../include/user_monitor.hpp"

#include <vector>

bool Gerenciar_usuarios::create_user(const std::string email, const std::string senha,  std::string const nome_completo, const std::string tipo){
    /*std::string aux;
    bool split = false;
    for(auto it : email){
        if(it == '@'){
            split = true;
        }
        if(split){
            aux += it;
        }
    }
    split = false;
    for(auto it : aux){
        if(it == '.'){
            split = true;
            break;
        }
    }
    if(!split){
        return false;
    }
    if(tipo != "Aluno" || tipo != "Monitor"){
        return false;
    }*/

    criar_usuario(email, senha, nome_completo, tipo);
    return true;
}

void Gerenciar_usuarios::remove_user(std::string id_usuario){
    remover_usuario(id_usuario);
}

bool Gerenciar_usuarios::authenticate_user(std::string email, std::string senha){
    return autenticar_login(email, senha);
}

User* Gerenciar_usuarios::find_user(std::string email){
    std::string id_usuario = identidade_usuario(email);
    User *user;
    std::string user_data;

    user_data = dados_usuario(id_usuario);

    std::vector<std::string> data;
    std::string aux;

    for(int i = 0; ; i++){
        if(user_data[i] == ' ' || user_data[i] == '\0'){
            data.push_back(aux);
            aux = "";
            if(user_data[i] == '\0'){break;}
            continue;
        }
        aux += user_data[i];
    }

    if(data[2] == "Aluno"){
        user = new Student(id_usuario, data[0], data[1], data[2]);
    }else{
        user = new Monitor(id_usuario, data[0], data[1], data[2]);
    }

    return user;

}

void Gerenciar_usuarios::edit_user(std::string id_usuario, const std::string email, const std::string senha,  std::string const nome_completo, const std::string tipo){
    remover_usuario(id_usuario);
    create_user(email, senha, nome_completo, tipo);
}

std::vector<std::string> Gerenciar_usuarios::get_posts(std::string id_usuario){
    return buscar_posts(id_usuario);
}