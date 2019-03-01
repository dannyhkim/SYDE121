// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 7
// Filename: lab08_library.hpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Books are Awesome
// Purpose: Utilize a Book and Library class to create book objects with a title, authors, and date of publication.
//          Use insert and remove functions from Library class to insert or remove books from the vector list.
// Due Date: November 22, 2018
// *********************************************************************************************************************

#ifndef LAB08_BOOK_LAB08_LIBRARY_HPP
#define LAB08_BOOK_LAB08_LIBRARY_HPP
#include <iostream>
#include <vector>
#include "lab08_book.hpp"
using namespace std;

class Library {
    vector<Book> books;

public:
    // constructors

    // PURPOSE: Parametric constructor that takes a new vector instance as input
    Library(vector<Book> new_books);

    // PURPOSE: default/empty constructor
    Library();

    // PURPOSE: prints information for all the books currently stored in the library
    void print();

    //PURPOSE: inserts a new book into the library
    // INPUTS: new_title, new_authors, new_dop
    //         - values for the object that is to be inserted
    // RETURNS: true, if the insertion was successful; false, otherwise
    bool insert_book(string new_title, string new_authors, string new_dop);

    // PURPOSE: inserts a new book into the library
    // INPUTS: new_book - values for the object that is to be inserted
    // RETURNS: true, if the insertion was successful; false, otherwise
    bool insert_book(Book new_book);

    //PURPOSE: removes a selected book from the library
    // INPUTS: cur_title, cur_authors, cur_dop
    //         - values for the object that is to be removed
    // RETURNS: true, if the removal was successful; false, otherwise
    bool remove_book(string cur_title, string cur_authors, string cur_dop);

    // PURPOSE: removes a selected book from the library
    // INPUTS: cur_book - values for the object that is to be removed
    // RETURNS: true, if the removal was successful; false, otherwise
    bool remove_book(Book cur_book);
};

#endif //LAB08_BOOK_LAB08_LIBRARY_HPP
