// *********************************************************************************************************************
//
// Student Names: Jennifer (Jing Yi) He and Daniel Kim
// Student Numbers: 20759401 and 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 8
// Filename: lab09_produce.hpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Fresh Fruits and Veggies
// Purpose: To create a program that models an ordering system in which customers can subscribe to different plans
//          and get their fruits and vegetable items in a box based on the season of the month.
// Due Date: November 30, 2018
// *********************************************************************************************************************

#ifndef LAB09_LAB09_PRODUCE_HPP
#define LAB09_LAB09_PRODUCE_HPP

#include <iostream>
using namespace std;

// declare class produce
class Produce {

    // include struct containing attributes
    struct Date{
        int day, month, year;

        // struct constructor implicitly sets day, month, year to new values
        Date(int new_day, int new_month, int new_year) : day(new_day), month(new_month), year(new_year) {}
    };

    // class attributes describing a Produce object
    string item_name;
    double item_weight;
    Date exp_date;
    
public:
    // default constructor declaration
    Produce();
    // parametric constructor declaration
    Produce(string new_item_name, double new_item_weight, int new_eday, int new_emonth, int new_eyear);
    
    void print(); // print function
    bool operator==(Produce& target) const; // operator function overloading
};

// WinterProduce class inherits Produce class
class WinterProduce: public Produce {
public:
    WinterProduce(); // default constructor
    // parametric constructor
    WinterProduce(string new_item_name, double new_item_weight, int new_eday, int new_emonth, int new_eyear);

    // class functions
    void print();
    bool operator==(WinterProduce& target) const;
};
// SpringProduce class inherits Produce class
class SpringProduce: public Produce{
public:
    SpringProduce(); // default constructor
    // parametric constructor
    SpringProduce(string new_item_name, double new_item_weight, int new_eday, int new_emonth, int new_eyear);

    // class functions
    void print();
    bool operator==(SpringProduce& target) const;
};
// SummerProduce class inherits Produce class
class SummerProduce: public Produce{
public:
    SummerProduce(); // default constructor
    // parametric constructor
    SummerProduce(string new_item_name, double new_item_weight, int new_eday, int new_emonth, int new_eyear);

    // class functions
    void print();
    bool operator==(SummerProduce& target) const;
};
// FallProduce class inherits Produce class
class FallProduce: public Produce{
public:
    FallProduce(); // default constructor
    // parametric constructor
    FallProduce(string new_item_name, double new_item_weight, int new_eday, int new_emonth, int new_eyear);

    // class functions
    void print();
    bool operator==(FallProduce& target) const; // operator overloading
};

#endif 
