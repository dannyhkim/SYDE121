// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 7
// Filename: lab08_book.hpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Books are Awesome
// Purpose: Utilize a Book and Library class to create book objects with a title, authors, and date of publication.
//          Use insert and remove functions from Library class to insert or remove books from the vector list.
// Due Date: November 22, 2018
// *********************************************************************************************************************
#include <iostream>
using namespace std;
#ifndef LAB08_BOOK_LAB08_BOOK_HPP
#define LAB08_BOOK_LAB08_BOOK_HPP

// PURPOSE: Models information about a book
class Book{
    string title, authors, dop; // attributes of class

public:
    // PURPOSE: Empty constructor
    Book();

    // PURPOSE: parametric constructor that takes one string as parameter value
    Book(string new_title);

    // PURPOSE: parametric constructor that takes two strings as parameter values
    Book(string new_title, string new_authors);

    // PURPOSE: parametric constructor that takes three strings as parameter values
    Book(string new_title, string new_authors, string new_dop);

    // PURPOSE: getters for individual attribute values
    string get_title();
    string get_authors();
    string get_dop();

    // PURPOSE: prints out the contents of the book objects
    void print();
};

#endif //LAB08_BOOK_LAB08_BOOK_HPP
