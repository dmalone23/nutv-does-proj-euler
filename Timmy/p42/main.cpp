#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> split_string(string str, char d) {
    vector<string> words;
    int pos = str.find(d);
    while (pos != string::npos) {
        string new_word = str.substr(1, pos-2);
        str = str.substr(pos + 1, str.length());
        words.push_back(new_word);
        pos = str.find(d);
    }
    words.push_back(str.substr(1, str.length() - 2));
    return words;
}

void print_string_vector(vector<string> words) {
    for(auto &s : words) {
        cout << s << endl;
    }
}

int word_to_value(string word) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int sum = 0;
    for(int i = 0; i < word.length(); i++) {
        int c = alphabet.find(word.at(i)) + 1;
        sum = sum + c;
    }
    return sum;
}

bool is_triangle_num(int num) {
    int n = 1;
    int t = 0;
    do {
        t = (n * (n + 1)) / 2;
        if (t == num) {
            return true;
        }
        n = n + 1;
    } while (t < num);
    return false;
}

int main(int argc, char** argv) {
    fstream inFile;
    inFile.open("words.txt");
    int triangles = 0;
    if (inFile.is_open()) {
        string line;
        getline(inFile, line);
        vector<string> words = split_string(line, ',');
        for (auto &word : words) {
            if (is_triangle_num(word_to_value(word))) {
                triangles = triangles + 1;
            }
        }
    }
    cout << triangles << endl;
    return 0;
}