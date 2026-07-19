#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MatrixOperations {
private:
    vector<vector<int>> matrix;
    int size = 0;

public:
    void scan() {
        cin >> size;
        matrix.clear();
        matrix.resize(size, vector<int>(size));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                cin >> matrix[i][j];
    }

    void print() {
        if (matrix.empty()) {
            cout << "No element in matrix can be printed.\n";
        } else {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j)
                    cout << matrix[i][j] << " ";
                cout << endl;
            }
            cout << endl;
        }
    }

    void rotate_right() {
        if (matrix.empty()) {
            cout << "No element in matrix can be rotated.\n";
            return;
        }
        vector<vector<int>> rotated(size, vector<int>(size));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                rotated[j][size - 1 - i] = matrix[i][j];
        matrix = rotated;
    }

    void rotate_left() {
        if (matrix.empty()) {
            cout << "No element in matrix can be rotated.\n";
            return;
        }
        vector<vector<int>> rotated(size, vector<int>(size));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                rotated[size - 1 - j][i] = matrix[i][j];
        matrix = rotated;
    }
};

int main() {
    MatrixOperations matrixOps;
    string command;

    while (cin >> command) {
        if (command == "scan") {
            matrixOps.scan();
        } else if (command == "rotate") {
            string direction;
            cin >> direction;
            if (direction == "right") {
                matrixOps.rotate_right();
            } else if (direction == "left") {
                matrixOps.rotate_left();
            } else {
                cout << "unknown\n";
            }
        } else if (command == "print") {
            matrixOps.print();
        } else if (command == "stop") {
            break;
        } else {
            cout << "unknown\n";
        }
    }

    return 0;
}
