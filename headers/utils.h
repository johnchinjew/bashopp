/* START FILE
================================================================================================= */

#ifndef UTILS_H
#define UTILS_H




/* DEPENDENCIES
================================================================================================= */

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <fstream>

using std::cout;
using std::vector;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::ifstream;



/* FUNCTIONS
================================================================================================= */

// get random number from inclusive range
int random(int min, int max) {
  static bool first = true;
  if (first) {
    srand(time(NULL));
    first = false;
  }
  return min + (rand() % (max - min + 1));
}

// print with typewriter effect
void slow_print(string message, int ms_per_char) {
  for (int i = 0; i < message.length(); i++) {
    cout << message[i] << flush;
    sleep_for(milliseconds(ms_per_char));
  }
  cout << flush;
}

// print with natural speed and pauses
void say(string message) {
  sleep_for(milliseconds(random(400, 600)));
  slow_print(message, 50);
}

// get lines from text file as vector
vector<string> load_lines(string path) {
  vector<string> lines;
  string line;
  ifstream f_in (path);
  while (getline(f_in, line))
    lines.push_back(line);
  return lines;
}

// get project directories
string root_dir() { return "/Users/John/Desktop/zenbot/"; }
string assets_dir() { return root_dir() + "assets/"; }
string headers_dir() { return root_dir() + "headers/"; }



/* END FILE
================================================================================================= */

#endif
