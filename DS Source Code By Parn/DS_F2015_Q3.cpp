// Fall 2015 - Question 3
// Reducible Lexicon
// Suphanut Jamonnak

#include <iostream>
#include <string>

// Lexicon class with contains function
class Lexicon {
  public:
    bool contains (const std::string &str) const {
      // word with 'a', 'e', 'i', 'o', 'u' is english words
      if (str.find_first_of("aeiou") != std::string::npos) {
        return true;
      } else {
        return false;
      }
    }
};

// isReducible function
bool isReducible (std::string &word, const Lexicon &l) {
  // base case
  if (word.length() == 1 && l.contains(word)) {
    return true;
  } else {
    // recursive case
    for (int i = 0; i < word.length(); i++) {
      std::string copy = word;
      copy.erase(i,1);
      // if copy contain a english words
      if (l.contains(copy)) {
        std::cout << copy << std::endl;
        // recursive: function that calling itself
        if (isReducible(copy, l)) {
          return true;
        }
      }
    }
    return false;
  }
}

// Test
void checkReducible(Lexicon & lex, std::string word) {
    if(isReducible(word,lex)) {
        std::cout << word << " IS reducible" << std::endl;
    } else {
        std::cout << word << " is NOT reducible" << std::endl;
    }
}

// Test
int main () {
  std::string s;
  std::cout << "Enter english word (e.g. complecting): ";
  std::cin >> s;
  Lexicon lex;
  checkReducible(lex,s);
}
