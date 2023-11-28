#include <iostream>
#include <string>
#include "user.cpp"

int main (){
    std::string input_email, input_name, input_surname;
    
    std::cin >> input_email;

    User user(input_name, input_surname, input_email, "default");

    std::cin >> input_name;
    std::cin >> input_surname;

    std::cout << user.Email() << std::endl;
    std::cout<< user.Name() << std::endl;
    return 0;
}