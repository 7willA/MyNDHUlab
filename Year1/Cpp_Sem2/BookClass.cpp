#include <iostream>
#include <string>

using namespace std;

class Book {
protected:
    string isbn;
    string title;
    string author;
    string publisher;
    int publicationYear;
    bool isBorrowed;
    string borrowedByMemberID;

public:
    // Constructor
    Book(const string& isbn, const string& title, const string& author,
         const string& publisher, int publicationYear)
        : isbn(isbn), title(title), author(author), publisher(publisher),
          publicationYear(publicationYear), isBorrowed(false), borrowedByMemberID("") {}

    // Virtual Destructor
    virtual ~Book() {}

    // Getter methods
    string getISBN() const { return isbn; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getPublisher() const { return publisher; }
    int getPublicationYear() const { return publicationYear; }
    bool getIsBorrowed() const { return isBorrowed; }
    string getBorrowedByMemberID() const { return borrowedByMemberID; }

    // Setter method
    void setBorrowed(bool borrowed, const string& memberID = "") {
        isBorrowed = borrowed;
        if (borrowed) {
            borrowedByMemberID = memberID;
        } else {
            borrowedByMemberID = "";
        }
    }

    // Display details
    virtual void displayDetails() const {
        cout << "ISBN: " << isbn << "\n"
             << "Title: " << title << "\n"
             << "Author: " << author << "\n"
             << "Publisher: " << publisher << "\n"
             << "Publication Year: " << publicationYear << "\n"
             << "Status: " << (isBorrowed ? "Borrowed by " + borrowedByMemberID : "In Library")
             << endl;
    }
};