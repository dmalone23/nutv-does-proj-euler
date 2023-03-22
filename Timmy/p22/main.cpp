#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> getNames(string line) {
    int pos = 0;
    vector<string> names;
    while((pos = line.find(",")) != string::npos) {
        string name = line.substr(1,pos-2);
        line = line.substr(pos+1, line.size());
        names.push_back(name);
    }
    names.push_back(line.substr(1, line.size()-2));
    return names;
}

void printNames(vector<string> names) {
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }
}

int getNameValue(string name) {
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int sum = 0;
    for (int i = 0; i < name.size(); i++) {
        int val = abc.find(name.at(i)) + 1;
        //cout << name.at(i) << " = " << val << endl;
        sum += val;
    }
    return sum;
}

long getNamesTotal(vector<string> names) {
    long sum = 0;
    for (int i = 0; i < names.size(); i++) {
        int spot = i + 1;
        int val = getNameValue(names[i]);
        int prod = val * spot;
        sum += prod;
    }
    return sum;
}

int main(int argc, char** argv) {
    fstream inFile;
    inFile.open("p022_names.txt");
    int i = 0;
    cout << getNameValue("COLIN") << endl;
    //return 0;
    if (inFile.is_open()) {
        string line;
        while(getline(inFile, line)){
            //std::cout << "LINE: " << line << std::endl;
            vector<string> names = getNames(line);
            sort(names.begin(), names.end());
            //printNames(names);
            long total = getNamesTotal(names);
            cout << total << endl;
        }
    }
    return 0;
}