#pragma once

#include <iostream>
#include <string>

class User{
    public:
        /**
        * @brief Construtor genérico da classe User.
        * @retval none.
        * */
        User();
        /**
        * @brief Construtor padrão da classe User.
        * @param id_user, email, name: id_user, email, name.
        * */
        User(std::string id_user, std::string email, std::string name);
        /**
        * @brief Metodo get do campo privado _email.
        * @retval std::string
        * */
        std::string Email() const;
        /**
        * @brief Metodo get do campo privado _name.
        * @retval std::string
        * */
        std::string Name() const;
        /**
        * @brief Metodo get do campo privado _id_user.
        * @retval std::string
        * */
        std::string Id() const;
        /**
        * @brief Metodo virtual get do campo _type a ser implementado pelas heranças.
        * @retval std::string
        * */
        virtual std::string Type() = 0; 


    private:        
        std::string _email;
        std::string _name;
        std::string _id_user;
};
