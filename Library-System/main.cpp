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
void addBook (const std::string& title, const std::string& author, const std::string& isbn){
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
void borrowBook(const std::string& isbn) {
    bool found = false;
    for (auto& book : library) {
        if (book.isbn == isbn) {
            found = true;
            if (book.isAvailable) {
                book.isAvailable = false;
                std::cout << "You borrowed " << book.title << "\n";
            } else {
                std::cout << "Sorry, the book is already borrowed.\n";
            }
            break; // no need to keep looping
        }
    }
    if (!found) {
        std::cout << "Book not found\n";
    }
}

//marks a book as available again by isbn
void returnBook(const std::string& isbn) {
    bool found = false;
    for (auto& book : library) {
        if (book.isbn == isbn) {
            found = true;
            book.isAvailable = true;
            std::cout << "You returned " << book.title << "\n";
            break;
        }
    }
    if (!found) {
        std::cout << "Book with ISBN " << isbn << " not found\n";
    }
}


int main() {
    addBook("1984", "George Orwell", "9780451524935");
    addBook("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    addBook("To Kill a Mockingbird", "Harper Lee", "9780060935467");
    displayBooks();
    int choice;
    std::string isbn;

    do {
        std::cout << "\nMenu:\n1. Display books\n2. Borrow book\n3. Return book\n4. Exit\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayBooks();
                break;
            case 2:
                std::cout << "Enter ISBN to borrow: ";
                std::cin >> isbn;
                borrowBook(isbn);
                break;
            case 3:
                std::cout << "Enter ISBN to return: ";
                std::cin >> isbn;
                returnBook(isbn);
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}

