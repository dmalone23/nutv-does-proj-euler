#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int GetSumOfDigit(std::vector<std::vector<int>> lines, int ind, int r){
  int sum = 0;
  for (int i = 0; i < lines.size(); ++i){
    int d = lines.at(i).at(ind);
    sum = sum + d;
  }
  return sum + r;
}

void printVector(std::vector<int> v){
  for(int i = 0; i < v.size(); ++i){
    std::cout << v.at(i) << std::endl;
  }
}

int main(int argc, char** argv) {
    std::fstream inFile;
    inFile.open("data.txt");

    std::vector<std::vector<int>> lines;

    if(inFile.is_open()){
    std::string line;
    while(getline(inFile, line)){
      std::vector<int> row;
      for (int i = 49; i >= 0; --i) {
        row.push_back((int) line[i] - 48);
      }
      lines.push_back(row);
    }

    int r = 0;
    std::vector<int> sums;
    for (int i = 0; i < 50; ++i){
      int s = GetSumOfDigit(lines, i, r);
      sums.push_back(s%10);
      r = s/10;
    }

    while (true){
      sums.push_back(r%10);
      if (r >= 10) {
        r = r/10;
      }
      else {
        break;
      }
    }

    for(int i = 0; i < 10; ++i){
      std::cout << sums.back();
      sums.pop_back();
    }
    std::cout << std::endl;
  }
}