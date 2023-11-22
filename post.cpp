//Lucas Bahia e Sarah Azevedo 
//Post.hpp 
#include <iostream>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include post.hpp

Post::Post(std::string disciplina, std::string conteudo, std::string titulo, unsigned user_id)
    : Post(disciplina, conteudo, titulo, user_id, 0) {}

Post::Post(std::string disciplina, std::string conteudo, std::string titulo, unsigned user_id, unsigned post_id)
    : _disciplina(disciplina), _conteudo(conteudo), _titulo(titulo), _user_id(user_id), gerar_id() { 
    
 
}



int gerar_id (){
      unsigned seed = time(0);

    srand(seed);
    return rand();
}

