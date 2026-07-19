class DateTime : public Date, public Time {
    public:
    DateTime(): Date("1900/01/01"), Time("00:00:00"){
        
    }
    DateTime(string str) : Date(str.substr(0,10)), Time(str.substr(11)) {}
    string toString(){
        string datetime = Date::display()+" "+Time::display();
        return datetime;
        }
};