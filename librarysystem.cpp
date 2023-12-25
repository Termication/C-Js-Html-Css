/*Certainly! Here's a C++ challenge for you:

Create a program that simulates a simple library system. The program should be able to:

Add a new book to the library.
Remove a book from the library.
Display the list of available books.
Allow users to borrow and return books.
You can use classes to represent books and the library system. Make sure to handle cases where a user tries to borrow a book that is already borrowed or return a book that is not in the library.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
public:
    std::string title;
    std::string author;
    bool available;

    Book(const std::string& t, const std::string& a) : title(t), author(a), available(true) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const std::string& title, const std::string& author) {
        books.emplace_back(title, author);
        std::cout << "Book added: " << title << " by " << author << std::endl;
    }

    void removeBook(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(),
            [title](const Book& b) { return b.title == title; });

        if (it != books.end()) {
            books.erase(it);
            std::cout << "Book removed: " << title << std::endl;
        } else {
            std::cout << "Book not found: " << title << std::endl;
        }
    }

    void displayBooks() const {
        std::cout << "Library Books:" << std::endl;
        for (const auto& book : books) {
            std::cout << "- " << book.title << " by " << book.author;
            if (book.available) {
                std::cout << " (Available)" << std::endl;
            } else {
                std::cout << " (Borrowed)" << std::endl;
            }
        }
    }

    void borrowBook(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(),
            [title](const Book& b) { return b.title == title && b.available; });

        if (it != books.end()) {
            it->available = false;
            std::cout << "You borrowed: " << title << std::endl;
        } else {
            std::cout << "Book not available for borrowing: " << title << std::endl;
        }
    }

    void returnBook(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(),
            [title](const Book& b) { return b.title == title && !b.available; });

        if (it != books.end()) {
            it->available = true;
            std::cout << "You returned: " << title << std::endl;
        } else {
            std::cout << "Book not valid for return: " << title << std::endl;
        }
    }
};

int main() {
    Library library;

    // Adding books
    library.addBook("The Catcher in the Rye", "J.D. Salinger");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");

    // Displaying books
    library.displayBooks();

    // Borrowing and returning books
    library.borrowBook("The Catcher in the Rye");
    library.borrowBook("To Kill a Mockingbird");

    library.displayBooks();

    library.returnBook("The Catcher in the Rye");

    library.displayBooks();

    return 0;
}


