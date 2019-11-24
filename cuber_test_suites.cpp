// Matt Perry
// Tailon Russell
// Finished: 11/23/19
// cuber_test_suites.cpp  COMPLETE
// Template From Glenn G. Chappell
// 2019-11-22
//
// For CS 311 Fall 2019
// Tests for class Cuber: test suites
// For Project 8, Exercise B
// Uses the "Catch" unit-testing framework, version 2
// Requires cuber_test_main.cpp, catch.hpp, cuber.h

// Includes for code to be tested
#include "cuber.h"         // For class Cuber
#include "cuber.h"         // Double inclusion test

#define CATCH_CONFIG_FAST_COMPILE
                           // Disable some features for faster compile
#include "catch.hpp"       // For the "Catch" unit-testing framework

// Additional includes for this test program


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE("Cuber: Negative Ints")
{
    Cuber cc;
    int arg,result;
    {
        arg = -5;
        result = -(5*5*5);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);
    }
    {
        arg = -1;
        result = -1;
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);
    }
    {
        arg = -6;
        result = -(6*6*6);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);
    }
    {
        arg = -(10*10);
        result = -(10*10*10*10*10*10);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);
    }
}

TEST_CASE("Cuber: Positive Ints")
{
    Cuber cc;
    int arg,result;
    {
        arg = 5;
        result = (5*5*5);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);
    }
    {
        arg = 1;
        result = 1;
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);
    }
    {
        arg = 6;
        result = (6*6*6);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);
    }
    {
        arg = (10*10);
        result = (10*10*10*10*10*10);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);
    }
    {
        arg = 14;
        result = (14*14*14);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);
    }
    {
        arg = 0;
        result = 0;
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);
    }
}

TEST_CASE("Cuber: Positive Floats")
{
    Cuber cc;
    float arg,result;
    {
        arg = 5.5;
        result = (5.5*5.5*5.5);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == Approx(result));
    }
    {
        arg = 1.0;
        result = 1.0;
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == Approx(result));
    }
    {
        arg = 6.74;
        result = (6.74*6.74*6.74);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == Approx(result));
    }
    {
        arg = 13.66;
        result = (13.66*13.66*13.66);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == Approx(result));
    }
    {
        arg = 14.32;
        result = (14.32*14.32*14.32);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == Approx(result));
    }
}

TEST_CASE("Cuber: Negative Floats")
{
    Cuber cc;
    float arg,result;
    {
        arg = -4.22;
        result = -(4.22*4.22*4.22);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == Approx(result));
    }
    {
        arg = -1.0;
        result = -1.0;
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == Approx(result));
    }
    {
        arg = -2.94;
        result = -(2.94*2.94*2.94);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == Approx(result));
    }
    {
        arg = -11.26;
        result = -(11.26*11.26*11.26);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == Approx(result));
    }
    {
        arg = -(17.32);
        result = -(17.32*17.32*17.32);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == Approx(result));
    }
}

TEST_CASE("Cuber: Const Cuber Ints")
{
    const Cuber cc;
    int arg,result;
    {
        arg = 6;
        result = (6*6*6);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);   
    }
    {
        arg = 2;
        result = (2*2*2);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);   
    }
    {
        arg = -3;
        result = -(3*3*3);
        INFO(arg <<  " cubed is " << result);
        REQUIRE(cc(arg) == result);   
    }
}

TEST_CASE("Cuber: Chars")
{
    const Cuber cc;
    char arg, result;
    {
        arg = 'a';
        result = ('a'*'a'*'a');
        INFO(arg << " cuber is " << result);
        REQUIRE(cc(arg) == result);
    }
    {
        arg = 'v';
        result = ('v'*'v'*'v');
        INFO(arg << " cuber is " << result);
        REQUIRE(cc(arg) == result);
    }
}
