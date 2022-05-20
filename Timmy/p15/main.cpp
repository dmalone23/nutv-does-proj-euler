#include <iostream>
#include <vector>
#include <string>

void PrintVector(std::vector<std::vector<int>> v) {
    for (int r = 0; r < v.size(); ++r) {
        std::vector<int> row = v.at(r);
        for (int c = 0; c < row.size(); ++c){
            std::cout << row.at(c) << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char** argv){
    int dim;
    std::vector<std::vector<int>> grid;
    if (argc == 1) {
        dim = 20;
    }
    else {
        dim = atoi(argv[1]);
    }
    dim = dim + 1;
    std::cout << dim << std::endl;

    for (int r = 0; r < dim; ++r){
        std::vector<int> row;
        
        std::cout << "start for loop"<<std::endl;
        for (int c = 0; c < dim; ++c) {
            int sum = 0;
            if (r > 0) {
                std::cout << "in row "<< r << std::endl;
                sum = sum + grid.at(r-1).at(c);
            }
            if (c > 0) {
                std::cout << "in col "<< c << std::endl;
                sum = sum + row.at(c-1);
            }
            if (c == 0 && r == 0) {
                std::cout << "start"<<std::endl;
                sum = 1;
            }
            row.push_back(sum);
        }
        grid.push_back(row);
        std::cout<< "At row" << std::endl;
    }
    PrintVector(grid);
    std::cout << "For a " << dim << "x" << dim << " grid there are " << grid.at(dim-1).at(dim-1) << " possible paths." << std::endl;
    return 0;
}