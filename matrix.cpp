#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

Matrix::Matrix(int n) : size(n) {
    if (n > 0) {
        data.resize(n, std::vector<double>(n, 0.0));
    }
}

void Matrix::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    
    int typeFlag;
    file >> size >> typeFlag;
    
    data.resize(size, std::vector<double>(size, 0.0));
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> data[i][j];
        }
    }
}

void Matrix::display() const {
    for (const auto& row : data) {
        for (double val : row) {
            std::cout << std::setw(10) << val;
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size for addition");
    }
    
    Matrix result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size for multiplication");
    }
    
    Matrix result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

double Matrix::mainDiagonalSum() const {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += data[i][i];
    }
    return sum;
}

double Matrix::secondaryDiagonalSum() const {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += data[i][size - 1 - i];
    }
    return sum;
}

void Matrix::swapRows(int row1, int row2) {
    if (row1 < 0 || row1 >= size || row2 < 0 || row2 >= size) {
        throw std::out_of_range("Row indices out of bounds");
    }
    std::swap(data[row1], data[row2]);
}

void Matrix::swapColumns(int col1, int col2) {
    if (col1 < 0 || col1 >= size || col2 < 0 || col2 >= size) {
        throw std::out_of_range("Column indices out of bounds");
    }
    for (int i = 0; i < size; ++i) {
        std::swap(data[i][col1], data[i][col2]);
    }
}

void Matrix::updateElement(int row, int col, double value) {
    if (row < 0 || row >= size || col < 0 || col >= size) {
        throw std::out_of_range("Matrix indices out of bounds");
    }
    data[row][col] = value;
}

// Polymorphic implementations
void swapRowsPoly(std::vector<int>& matrix, int n, int row1, int row2) {
    if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n) {
        throw std::out_of_range("Row indices out of bounds");
    }
    for (int j = 0; j < n; ++j) {
        std::swap(matrix[row1 * n + j], matrix[row2 * n + j]);
    }
}

void swapRowsPoly(std::vector<double>& matrix, int n, int row1, int row2) {
    if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n) {
        throw std::out_of_range("Row indices out of bounds");
    }
    for (int j = 0; j < n; ++j) {
        std::swap(matrix[row1 * n + j], matrix[row2 * n + j]);
    }
}

void swapColumnsPoly(std::vector<int>& matrix, int n, int col1, int col2) {
    if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n) {
        throw std::out_of_range("Column indices out of bounds");
    }
    for (int i = 0; i < n; ++i) {
        std::swap(matrix[i * n + col1], matrix[i * n + col2]);
    }
}

void swapColumnsPoly(std::vector<double>& matrix, int n, int col1, int col2) {
    if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n) {
        throw std::out_of_range("Column indices out of bounds");
    }
    for (int i = 0; i < n; ++i) {
        std::swap(matrix[i * n + col1], matrix[i * n + col2]);
    }
}