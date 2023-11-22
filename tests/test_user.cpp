#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "../include/user.hpp"

TEST_CASE("Is it an email?") {
    User user;

    SUBCASE("Testing a valid email"){
        CHECK(user.isEmail("example@gmail.com"));
    }
    SUBCASE("Testing a invalid email"){
        CHECK_FALSE(user.isEmail("invalid_email.com"));
    }
}

TEST_CASE("Is it a password?") {
    User user;

    SUBCASE("Testing a void password"){
        CHECK_FALSE(user.isPassword(""));
    }
    SUBCASE("Testing an invalid password (not enough numbers)"){
        CHECK_FALSE(user.isPassword("senhainvalida"));
    }
    SUBCASE("Testing an invalid password (not enough letters)"){
        CHECK_FALSE(user.isPassword("s2987334"));
    }
    SUBCASE("Testing a too short password"){
        CHECK_FALSE(user.isPassword("soisso"));
    }
    SUBCASE("Finally testing a valid password"){
        CHECK(user.isPassword("senha123valida"));
    }
    
}

TEST_CASE("Change of email") {
    User user;

    CHECK_NOTHROW(user.changeEmail("example@gmail.com"));
    CHECK_EQ(user.seeEmail(), "example@gmail.com");

    CHECK_NOTHROW(user.changeEmail("user@yahoo.com"));
    CHECK_EQ(user.seeEmail(), "user@yahoo.com");
}

TEST_CASE("Change of password") {
    std::string firstName = "Any";
    std::string secondName = "Name";
    std::string password = "senhavalida123";
    std::string email = "emailvalido@gmail.com";
    User user(firstName, secondName, email, password);;

    SUBCASE("Valid new password"){
        user.changePassword("newPassword123");
        CHECK_EQ(user.seePassword(), "newPassword123");
    }

    SUBCASE("Invalid new password"){
        user.changePassword("pass");
        CHECK_EQ(user.seePassword(), "senhavalida123");
    }
}

TEST_CASE("Testing the name"){
    SUBCASE("Valid input") {
        std::string firstName = "aNy";
        std::string secondName = "NamE";
        std::string password = "senhavalida123";
        std::string email = "emailvalido@gmail.com";

        User user(firstName, secondName, email, password);

        CHECK(user.seeName() == "Any Name");
    }

    // See how to check if the name is empty
}