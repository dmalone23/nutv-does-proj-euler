#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void printMatrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        vector<int> row = matrix.at(i);
        for (int j = 0; j < row.size(); j++) {
            cout << row.at(j) << ", ";
        }
        cout << endl;
    }
}

int shortestPath(vector<vector<int>> matrix) {
    for (int r = matrix.size() - 1; r >= 0; r--) {
        vector<int> row = matrix.at(r);
        for (int c = row.size() - 1; c >= 0; c--) {
            cout << r << ", " << c << endl;
            if (c == row.size() - 1 && r == matrix.size()-1) {
                continue;
            }
            else if (c == row.size() - 1) {
                matrix[r][c] += matrix[r+1][c];
            }
            else if (r == matrix.size()-1) {
                matrix[r][c] += matrix[r][c+1];
            }
            else {
                int min = matrix[r][c+1];
                if (min > matrix[r+1][c]) {
                    min = matrix[r+1][c];
                }
                matrix[r][c] += min;
            }
        }
    }
    printMatrix(matrix);
    return matrix[0][0];
}

vector<vector<int>> practiceMatrix() {
    vector<vector<int>> matrix;
    matrix.push_back({131, 673, 234, 103, 18});
    matrix.push_back({201, 96, 342, 965, 150});
    matrix.push_back({630, 803, 746, 422, 111});
    matrix.push_back({537, 699, 497, 121, 956});
    matrix.push_back({805, 732, 524, 37, 331});
    return matrix;
}

int main(int argc, char** argv) { 
    fstream inFile;
    inFile.open("matrix.txt");

    vector<vector<int>> matrix;

    cout << "TEST1" << endl;

    if(inFile.is_open()){
        cout << "TEST2" << endl;
        string line;
        while(getline(inFile, line)){
        vector<int> row;
        while (true) {
            int ind = line.find(",");
            if (ind == -1) {
                break;
            }
            else {
                row.push_back(stoi(line.substr(0,ind)));
                line = line.substr(ind+1, line.size());
            }
        }
        matrix.push_back(row);
        }
    }
    //matrix = practiceMatrix();
    cout << shortestPath(matrix) << endl;
    return 0;
}