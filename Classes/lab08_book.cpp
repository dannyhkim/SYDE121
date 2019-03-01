// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 7
// Filename: lab08_book.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Books are Awesome
// Purpose: Utilize a Book and Library class to create book objects with a title, authors, and date of publication.
//          Use insert and remove functions from Library class to insert or remove books from the vector list.
// Due Date: November 22, 2018
// *********************************************************************************************************************
#include "lab08_book.hpp"
#include <iostream>
using namespace std;

    // PURPOSE: parametric constructor with no parameters
    Book::Book():title("n/a"), authors("n/a"), dop("n/a"){} // default constructor with no parameters, assigns all
                                                           // attributes to "n/a"

    // PURPOSE: parametric constructor that takes one string as parameter value
    Book::Book(string new_title) : title(new_title),authors("n/a"),dop("n/a"){}

    // PURPOSE: parametric constructor that takes two strings as parameter values
    Book::Book(string new_title, string new_authors) : title(new_title),authors(new_authors),dop("n/a"){}

    // PURPOSE: parametric constructor that takes three strings as parameter values
    Book::Book(string new_title, string new_authors, string new_dop) : title(new_title),authors(new_authors),dop(new_dop){}

    string Book::get_title(){ // getter that returns the title of a book instance
        return title;
    }

    string Book::get_authors() { // getter that returns authors of a book instance
        return authors;
    }

    string Book::get_dop() { // getter than returns date of publication of a book instance
        return dop;
    }

    // PURPOSE: prints out the contents of the book objects
    void Book::print() {
        cout << "Title: " << title << endl;
        cout << "Authors: " << authors << endl;
        cout << "Date of Publication: " << dop << endl << endl;
    }
