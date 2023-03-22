#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/*
    Type of Hand Values:
    1: High Card: Highest value card.
    2: One Pair: Two cards of the same value.
    3: Two Pairs: Two different pairs.
    4: Three of a Kind: Three cards of the same value.
    5: Straight: All cards are consecutive values.
    6: Flush: All cards of the same suit.
    7: Full House: Three of a kind and a pair.
    8: Four of a Kind: Four cards of the same value.
    9: Straight Flush: All cards are consecutive values of same suit.
    10: Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
*/

class Hand {
    public:
        int typeOfHand;
        int highOfHand;
        int totalHigh;
        Hand(int toh, int hoh, int th) {
            typeOfHand = toh;
            highOfHand = hoh;
            totalHigh = th;
        }
        Hand() {
            typeOfHand = -1;
            highOfHand = -1;
            totalHigh = -1;
        }
        bool isEmpty() {
            if (totalHigh == -1 && typeOfHand == -1 && highOfHand == -1) {
                return true;
            }
            return false;
        }
};

bool inVector(vector<char> chars, char c) {
    bool invec = false;
    for (int i = 0; i < chars.size(); i++) {
        if (chars.at(i) == c) {
            invec = true;
            break;
        }
    }
    return invec;
}

bool isRoyalFlush(vector<string> handStr) {
    char suit = handStr[0].at(1);
    string vals = "TJQKA";

    for (int i = 0; i < handStr.size(); i++) {
        char s = handStr[i].at(1);
        char n = handStr[i].at(0);
        if (s != suit || vals.find(n) == -1) {
            return false;
        }
    }
    return true;
}

Hand straightFlush(vector<string> handStr) {
    return Hand();
}

Hand getHand(vector<string> handStr) {
    Hand hand;
    if (isRoyalFlush(handStr)) {
        return Hand(10, 14, 14);
    }
    hand = straightFlush(handStr);
    if (!hand.isEmpty()) {
        return hand;
    }
}

int handleHand(string line) {
    vector<string> cards;
    for (int i = 0; i < 30; i = i + 3) {
        cards.push_back(line.substr(i,2));
    }
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i] << endl;
    }
    return 0;
}

int main(int argc, char** argv) {
    int wins = 0;
    std::fstream inFile;
    inFile.open("poker.txt");

    if(inFile.is_open()){
        string line;
        while(getline(inFile, line)) {
            wins = wins + handleHand(line);
            return 0;
        }
        cout << wins << endl;
        return 0;
    }
}