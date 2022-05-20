#include <iostream>
#include <string>

std::string SingleDigitToString(int n) {
    switch (n) {
        case 9:
            return "nine";
        case 8:
            return "eight";
        case 7:
            return "seven";
        case 6:
            return "six";
        case 5:
            return "five";
        case 4:
            return "four";
        case 3:
            return "three";
        case 2:
            return "two";
        case 1:
            return "one";
        default:
            return "";
    }
}

std::string TensDigitString(int n) {
    int t = n / 10;
    int ones = n % 10;
    std::string str = "";
    switch (t) {
        case 9:
            str.append("nintey");
            if (ones > 0) {
                str.append(SingleDigitToString(ones));
            }
            break;
        case 8:
            str.append("eighty");
            if (ones > 0) {
                str.append(SingleDigitToString(ones));
            }
            break;
        case 7:
            str.append("seventy");
            if (ones > 0) {
                str.append(SingleDigitToString(ones));
            }
            break;
        case 6:
            str.append("sixty");
            if (ones > 0) {
                str.append(SingleDigitToString(ones));
            }
            break;
        case 5:
            str.append("fifty");
            if (ones > 0) {
                str.append(SingleDigitToString(ones));
            }
            break;
        case 4:
            str.append("forty");
            if (ones > 0) {
                str.append(SingleDigitToString(ones));
            }
            break;
        case 3:
            str.append("thirty");
            if (ones > 0) {
                str.append(SingleDigitToString(ones));
            }
            break;
        case 2:
            str.append("twenty");
            if (ones > 0) {
                str.append(SingleDigitToString(ones));
            }
            break;
        case 1:
            switch (ones) {
                case 9:
                    str.append("nineteen");
                    break;
                case 8:
                    str.append("eighteen");
                    break;
                case 7:
                    str.append("seventeen");
                    break;
                case 6:
                    str.append("sixteen");
                    break;
                case 5:
                    str.append("fifteen");
                    break;
                case 4:
                    str.append("fourteen");
                    break;
                case 3:
                    str.append("thirteen");
                    break;
                case 2:
                    str.append("twelve");
                    break;
                case 1:
                    str.append("eleven");
                    break;
                case 0:
                    str.append("ten");
                    break;
            }
            break;
        default:
            str.append(SingleDigitToString(ones));
            break;
    }
    return str;
}

std::string GetWordFromInt(int n) {
    std::string str = "";
    if (n >= 1000) {
        int t = n / 1000;
        str.append(SingleDigitToString(t));
        str.append("thousand");
        n = n % 1000;
    }
    if (n >= 100) {
        int t = n / 100;
        std::string firstDigit = SingleDigitToString(t);
        if (firstDigit=="one") {
            //firstDigit = "a";
        } 
        str.append(firstDigit);
        str.append("hundred");
        n = n % 100;
        if (n > 0) {
            str.append("and");
        }
    }
    if (n > 0) {
        str.append(TensDigitString(n));
    }
    return str;
}

int main(int argc, char** argv) {
    int sum = 0;
    for (int i = 1; i <= 1000; ++i){
        std::string word = GetWordFromInt(i);
        std::cout << word << std::endl;
        sum = sum + word.length();
    }
    std::cout << "sum of string = " << sum << std::endl;
    return 0;
}