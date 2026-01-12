#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        bool firstColZero = false;
        int m = matrix.size();
        int n = matrix[0].size();

        // Mark zero rows and columns
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                firstColZero = true;
            }

            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Place zeros
        for(int i = 1; i < m; i++){
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // First row
        if(matrix[0][0] == 0){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }

        // First col
        if(firstColZero){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 0, 4},
        {5, 6, 7, 8},
        {0, 9, 10, 11},
        {12, 13, 14, 15}
    };

    setZeroes(matrix);

    // Print result
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}