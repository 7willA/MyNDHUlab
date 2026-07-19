using namespace std;

enum class FictionGenre {
    SCIENCE_FICTION,
    FANTASY,
    MYSTERY,
    THRILLER,
    ROMANCE,
    HISTORICAL_FICTION,
    HORROR,
    OTHER
};

string genreToString(FictionGenre genre) {
    switch (genre) {
        case FictionGenre::SCIENCE_FICTION:
            return "Science Fiction";
        case FictionGenre::FANTASY:
            return "Fantasy";
        case FictionGenre::MYSTERY:
            return "Mystery";
        case FictionGenre::THRILLER:
            return "Thriller";
        case FictionGenre::ROMANCE:
            return "Romance";
        case FictionGenre::HISTORICAL_FICTION:
            return "Historical Fiction";
        case FictionGenre::HORROR:
            return "Horror";
        case FictionGenre::OTHER:
            return "Other";
        default:
            return "Unknown";
    }
}

class FictionBook : public Book {
private:
    FictionGenre genre;

public:
    FictionBook(const string& isbn, const string& title, const string& author,
                const string& publisher, int publicationYear, FictionGenre genre)
        : Book(isbn, title, author, publisher, publicationYear), genre(genre) {}

    FictionGenre getGenre() const {
        return genre;
    }

    void setGenre(FictionGenre genre) {
        this->genre = genre;
    }

    void displayDetails() const override {
        Book::displayDetails();
        cout << "Genre: " << genreToString(genre) << endl;
    }
};

class NonFictionBook : public Book {
private:
    string deweyDecimalNumber;
    string subjectArea;

public:
    NonFictionBook(const string& isbn, const string& title, const string& author,
                   const string& publisher, int publicationYear,
                   const string& dewey, const string& subject)
        : Book(isbn, title, author, publisher, publicationYear), 
          deweyDecimalNumber(dewey), subjectArea(subject) {}

    string getDeweyDecimalNumber() const {
        return deweyDecimalNumber;
    }

    string getSubjectArea() const {
        return subjectArea;
    }

    void setDeweyDecimalNumber(const string& dewey) {
        deweyDecimalNumber = dewey;
    }

    void setSubjectArea(const string& subject) {
        subjectArea = subject;
    }

    void displayDetails() const override {
        Book::displayDetails();
        cout << "Dewey Decimal: " << deweyDecimalNumber << endl;
        cout << "Subject Area: " << subjectArea << endl;
    }
};