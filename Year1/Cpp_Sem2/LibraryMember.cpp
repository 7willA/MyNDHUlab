#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Member {
private:
    std::string memberID;
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::vector<std::string> borrowedBookISBNs;
    int maxBooksAllowed;

public:
    Member(const std::string& memberID, const std::string& name, int maxBooks = 5, 
           const std::string& address = "", const std::string& phone = "")
        : memberID(memberID), name(name), address(address), phoneNumber(phone), 
          maxBooksAllowed(maxBooks) {
        borrowedBookISBNs = std::vector<std::string>();
    }

    // Getter functions
    std::string getMemberID() const { return memberID; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getPhoneNumber() const { return phoneNumber; }
    const std::vector<std::string>& getBorrowedBookISBNs() const { return borrowedBookISBNs; }
    int getMaxBooksAllowed() const { return maxBooksAllowed; }
    int getBorrowedBooksCount() const { return borrowedBookISBNs.size(); }

    // Setter functions
    void setName(const std::string& name) { this->name = name; }
    void setAddress(const std::string& address) { this->address = address; }
    void setPhoneNumber(const std::string& phone) { phoneNumber = phone; }
    void setMaxBooksAllowed(int maxBooks) { 
        if (maxBooks >= 0) {
            maxBooksAllowed = maxBooks; 
        }
    }

    // Borrowing-related functions
    bool canBorrowMoreBooks() const {
        return getBorrowedBooksCount() < maxBooksAllowed;
    }

    bool borrowBookISBN(const std::string& isbn) {
        if (!canBorrowMoreBooks()) {
            return false;
        }
        // Check if ISBN already exists
        if (std::find(borrowedBookISBNs.begin(), borrowedBookISBNs.end(), isbn) != borrowedBookISBNs.end()) {
            return false;
        }
        borrowedBookISBNs.push_back(isbn);
        return true;
    }

    bool returnBookISBN(const std::string& isbn) {
        auto it = std::find(borrowedBookISBNs.begin(), borrowedBookISBNs.end(), isbn);
        if (it != borrowedBookISBNs.end()) {
            borrowedBookISBNs.erase(it);
            return true;
        }
        return false;
    }

    // Display function
    void displayDetails() const {
        std::cout << "Member ID: " << memberID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Phone: " << phoneNumber << std::endl;
        std::cout << "Max Books Allowed: " << maxBooksAllowed << std::endl;
        std::cout << "Books Borrowed: " << borrowedBookISBNs.size() << std::endl;
        std::cout << "Borrowed ISBNs: ";
        for (size_t i = 0; i < borrowedBookISBNs.size(); ++i) {
            if (i != 0) std::cout << ", ";
            std::cout << borrowedBookISBNs[i];
        }
        std::cout << std::endl;
    }
};

// Helper function for testing
void printBorrowedISBNsFromMain(const Member& member) {
    std::cout << "Borrowed ISBNs (checked from main): ";
    const auto& isbns = member.getBorrowedBookISBNs();
    for (size_t i = 0; i < isbns.size(); ++i) {
        if (i != 0) std::cout << ", ";
        std::cout << isbns[i];
    }
    std::cout << std::endl;
}