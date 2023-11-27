#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "../include/user_monitor.hpp"

TEST_CASE("Seeing star range"){
    Monitor monitor;

    SUBCASE("Inicial value"){
        CHECK_EQ(monitor.seeStars(), 0);
    };

    SUBCASE("After some evaluations"){
        CHECK_EQ(monitor.seeStars(), 0);

        monitor.calculateStars(3);
        CHECK_EQ(monitor.seeStars(), 3);

        monitor.calculateStars(5);
        CHECK_EQ(monitor.seeStars(), 4);
    }
}