#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    string getISBN() {
        return isbn;
    }

    bool isAvailable() {
        return available;
    }

    void borrowBook() {
        available = false;
    }

    void returnBook() {
        available = true;
    }
};
class User {
private:
    int userId;
    string name;

public:
    User(int id, string n) {
        userId = id;
        name = n;
    }

    int getUserId() {
        return userId;
    }

    string getName() {
        return name;
    }
};
class Library {
private:
    vector<Book> books;

public:
    void addBook(Book book) {
        books.push_back(book);
        cout << "Book added successfully.\n";
    }

    void searchBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getTitle() == title) {
                cout << "Book Found!\n";
                cout << "Title: " << books[i].getTitle() << endl;
                cout << "Author: " << books[i].getAuthor() << endl;
                cout << "ISBN: " << books[i].getISBN() << endl;

                if (books[i].isAvailable())
                    cout << "Status: Available\n";
                else
                    cout << "Status: Borrowed\n";

                return;
            }
        }
        cout << "Book not found.\n";
    }

    void borrowBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getTitle() == title && books[i].isAvailable()) {
                books[i].borrowBook();
                cout << "Book borrowed successfully.\n";
                return;
            }
        }
        cout << "Book not available or not found.\n";
    }

    void returnBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getTitle() == title && !books[i].isAvailable()) {
                books[i].returnBook();
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found or already available.\n";
    }
};
int main() {
    Library library;

    library.addBook(Book("Bambi and the duke", "Ash knight", "111"));
    library.addBook(Book("Hellbound", "kazzenlx", "121"));

    int choice;
    string title;

    do {
        cout << "\n ONLINE LIBRARY SYSTEM \n";
        cout << "1. Search Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter book title: ";
            getline(cin, title);
            library.searchBook(title);
            break;

        case 2:
            cout << "Enter book title to borrow: ";
            getline(cin, title);
            library.borrowBook(title);
            break;

        case 3:
            cout << "Enter book title to return: ";
            getline(cin, title);
            library.returnBook(title);
            break;

        case 4:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}

