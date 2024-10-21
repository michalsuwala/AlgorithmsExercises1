#include <iostream>
#include <regex>
#include <string>

int main() {

    std::string s = "Witaj, proszę skontaktować się ze mną pod adresem email: doe@example.com\n"
                        "Możesz też napisać na adres support@company.pl.\n"
                        "Oto jeszcze jeden adres: alice_smith123@gmail.com. Dziękuję!";

    std::regex pattern(R"(\b[^@\s]*+@[A-Za-z0-9.-]+\.[a-z]{1,}\b)");

    std::sregex_iterator it(s.begin(), s.end(), pattern);
    std::sregex_iterator koniec;

    while(it != koniec) {
        std::smatch dopasowanie = *it;
        std::cout << dopasowanie.str() << '\n';
        ++it;
    }

    return 0;
}


let text1 = "kamilslimak"
let text2 = "kamilszymon"



function checkPalindrom(txt) {
  for(let i = 0, j = txt.length - 1; i < txt.length; ++i, --j) {
	if(txt[i] !== txt[j]) return false
  }
  return true
}

console.log(checkPalindrom(text1))
console.log(checkPalindrom(text2))

let res = "";
let k = 0, l = 0;
for(let i = 0; i < str.length; ++i) {
  res += String.fromCharCode(arr[k][l]);

  if(str[i] === 'r') ++l;
  else if(str[i] === 'l') --l;
  else if(str[i] === 'd') ++k;
  else --k;
}
res += String.fromCharCode(arr[k][l]);

console.log(res)