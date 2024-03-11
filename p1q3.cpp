#include <iostream>

class Array {
private:
    int **arr;
    int rows;
    int cols;

public:
    // Function to initialize the number of rows and columns
    void initialize_size(int r, int c) {
        rows = r;
        cols = c;
    }

    // Function to dynamically allocate memory for the array
    void declare_array() {
        arr = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new int[cols];
        }
    }

    // Function to deallocate the memory allocated to the array
    void deallocate_array() {
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    // Friend function to initialize the elements of the array with user input
    friend void initialize_Array(Array &obj);

    // Friend function to display the elements of the array
    friend void display_array(const Array &obj);

    // Friend function to check whether the passed array is an identity matrix or not
    friend int check_identity(const Array &obj);
};

// Function to initialize the elements of the array with user input
void initialize_Array(Array &obj) {
    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            std::cin >> obj.arr[i][j];
        }
    }
}

// Function to display the elements of the array
void display_array(const Array &obj) {
    std::cout << "Array elements:" << std::endl;
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            std::cout << obj.arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check whether the passed array is an identity matrix or not
int check_identity(const Array &obj) {
    if (obj.rows != obj.cols) {
        return 0; // Not a square matrix, so not an identity matrix
    }

    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            if (i == j && obj.arr[i][j] != 1) {
                return 0; // Diagonal elements should be 1
            } else if (i != j && obj.arr[i][j] != 0) {
                return 0; // Non-diagonal elements should be 0
            }
        }
    }
    return 1; // It's an identity matrix
}

int main() {
    Array matrix;
    int rows, cols;

    std::cout << "Enter the number of rows and columns of the matrix: ";
    std::cin >> rows >> cols;

    matrix.initialize_size(rows, cols);
    matrix.declare_array();
    initialize_Array(matrix);
    display_array(matrix);

    if (check_identity(matrix)) {
        std::cout << "Entered matrix is identity" << std::endl;
    } else {
        std::cout << "Entered matrix is not identity" << std::endl;
    }

    matrix.deallocate_array();

    return 0;
}
