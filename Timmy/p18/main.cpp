#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> GetVectorIntFromString(string str) {
    vector<int> nums;
    while (true) {
        int ind = str.find(" ");
        if (ind < str.length()) {
            string subStr = str.substr(0,ind);
            nums.push_back(stoi(subStr));
            str = str.substr(ind+1, str.length());
        }
        else {
            //string subStr = str.substr(0,ind);
            nums.push_back(stoi(str));
            return nums;
        }
    }
}

int GetMaxFromVector(vector<int> v) {
    int max = -1;
    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i) > max) {
            max = v.at(i);
        }
    }
    return max;
}

void PrintTriangle(vector<vector<int>> triangle) {
    for (int r = 0; r < triangle.size(); ++r) {
        vector<int> row = triangle.at(r);
        for (int c = 0; c < row.size(); ++c) {
            std::cout << row.at(c) << " ";
        }
        std::cout << std::endl;
    }
}

vector<vector<int>> CalculateTrianglePaths(vector<vector<int>> triangle) {
    for (int r = 1; r < triangle.size(); ++r) {
        vector<int> prevRow = triangle.at(r-1);
        vector<int> row = triangle.at(r);
        for (int c = 0; c < row.size(); ++c) {
            int maxPath = -1;
            if (c < prevRow.size() && prevRow.at(c) > maxPath) {
                maxPath = prevRow.at(c);
            }
            if (c > 0 && prevRow.at(c-1) > maxPath) {
                maxPath = prevRow.at(c-1);
            }
            triangle.at(r).at(c) = row.at(c) + maxPath;
        }
    }
    return triangle;
}

vector<vector<int>> ParseFileToVector(string fileName) {
    vector<vector<int>> triangle;
    std::fstream inFile;
    inFile.open(fileName);

    if(inFile.is_open()){
        std::string line;
        while(getline(inFile, line)){
            //std::cout << "LINE: " << line << std::endl;
            std::vector<int> row = GetVectorIntFromString(line);
            triangle.push_back(row);
        }
    }
    //PrintTriangle(triangle);
    return triangle;
}

int main(int argc, char** argv) {
    vector<vector<int>> triangle = ParseFileToVector("data.txt");
    triangle = CalculateTrianglePaths(triangle);
    //PrintTriangle(triangle);
    cout<< GetMaxFromVector(triangle.back()) << endl;
    return 0; 
}