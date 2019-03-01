// *********************************************************************************************************************
//
// Student Names: Jennifer (Jing Yi) He and Daniel Kim
// Student Numbers: 20759401 and 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 8
// Filename: lab09_produce.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Fresh Fruits and Veggies
// Purpose: To create a program that models an ordering system in which customers can subscribe to different plans
//          and get their fruits and vegetable items in a box based on the season of the month.
// Due Date: November 30, 2018
// *********************************************************************************************************************

#include "lab09_produce.hpp"
#include <iostream>
using namespace std;

// default constructor initializes attributes to default values
Produce::Produce() : item_name("n/a"),item_weight(0),exp_date(Date(1,1,2000)) {
}

// parametric constructor where all 5 attributes are implicitly set
Produce::Produce(string new_item_name, double new_item_weight, int new_eday, int new_emonth, int new_eyear) :
item_name(new_item_name),item_weight(new_item_weight), exp_date(new_eday, new_emonth, new_eyear) {}

// prints details of Produce object
void Produce::print() {
    cout << item_name << endl;
    cout << item_weight << endl;
    cout << exp_date.day << "/" << exp_date.month << "/"<< exp_date.year << endl << endl;
}

// overloads == operator, checks if target object details and other class instance details match
bool Produce::operator==(Produce& target) const {
    bool are_equal = true;
    are_equal = are_equal && (item_name == target.item_name);
    are_equal = are_equal && (item_weight == target.item_weight);
    are_equal = are_equal && (exp_date.day == target.exp_date.day);
    are_equal = are_equal && (exp_date.month == target.exp_date.month);
    are_equal = are_equal && (exp_date.year == target.exp_date.year);
    
    return are_equal;
};

// default constructor
WinterProduce::WinterProduce() {}

// parametric constructor with implicit setters
WinterProduce::WinterProduce(string new_item_name, double new_item_weight, int new_eday, int new_emonth, int new_eyear)
:Produce(new_item_name, new_item_weight, new_eday, new_emonth, new_eyear) {
}

// prints details of WinterProduce object
void WinterProduce::print() {
    cout << "WINTER PRODUCE" << endl;
    Produce::print();
}
// operator overloading
bool WinterProduce::operator==(WinterProduce& target) const {
    return static_cast<Produce>(*this) == static_cast<Produce&>(target);
}

SpringProduce::SpringProduce() { // default constructor
}
// parametric constructor that implicitly sets attributes to new values by calling constructor in main
SpringProduce::SpringProduce(string new_item_name, double new_item_weight, int new_eday, int new_emonth, int new_eyear)
:Produce(new_item_name, new_item_weight, new_eday, new_emonth, new_eyear) {
}
void SpringProduce::print(){ // prints details of SpringProduce class instance
    cout << "SPRING PRODUCE" << endl;
    Produce::print();
}
// overloads operator when comparing SpringProduce objects
bool SpringProduce::operator==(SpringProduce &target) const {
   return static_cast<Produce>(*this) == static_cast<Produce&>(target);
}

// default constructor
SummerProduce::SummerProduce(){
}
// parametric constructor which implicitly sets SummerProduce attributes to new values when called in main
SummerProduce::SummerProduce(string new_item_name, double new_item_weight, int new_eday, int new_emonth, int new_eyear)
:Produce(new_item_name, new_item_weight, new_eday, new_emonth, new_eyear) {
}
void SummerProduce::print(){ // function that prints details of a SummerProduce object
    cout << "SUMMER PRODUCE" << endl;
    Produce::print();
}
// overloads operator when comparing SummerProduce objects
bool SummerProduce::operator==(SummerProduce &target) const {
    return static_cast<Produce>(*this) == static_cast<Produce&>(target);
}

FallProduce::FallProduce() { // default constructor
}
// parametric constructor
FallProduce::FallProduce(string new_item_name, double new_item_weight, int new_eday, int new_emonth, int new_eyear):Produce(new_item_name, new_item_weight, new_eday, new_emonth, new_eyear) {
}

void FallProduce::print() { // prints details of FallProduce objects
    cout << "FALL PRODUCE" << endl;
    Produce::print();
}
// overloads operator when comparing FallProduce class instances
bool FallProduce::operator==(FallProduce &target) const {
    return static_cast<Produce>(*this) == static_cast<Produce&>(target);
}

