// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 7
// Filename: lab08_library.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Books are Awesome
// Purpose: Utilize a Book and Library class to create book objects with a title, authors, and date of publication.
//          Use insert and remove functions from Library class to insert or remove books from the vector list.
// Due Date: November 22, 2018
// *********************************************************************************************************************

#include "lab08_library.hpp"
#include <iostream>
#include <vector>
using namespace std;

    Library::Library():books(){} // empty constructor - implicitly initializes the vector attribute

    Library::Library(vector<Book> new_books) : books(new_books){} // parametric constructor that takes as input a vector
                                                                  // of book objects

    void Library::print(){ // prints all the books stored in the Library instance
        for(int i = 0; i < books.size(); i++){
            cout << i << ". ";
            books[i].print();
        }
    }
    // insert_book function with three string parameters
    bool Library::insert_book(string new_title, string new_authors, string new_dop) {

        for(int i = 0; i < books.size(); i++){
            // checks if there is an identical book in the library instance, if there is, function returns false
            // and does not insert book, rejects
            if(books[i].get_title().compare(new_title) == 0 && books[i].get_authors().compare(new_authors) == 0
               && books[i].get_dop().compare(new_dop) == 0){
                return false;
            }
        }
        // If no identical books are found by iterating through for loop, insert book into vector and return true
        // as indication that insertion is successful
        books.push_back(Book(new_title, new_authors, new_dop));
        return true;
    }
    // insert_book function with single Book object parameter
    bool Library::insert_book(Book new_book) {

        for(int i = 0; i < books.size(); i++){
            // compares attributes of each book object in vector with new_book, if identical book found, return false
            if(books[i].get_title().compare(new_book.get_title()) == 0 &&
               books[i].get_authors().compare(new_book.get_authors()) == 0 &&
               books[i].get_dop().compare(new_book.get_dop()) == 0){
                return false;
            }
        }
        // Inserts book object and returns true if no identical books found in previous for loop
        books.push_back(Book(new_book));
        return true;
    }

    // remove_book function with three string attribute parameters
    bool Library::remove_book(string cur_title, string cur_authors, string cur_dop) {

        for (int i = 0; i < books.size(); i++) {
            // Checks if book object attributes in vector and string parameter attributes are identical
            if (books[i].get_title().compare(cur_title) == 0 && books[i].get_authors().compare(cur_authors) == 0
                && books[i].get_dop().compare(cur_dop) == 0) {
                // removes book and returns true
                books.erase(books.begin() + i); // removes the book if found
                return true;
            }
        }
        return false; // book was not removed
    }
    // remove_book function with a single Book object parameter
    bool Library::remove_book(Book cur_book){

        for(int i = 0; i < books.size(); i++){
            // if an identical book object was found, book is removed from vector
            if(books[i].get_title().compare(cur_book.get_title()) == 0 &&
               books[i].get_authors().compare(cur_book.get_authors()) == 0 &&
               books[i].get_dop().compare(cur_book.get_dop()) == 0){

               books.erase(books.begin() + i);
               return true;
            }
        }
        return false; // book is not removed
    }

