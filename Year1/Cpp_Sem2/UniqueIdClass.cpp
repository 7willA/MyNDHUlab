#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class UID {
private:
    std::string id_value_;
    static const char default_prefix_ = 'D';
    static int counter_;

public:
    UID(char prefix = default_prefix_) {
        std::ostringstream oss;
        oss << prefix << '-' << std::setw(3) << std::setfill('0') << counter_;
        id_value_ = oss.str();
        ++counter_;
    }

    std::string getIDString() const {
        return id_value_;
    }

    static void resetCounter(int start_value = 0) {
        counter_ = start_value;
    }
};

// static member variable definition
int UID::counter_ = 0;

class Location {
private:
    std::string roomName_;
    std::string details_;

public:
    Location(const std::string& roomName, const std::string& details = "")
        : roomName_(roomName), details_(details) {}

    std::string getRoomName() const {
        return roomName_;
    }

    std::string getDetails() const {
        return details_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Location& loc) {
        os << loc.roomName_;
        if (!loc.details_.empty()) {
            os << " (" << loc.details_ << ")";
        }
        return os;
    }
};
