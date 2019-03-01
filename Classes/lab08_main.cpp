// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 7
// Filename: lab08_main.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Books are Awesome
// Purpose: Utilize a Book and Library class to create book objects with a title, authors, and date of publication.
//          Use insert and remove functions from Library class to insert or remove books from the vector list.
// Due Date: November 22, 2018
// *********************************************************************************************************************
#include <iostream>
#include "lab08_book.hpp"
#include "lab08_library.hpp"
using namespace std;

bool test_book_insertion(){
    bool test_insertion = true; // bool variable initialized
    vector<Book> books; // vector of Book objects

    // Call each Book constructor with different # of parameters to make Book instances
    Book my_book("UMOD", "Bella Martin and Bruce Hanington", "2012");
    Book my_book_2("Cracking the Coding Interview", "Gayle Laakmann McDowell");
    Book my_book_3 = Book();

    my_book_3.print(); // prints details of book instance

    // adds book instances to book vector
    books.push_back(my_book);
    books.push_back(my_book_2);
    books.push_back(Book("Harry Potter: Chamber of Secrets"));

    Library test_library(books); // Initializes library instance using constructor with single parameter
    Library test_library_2; // Initializes library instance of empty parameter constructor

    test_library_2.insert_book(my_book); // inserts book object into library instance of empty parameter constructor

    // inserts new book defined by string parameters into library instance
    test_library.insert_book("Cracking the PM Interview", "Gayle Laakmann McDowell", "2014")
                                // attempts to insert duplicate book into library, rejects, and now false
    && test_library.insert_book("UMOD", "Bella Martin and Bruce Hanington", "2012") ? : test_insertion = false;
    // ternary operator checking if all insertions were successful, if not, bool changed to false

    // attempts to insert duplicate book object, inserts new book object my_book_3
    test_library.insert_book(my_book_2) && test_library.insert_book(my_book_3) ? : test_insertion = false;

    test_library_2.print(); // prints books in default constructor library instance
    test_library.print(); // prints list of books in single parameter library instance

    return test_insertion; // will return false since not all insertions were successful
}

bool test_book_removal(){
    bool test_removal = true;
    vector<Book> books;

    // Initialize book objects with different Book constructors
    Book my_book = Book();
    Book my_book_1("Hunger Games", "Suzanne Collins", "2008");
    Book my_book_2("Catching Fire", "Suzanne Collins");
    Book my_book_3("Elephant Run", "Roland Smith", "2007");

    // adds Book instances to book vector
    books.push_back(my_book_1);
    books.push_back(my_book_2);

    // Initializes library instance with "books" vector
    Library test_library(books);

    // attempts to remove non-existent book defined by string parameters
    test_library.remove_book("Mocking Jay", "Suzanne Collins", "2010")
                                // removes book inside library instance
    && test_library.remove_book("Elephant Run", "Roland Smith", "2007") ? : test_removal = false;
    // since removal of non-existent book failed, test_removal set to false

    // removes existing book objects and fails to remove non-existent book objects
    test_library.remove_book(my_book_1) && test_library.remove_book(my_book_3) ? : test_removal = false;

    test_library.print(); // prints list of books in library instance after series of removals

    return test_removal; // will return false since not all removals were successful, otherwise, can return true
                         // if all remove functions were successful
}

int main(){
    // Outputs statement saying book insertion and book removal tests passed or failed depending on boolean value
    // that functions return
    cout << (test_book_insertion() ? "All book insertion tests passed.\n" : "One or more book insertion tests failed.\n") << endl;
    cout << (test_book_removal() ? "All book removal tests passed." : "One or more book removal tests failed.") << endl;
    // used ternary operator

    return 0; // program terminates
}

