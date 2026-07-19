class container {
private:
    int *box;
    int len;
    int index;

public:
    container(void) : box(NULL), len(0), index(-1) {}

    int getLen() {
        return len;
    }

    int getIndex() {
        return index;
    }
};
