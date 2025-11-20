#include<iostream>
#include<vector>

void multiplyMatrices(const std::vector<std::vector<int>>& matrixA,
                      const std::vector<std::vector<int>>& matrixB,
                      std::vector<std::vector<int>>& result) {
    int rowsA = matrixA.size();
    int colsA = matrixA[0].size();
    int colsB = matrixB[0].size();

    // Initializing elements of the result matrix to 0
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }

    // Performing matrix multiplication
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsB; j++) {
            for(int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> matrixA = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> matrixB = {{1, 0}, {0, 1}};
    std::vector<std::vector<int>> result(matrixA.size(), std::vector<int>(matrixB[0].size()));

    multiplyMatrices(matrixA, matrixB, result);

    // Printing the result
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
