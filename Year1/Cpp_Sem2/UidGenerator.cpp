#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

// UID Class - Unique Identifier
class UID {
private:
    std::string id_value_;
    static const char default_prefix_ = 'D';
    static int counter_;

public:
    // Constructor with default prefix
    UID(char prefix = default_prefix_) {
        counter_++;
        std::ostringstream oss;
        oss << prefix << "-" << std::setfill('0') << std::setw(3) << counter_;
        id_value_ = oss.str();
    }

    // Getter method
    std::string getIDString() const {
        return id_value_;
    }

    // Static method to reset counter
    static void resetCounter(int start_value = 0) {
        counter_ = start_value - 1;
    }
};

// Location Class
class Location {
private:
    std::string roomName_;
    std::string details_;

public:
    // Constructor
    Location(const std::string& roomName, const std::string& details = "") 
        : roomName_(roomName), details_(details) {}

    // Getter methods
    std::string getRoomName() const {
        return roomName_;
    }

    std::string getDetails() const {
        return details_;
    }

    // Optional toString method
    std::string toString() const {
        if (details_.empty()) {
            return roomName_;
        } else {
            return roomName_ + " (" + details_ + ")";
        }
    }

    // Friend function for operator<< overloading
    friend std::ostream& operator<<(std::ostream& os, const Location& loc) {
        if (loc.details_.empty()) {
            os << loc.roomName_;
        } else {
            os << loc.roomName_ << " (" << loc.details_ << ")";
        }
        return os;
    }
};