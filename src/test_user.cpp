#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.hpp"
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

TEST_CASE("Testing the name"){
    User user;

    SUBCASE("Valid input") {
        std::string firstName = "aNy";
        std::string secondName = "NamE";

        user.mergeName(firstName, secondName);

        CHECK(user.seeName() == "Any Name");
    }

        // Assuming an empty string is expected for empty input - need to be implemented

        //SUBCASE("Empty input") {
        //    std::string firstName = "";
        //    std::string secondName = "";
        //
        //    user.mergeName(firstName, secondName);
        //
        //    CHECK(user.seeName() == "");
        //}
}