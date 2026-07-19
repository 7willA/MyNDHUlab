#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

class Book;
class Member;

class Library {
private:
    std::string libraryName;
    std::vector<std::unique_ptr<Book>> books;
    std::vector<std::unique_ptr<Member>> members;

public:
    Library(const std::string& name) : libraryName(name) {}
    
    // Disable copying
    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;
    
    std::string getLibraryName() const { return libraryName; }

    // Book management
    void addBook(std::unique_ptr<Book> book) {
        books.push_back(std::move(book)); // Takes ownership of the book
    } 

    Book* findBookByISBN(const std::string& isbn) const {
        auto it = std::find_if(books.begin(), books.end(),
            [&isbn](const std::unique_ptr<Book>& book) {
                return book->getISBN() == isbn;
            });
        return (it != books.end()) ? it->get() : nullptr;
         // Searches for book by ISBN
    // Returns pointer if found, nullptr if not
    }

    void displayAllBooks() const {
        for (const auto& book : books) {
            book->displayDetails();
            std::cout << std::endl;
        }
    }

    // Member management
    void registerMember(std::unique_ptr<Member> member) {
        members.push_back(std::move(member));
    }

    Member* findMemberByID(const std::string& memberID) const {
        auto it = std::find_if(members.begin(), members.end(),
            [&memberID](const std::unique_ptr<Member>& member) {
                return member->getMemberID() == memberID;
            });
        return (it != members.end()) ? it->get() : nullptr;
    }

    void displayAllMembers() const {
        for (const auto& member : members) {
            member->displayDetails();
            std::cout << std::endl;
        }
    }
};