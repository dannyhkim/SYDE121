// *********************************************************************************************************************
//
// Student Names: Jennifer (Jing Yi) He and Daniel Kim
// Student Numbers: 20759401 and 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 8
// Filename: lab09_main.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Fresh Fruits and Veggies
// Purpose: To create a program that models an ordering system in which customers can subscribe to different plans
//          and get their fruits and vegetable items in a box based on the season of the month.
// Due Date: November 30, 2018
// *********************************************************************************************************************

#include <iostream>
#include "lab09_produce.hpp"
#include "lab09_box.hpp"

using namespace std;

// functions for driver program that fully test the classes
void test_fill_the_box();
void test_comparison_operator();

int main() {
    // calls functions for driver program
    test_fill_the_box();
    test_comparison_operator();
    return 0;
}

void test_fill_the_box(){

    // creates 3 FruitsAndVeggiesBox objects, one small(5 produce), medium(10 produce), and large sized(15 produce)
    FruitsAndVeggiesBox b1(FruitsAndVeggiesBox::SMALL_ORDER);
    FruitsAndVeggiesBox b2(FruitsAndVeggiesBox::MEDIUM_ORDER);
    FruitsAndVeggiesBox b3(FruitsAndVeggiesBox::LARGE_ORDER);

    b1.fill_the_box(1); // fills box with produce from January (Winter season exclusively - integer indicates month)
    b2.fill_the_box(3); // fills box with produce from March (Winter and Spring seasons)
    b3.fill_the_box(8); // fills box with produce from August(Summer and Fall seasons)

    // prints details of produce in each box
    cout << "BOX 1" << endl;
    b1.print();
    cout << "BOX 2" << endl;
    b2.print();
    cout << "BOX 3" << endl;
    b3.print();

}

// tests whether overloaded operators function correctly
void test_comparison_operator(){

    Produce p1; // empty produce object
    Produce p2("Apples",3.2,1,1,2019); // Creates produce by filling parameters of constructor
    p1.print(); // prints details of produce
    p2.print();

    // checks for functionality of operator function which overloads
    if(p1 == p2){
        cout << "Items are the same.\n" << endl;
    }else{
        cout << "Items are not the same.\n" << endl; // should print this statement since p1 and p2 are not matching
    }

    WinterProduce w1("Lettuce",4,3,5,2020); // two WinterProduce objects with exact same details initialized
    WinterProduce w2("Lettuce",4,3,5,2020);
    SpringProduce sp1("Peaches",1.1,5,16,2021); // creates Produce from 3 other seasons
    SummerProduce s1("Watermelon",10,8,14,2021);
    FallProduce f1("Carrots",3.7,9,20,2019);
    w1.print(); // prints details of all the produce objects created
    w2.print();
    sp1.print();
    s1.print();
    f1.print();

    if(w1 == w2){ // checks operator overloading
        cout << "The Winter Items are the same." << endl; // this statement should be printed
    }else {
        cout << "The Winter Items are not the same." << endl;
    }

}


