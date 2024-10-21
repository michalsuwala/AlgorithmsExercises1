#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::vector<std::string> tokens;
    tokens.push_back("");
    int count = 0;
    for (char c: line) {
        if(c == ' ') {
            tokens.push_back("");
        }
        else {
            tokens[count] += c;
        }
    }

    std::cin >> std::ws;
    std::getline(std::cin, line);

    std::string pattern;
    std::cin >> std::ws;
    std::getline(std::cin, pattern);

    int patternValue = 0;
    int lineValue = 0;
    for (char c : pattern) {
        patternValue = (int(c) + 256 * patternValue) % 7;
    }

    int h = (int)pow(256, pattern.length() - 1) % 7;

    int res = -1;
    for (int i = 0; i < line.length(); ++i) {
        if (i < pattern.length()) {
            lineValue = (line[i] + 256 * lineValue) % 7;
        }
        else {
            if (patternValue == lineValue) {
                bool f = true;
                for (int j = i - pattern.length(), k = 0; j < i; ++j, ++k) {
                    if (pattern[k] != line[j]) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    res = i - pattern.length();
                    break;
                }
            }
  
        }

        if (i >= pattern.length()) {
            lineValue = (256 * (lineValue - line[i - pattern.length()] * h) + line[i]) % 7;
            if (lineValue < 0) lineValue += 7;
        }
    }

    for ()
}