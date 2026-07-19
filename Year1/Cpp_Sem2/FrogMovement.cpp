#include <iostream>
using namespace std;

int main() {
    int x, y, destX, destY;

    cin >> x >> y >> destX >> destY;

    Frog frog(x, y);

    while (frog.getCurrentPositionX() != destX || frog.getCurrentPositionY() != destY) {
        if (frog.getCurrentPositionX() < destX) frog.moveRight();
        else if (frog.getCurrentPositionX() > destX) frog.moveLeft();

        if (frog.getCurrentPositionY() < destY) frog.moveUp();
        else if (frog.getCurrentPositionY() > destY) frog.moveDown();
    }

    return 0;
}
