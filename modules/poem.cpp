/* START FILE
================================================================================================= */

#ifndef POEM_CPP
#define POEM_CPP



/* DEPENDENCIES
================================================================================================= */

#include <string>
#include <vector>
#include <regex>

#include "utils.cpp"

using std::string;
using std::vector;
using std::regex;
using std::regex_replace;



/* VARIABLES
================================================================================================= */

vector<string> n = load_lines(assets_dir() + "_n.txt");
vector<string> v = load_lines(assets_dir() + "_v.txt");
vector<string> adj = load_lines(assets_dir() + "_adj.txt");
vector<string> adv = load_lines(assets_dir() + "_adv.txt");
vector<string> prep = load_lines(assets_dir() + "_prep.txt");
vector<string> interj = load_lines(assets_dir() + "_interj.txt");
vector<string> line = load_lines(assets_dir() + "_line.txt");



/* FUNCTIONS
================================================================================================= */

string rand_n()      { return      n[random(0,      n.size()-1)]; }
string rand_v()      { return      v[random(0,      v.size()-1)]; }
string rand_adj()    { return    adj[random(0,    adj.size()-1)]; }
string rand_adv()    { return    adv[random(0,    adv.size()-1)]; }
string rand_prep()   { return   prep[random(0,   prep.size()-1)]; }
string rand_interj() { return interj[random(0, interj.size()-1)]; }
string rand_line()   { return   line[random(0,   line.size()-1)]; }

string custom_line(vector<string> key_nouns) {
  string l = rand_line();
  for (int i = 0; i < l.length(); i++) {
    int c = l[i] - '0';
    if (c > 0 && c <= 9) {
      if (c == 1) {
        if (random(1, 5) > 2) {
          string w = key_nouns[random(0, key_nouns.size()-1)];
          l.insert(i, w); i += w.length();
        } else {
          string w = rand_n(); l.insert(i, w); i += w.length();
        }
      }
      else if (c == 2) { string w = rand_v(); l.insert(i, w); i += w.length(); }
      else if (c == 3) { string w = rand_adj(); l.insert(i, w); i += w.length(); }
      else if (c == 4) { string w = rand_adv(); l.insert(i, w); i += w.length(); }
      else if (c == 5) { string w = rand_prep(); l.insert(i, w); i += w.length(); }
      else if (c == 6) { string w = rand_interj(); l.insert(i, w); i += w.length(); }
    }
  }
  regex d ("[0-9]");
  return regex_replace(l, d, "");
}

string custom_poem(int num_lines, vector<string> key_nouns) {
  string new_poem = "";
  for (int i = 0; i < num_lines; i++) {
    string cased_line = custom_line(key_nouns);
    cased_line[0] = toupper(cased_line[0]);
    new_poem += "\t" + cased_line + "\n";
  }
  return new_poem;
}



/* END FILE
================================================================================================= */

#endif
