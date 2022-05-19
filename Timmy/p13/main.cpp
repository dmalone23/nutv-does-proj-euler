#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main(int argc, char** argv) {
    std::fstream inFile;
    inFile.open("data.txt");

    std::vector<std::vector<int>> lines;

    if(inFile.is_open()){
    std::string line;
    while(getline(inFile, line)){
      std::cout <<line <<std::endl;
    }
  }
}