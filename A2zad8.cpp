#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    std::string pattern;
    std::getline(std::cin, pattern);

    int ps[pattern.length()];
    ps[0] = 0;

    int l = 0, i = 1;
    while (i < pattern.length()) {
        if (pattern[l] == pattern[i]) {
            ++l;
            ps[i] = l;
            ++i;
        }
        else if (pattern[l] != pattern[i] && l != 0) {
            l = ps[l - 1];
        }
        else {
            ps[i] = l;
            ++i;
        }
    }


    i = 0;
    l = 0;

    bool f = false, res = false;
    char c;
    while (f || std::cin.get(c) && c != '\n') {
        if (c == '.' || c == '?' || c == '!' || c == ',' || c == '-' || c == ':' || c == ';') c = '.';
        else if (c > 96 && c < 123) c = 'a';
        else if (c > 64 && c < 91) c = 'A';
        else if (c > 47 && c < 58) c = '0';

        f = false;
        if (c == pattern[l]) {
            ++l;
            if (l == pattern.length()) {
                res = true;
                std::cout << "T";
                break;
            }
        }
        else if (l > 0) {
            l = ps[l - 1];
            f = true;
        }
    }

    if (!res) std::cout << 'N';

    return 0;
}