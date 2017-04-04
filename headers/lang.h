/* START FILE
================================================================================================= */

#ifndef LANG_H
#define LANG_H



/* DEPENDENCIES
================================================================================================= */

#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

#include "utils.h"

using std::istringstream;
using std::string;
using std::vector;
using std::regex;
using std::transform;



/* VARIABLES
================================================================================================= */

vector<string> nouns_dict = load_lines(assets_dir() + "nouns-dict.txt");



/* FUNCTIONS
================================================================================================= */

// get vector list of words from string
vector<string> as_words(string s) {
  vector<string> words;
  regex punc ("[[:punct:]]");
  s = regex_replace(s, punc, "");
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  istringstream s_in (s);
  string word;
  while (getline(s_in, word, ' '))
    words.push_back(word);
  return words;
}

// get vector list of normalized nouns from string
vector<string> extract_nouns(string s) {
  vector<string> words = as_words(s);
  vector<string> nouns;
  // for every word in the sentence
  for (int i = 0; i < words.size(); i++) {
    // for every noun from the dictionary
    for (int j = 0; j < nouns_dict.size(); j++) {
      string this_noun = nouns_dict[j];
      string word0 = words[i];
      // there is an immediate singular match
      if (word0 == this_noun) {
        nouns.push_back(word0);
      // might be a plural, strip and test
    } else if (word0.length() >= 3 && word0[word0.length()-1] == 's') {
        string word1 = word0;
        string word2 = word0;
        word1.erase(word1.end()-1);
        word2.erase(word2.end()-2, word2.end());
        // there is a singularized match
        if (word1 == this_noun || word2 == this_noun) {
          nouns.push_back(this_noun);
        }
      }
    }
  }
  return nouns;
}



/* END FILE
================================================================================================= */

#endif
