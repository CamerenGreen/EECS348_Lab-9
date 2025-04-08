#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

// all of your function definitions should be in this file now

class Matrix {
    private:
        // Member variables
        std::vector<std::vector<double>> data;
        int size; // initialize to 0

    public:
        // Constructor
        Matrix(int n = 0);
        
        // File operations
        void loadFromFile(const std::string& filename);
        
        // Display
        void display() const;
        
        // Matrix operations
        Matrix operator+(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        
        // Diagonal sums
        double mainDiagonalSum() const;
        double secondaryDiagonalSum() const;
        
        // Row/column operations
        void swapRows(int row1, int row2);
        void swapColumns(int col1, int col2);
        void updateElement(int row, int col, double value);
        
        // Accessors
        int getSize() const { return size; }
        double getElement(int row, int col) const { return data[row][col]; }
};

// Polymorphic functions for swapping rows/columns
void swapRowsPoly(std::vector<int>& matrix, int n, int row1, int row2);
void swapRowsPoly(std::vector<double>& matrix, int n, int row1, int row2);
void swapColumnsPoly(std::vector<int>& matrix, int n, int col1, int col2);
void swapColumnsPoly(std::vector<double>& matrix, int n, int col1, int col2);


// Template function for updating elements
template <typename T>
void updateElementTemplate(std::vector<T>& matrix, int n, int row, int col, T value) {
    if (row < 0 || row >= n || col < 0 || col >= n) {
        throw std::out_of_range("Matrix indices out of bounds");
    }
    matrix[row * n + col] = value;
}

#endif // __MATRIX_HPP__
