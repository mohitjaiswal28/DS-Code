#include <iostream>
#include <vector>
using namespace std;

void shiftLeft(vector<vector<int>>& mat, int row, int n, int amount) {
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = mat[row][(i + amount) % n];
    }
    for (int j = 0; j < n; ++j) {
        mat[row][j] = temp[j];
    }
}

void shiftUp(vector<vector<int>>& mat, int col, int n, int amount) {
    vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        temp[i] = mat[(i + amount) % n][col];
    }
    for (int i = 0; i < n; ++i) {
        mat[i][col] = temp[i];
    }
}

void cannonMultiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2, vector<vector<int>>& result, int n) {
    for (int i = 0; i < n; i++) {
        shiftLeft(mat1, i, n, i);
    }
    for (int j = 0; j < n; j++) {
        shiftUp(mat2, j, n, j);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = 0;
        }
    }

    for (int step = 0; step < n; step++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] += mat1[i][j] * mat2[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            shiftLeft(mat1, i, n, 1);
        }
        for (int j = 0; j < n; j++) {
            shiftUp(mat2, j, n, 1);
        }
    }
}

void printMatrix(const vector<vector<int>>& mat) {
    for(auto row : mat) {
        for(auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

int main() {
    const int n = 3; 
    
    vector<vector<int>> mat1(n, vector<int>(n));
    vector<vector<int>> mat2(n, vector<int>(n));
    vector<vector<int>> result(n, vector<int>(n));

    mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }

    mat2 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    }

    cout << "Matrix 1:" << endl;
    printMatrix(mat1);

    cout << "Matrix 2:" << endl;
    printMatrix(mat2);

    cannonMultiply(mat1, mat2, result, n);

    cout << "Result Matrix:" << endl;
    printMatrix(result);

    return 0;
}
