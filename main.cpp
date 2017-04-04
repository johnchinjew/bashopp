/* DEPENDENCIES
================================================================================================= */

#include <iostream>
#include <string>
#include <vector>

#include "headers/utils.h"
#include "headers/poem.h"
#include "headers/lang.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;



/* FORWARDS
================================================================================================= */

string name();
void say();



/* MAIN
================================================================================================= */

int main() {

  string do_repeat = "";

  say("Greetings, " + name() + ".");
  say("\nI am ZENBOT. ");
  say("I possess the wisdom of a thousand moons!");
  say("\n\nI sense ");
  say("a great conflict within you...");

  while(do_repeat != "N" && do_repeat != "n") {
    string response = "";
    vector<string> response_nouns;

    cout << endl;
    say("Tell me, ");
    say("what is it that so troubles your heart? ");
    cout << flush;
    cin.ignore();
    getline(cin, response);

    response_nouns = extract_nouns(response);

    while (response_nouns.size() == 0) {
      say("Be specific " + name() + "! ");
      say("What troubles you? ");
      cin.ignore();
      getline(cin, response);
      response_nouns = extract_nouns(response);
    }

    say("\nI see, ");
    say("I see " + name() + "...");
    say("\nBut, you musn't forget!\n\n");
    say(custom_poem(random(6, 8), response_nouns));
    say("\nSo sayeth ZENBOT!");

    say("\nSo " + name() + ", ");
    say("is there anything else on your mind? [Y/N] ");
    cout << flush;
    cin >> do_repeat;
  }

  say("\nAs it should be " + name() + ", hasten on your way.");
  cout << endl;
  return 0;
}



/* FUNCTIONS
================================================================================================= */

string name() {
  vector<string> n;
  n.push_back("young one");
  n.push_back("young learner");
  n.push_back("young grasshopper");
  n.push_back("my pupil");
  n.push_back("my padawan");
  n.push_back("my apprentice");
  n.push_back("mere mortal");
  n.push_back("weary traveler");
  return n[random(0, n.size()-1)];
}
