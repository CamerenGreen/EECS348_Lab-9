#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "Matrix.hpp"


void runTests() {
    try {
        // Test 1: Load from file and display
        Matrix mat1, mat2;
        mat1.loadFromFile("matrix1.txt");
        mat2.loadFromFile("matrix2.txt");
        
        std::cout << "Matrix 1:" << std::endl;
        mat1.display();
        std::cout << "\nMatrix 2:" << std::endl;
        mat2.display();
        
        // Test 2: Matrix addition
        std::cout << "\nMatrix 1 + Matrix 2:" << std::endl;
        Matrix sum = mat1 + mat2;
        sum.display();
        
        // Test 3: Matrix multiplication
        std::cout << "\nMatrix 1 * Matrix 2:" << std::endl;
        Matrix product = mat1 * mat2;
        product.display();
        
        // Test 4: Diagonal sums
        std::cout << "\nMatrix 1 main diagonal sum: " << mat1.mainDiagonalSum() << std::endl;
        std::cout << "Matrix 1 secondary diagonal sum: " << mat1.secondaryDiagonalSum() << std::endl;
        
        // Test 5: Swap rows
        Matrix mat3 = mat1;
        std::cout << "\nMatrix 1 after swapping rows 0 and 1:" << std::endl;
        mat3.swapRows(0, 1);
        mat3.display();
        
        // Test 6: Swap columns
        Matrix mat4 = mat1;
        std::cout << "\nMatrix 1 after swapping columns 0 and 1:" << std::endl;
        mat4.swapColumns(0, 1);
        mat4.display();
        
        // Test 7: Update element
        Matrix mat5 = mat1;
        std::cout << "\nMatrix 1 after updating element at (0,0) to 99:" << std::endl;
        mat5.updateElement(0, 0, 99);
        mat5.display();
        
        // Test polymorphism and templates
        std::vector<int> intMat = {1, 2, 3, 4};
        std::vector<double> doubleMat = {1.1, 2.2, 3.3, 4.4};
        
        std::cout << "\nTesting polymorphic row swap (int matrix):" << std::endl;
        swapRowsPoly(intMat, 2, 0, 1);
        for (int val : intMat) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Testing polymorphic column swap (double matrix):" << std::endl;
        swapColumnsPoly(doubleMat, 2, 0, 1);
        for (double val : doubleMat) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Testing template element update (int matrix):" << std::endl;
        updateElementTemplate(intMat, 2, 1, 1, 99);
        for (int val : intMat) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}