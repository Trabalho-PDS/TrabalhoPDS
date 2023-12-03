#pragma once

#include <iostream>
#include <string>

class User{
    public:   
        User();
        User(std::string id_user, std::string email, std::string name);

        std::string Email() const;
        std::string Name() const;
        std::string Id() const;
        virtual std::string Type() = 0; 


    private:        
        std::string _email;
        std::string _name;
        std::string _id_user;
};
