#include <bits/stdc++.h>
using namespace std;

class Book {
private:
    string author;
    string title;
    bool available;

public:
    Book() {
        title = "";
        author = "";
        available = true;
    }

    ~Book() {}

    Book(string title, string author) {
        this->title = title;
        this->author = author;
        available = true;
    }

    void setAvailability(bool check) {
        available = check;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    bool getAvailability() {
        return available;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Availability: " << (available ? "Available" : "Not Available") << endl;
        cout << endl;
    }
};

class LibraryMember {
private:
    string name;
    int card;

public:
    LibraryMember() {
        name = "";
        card = 0;
    }

    LibraryMember(string name, int card) {
        this->name = name;
        this->card = card;
    }

    string getName() {
        return name;
    }

    int getCard() {
        return card;
    }

    ~LibraryMember() {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "Library Card Number: " << card << endl;
        cout << endl;
    }
};

class Library {
private:
    Book books[100];
    LibraryMember members[100];
    int count = 0;
    int book_count = 0;

public:
    Library() {
        count = 0;
        book_count = 0;
    }

    void registerMember(string name, int number) {
        if (count < 100)
            members[count++] = LibraryMember(name, number);
    }

    void addBook(string name, string author) {
        if (book_count < 100)
            books[book_count++] = Book(name, author);
    }

    void borrowBook(string name, int number) {
        bool book_found = false, member_found = false;
        int i, j;
        for (i = 0; i < book_count; i++) {
            if (books[i].getTitle() == name && books[i].getAvailability()) {
                book_found = true;
                break;
            }
        }

        for (j = 0; j < count; j++) {
            if (members[j].getCard() == number) {
                member_found = true;
                break;
            }
        }

        if (book_found && member_found) {
            cout << "Book '" << name << "' has been borrowed by" << endl;
            members[j].display();
            books[i].setAvailability(false);
        }
    }

    void returnBook(string name, int number) {
        bool book_found = false;
        for (int i = 0; i < book_count; i++) {
            if (books[i].getTitle() == name && !books[i].getAvailability()) {
                books[i].setAvailability(true);
                book_found = true;
                break;
            }
        }

        if (book_found) {
            cout << "Book '" << name << "' has been returned by" << endl;
            for (int i = 0; i < count; i++) {
                if (members[i].getCard() == number) {
                    members[i].display();
                    break;
                }
            }
        }
    }

    void removeBook(string name) {
        for (int i = 0; i < book_count; i++) {
            if (books[i].getTitle() == name) {
                cout << "Book '" << books[i].getTitle() << "' has been removed from the library." << endl << endl;
                for (int j = i; j < book_count - 1; j++) {
                    books[j] = books[j + 1];
                }
                book_count--;
                break;
            }
        }
    }

    void removeMember(int card_number) {
        for (int i = 0; i < count; i++) {
            if (members[i].getCard() == card_number) {
                cout << "Member '" << members[i].getName() << " (" << members[i].getCard() << ")' has been removed from the library." << endl << endl;
                for (int j = i; j < count - 1; j++) {
                    members[j] = members[j + 1];
                }
                count--;
                break;
            }
        }
    }

    void displayAllBooks() {
        cout << "Books in the library:" << endl << endl;
        for (int i = 0; i < book_count; i++) {
            books[i].display();
        }
    }

    void displayAllMembers() {
        cout << "Members in the library:" << endl << endl;
        for (int i = 0; i < count; i++) {
            members[i].display();
        }
    }
};

 int main() {
 Library library;
 // Adding books
 library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
 library.addBook("To Kill a Mockingbird", "Harper Lee");
 library.addBook("Pride and Prejudice", "Jane Austen");
 // Displaying all books
 library.displayAllBooks();
 // Registering members
 library.registerMember("John Doe", 1234);
 library.registerMember("Jane Smith", 5678);
 // Displaying all members
 library.displayAllMembers();
 // Borrowing books
 library.borrowBook("The Great Gatsby", 1234);
 library.borrowBook("To Kill a Mockingbird", 5678);
 // Displaying all books (after borrowing)
 library.displayAllBooks();
 // Returning a book
 library.returnBook("The Great Gatsby", 1234);
 // Displaying all books (after returning)
 library.displayAllBooks();
 // Removing a book
 library.removeBook("Pride and Prejudice");
 // Displaying all books (after removal)
 library.displayAllBooks();
 // Removing a member
 library.removeMember(5678);
 // Displaying all members (after removal)
 library.displayAllMembers();
 return 0;
 }
