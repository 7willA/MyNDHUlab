class container {
private:
    int *box;          
    int len;           
    int index;         
    static int count;   

    // Private function to reallocate array
    bool reallocate(int size) {
        int *newBox = new int[size]; // Allocate new array
        if (!newBox) return false;    // Check allocation failure
        
        for (int i = 0; i <= index && i < size; i++) {
            newBox[i] = box[i];
        }
        delete[] box;                // Delete old array
        box = newBox;                // Update box to point to new array
        len = size;                  // Update length
        return true;
    }

    // Static functions to manage count
    static void increase() {
        count++;
    }

    static void decrease() {
        count--;
    }

public:
    // Default constructor
    container(void) : box(NULL), len(0), index(-1) {
        increase();
    }

    // Constructor with length parameter
    container(int len) : len(len), index(-1) {
        box = new int[len]; // Allocate array of given length
        increase();
    }

    // Destructor
    ~container() {
        delete[] box; // Free the dynamic array
        decrease();
    }

    // Get length of the array
    int getLen() {
        return len;
    }

    // Get current index
    int getIndex() {
        return index;
    }

    // Print all data in the array
    void traversal() {
        if (index < 0) {
            std::cout << "empty\n";
            return;
        }
        for (int i = 0; i <= index; i++) {
            std::cout << box[i] << " ";
        }
        std::cout << "\n";
    }

    // Push data to the tail
    bool push(int data) {
        if (index + 1 >= len) { // Array is full
            int newSize = (len == 0) ? 1 : len * 2; // Double size or set to 1 if empty
            if (!reallocate(newSize)) return false; // Reallocate failed
        }
        index++;
        box[index] = data;
        return true;
    }

    // Pop data from head
    int pop() {
        if (index < 0) return 0; 
        int value = box[0];      // Get head value
        // Shift elements left
        for (int i = 0; i < index; i++) {
            box[i] = box[i + 1];
        }
        index--;
        return value;
    }

    // Static function to get count
    static int getCount() {
        return count;
    }
};

// Initialize static member
int container::count = 0;