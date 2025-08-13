//
//  main.cpp
//  Library Managment System
//
//  Created by Ravia Bhullar on 8/12/25.
//

#include <iostream> //for input/output (cin/cout)
#include <vector> //to store multiple books dynamically
#include <string> //to handle book titles, authors, ISBNS

struct Book {
    std:: string title;
    std:: string author;
    std:: string isbn;
    bool isAvailable;
};

std::vector<Book> library;

//adds new books to the library and marks them avaible by default
void addBooks (const std::string& title, const std::string& author, const std::string& isbn){
    library.push_back({title, author, isbn, true});
    std::cout<<"Book added successfully!\n";
}

//shows the current list of books with availability status
void displayBooks(){
    std::cout<<"\nBooks in libary include:\n";
    for(int i =0; i<library.size();i++){
        std:: cout<<"Title: " << library[i].title
                << " | Author: " << library[i].author
                << " | ISBN: " <<library[i].isbn
                << " | Available: " << (library[i].isAvailable ? "Yes" : "No") << "\n";
    }
}

//allows user to borrow book if they are available
void borrowBooks(const std::string& isbn){
    for(auto& book: library){
        if(book.isbn==isbn){
            if(book.isAvailable){
                book.isAvailable=false;
                std:: cout<<"You borrowed "<<book.title<<"\n";
            }else{
                std::cout<<"Sorry, the book is already borrowed. \n";
            }
        }else{
            std::cout<<"Book not found \n";

        }
    }
}

//marks a book as available again by isbn
void returnBook(const std::string& isbn){
    for(auto& book:library){
        if (book.isbn==isbn){
            book.isAvailable=true;
            std:: cout<<"You returned " << book.title<< "\n";
        }else{
            std::cout<<"Book with ISBN " <<isbn<< " not found \n";
        }
    }
}

int main(){
    addBooks("Harry Potter", "JK Rowling", "1234567");
    displayBooks();
    borrowBooks("1234567");
    return 0;
}

