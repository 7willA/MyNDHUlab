#include <iostream>
#include <string>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(string timeStr) {
        hours   = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');
        minutes = (timeStr[3] - '0') * 10 + (timeStr[4] - '0');
        seconds = (timeStr[6] - '0') * 10 + (timeStr[7] - '0');
    }
    
    string toString() const {
        string result;

        if (hours < 10) result += "0";
        result += to_string(hours) + ":";

        if (minutes < 10) result += "0";
        result += to_string(minutes) + ":";

        if (seconds < 10) result += "0";
        result += to_string(seconds);

        return result;
    }

    int operator-(const Time &other) const {
        int thisTotal  = hours * 3600 + minutes * 60 + seconds;
        int otherTotal = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return thisTotal > otherTotal ? thisTotal - otherTotal : otherTotal - thisTotal;
    }
};
