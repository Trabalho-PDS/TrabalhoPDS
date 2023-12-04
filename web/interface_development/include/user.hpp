#pragma once

#include <iostream>
#include <string>

class User{
    public:
        //Construtor default;
        User();

        //Construtor padrão;
        User(std::string id_user, std::string email, std::string name);

        //Metodo get do campo privado _email;
        std::string Email() const;
        //Metodo get do campo privado _name;
        std::string Name() const;
        //Metodo get do campo privado _id_user;
        std::string Id() const;

        //Metodo virtual get do campo _type a ser implementado pelas heranças;
        virtual std::string Type() = 0; 


    private:        
        std::string _email;
        std::string _name;
        std::string _id_user;
};
