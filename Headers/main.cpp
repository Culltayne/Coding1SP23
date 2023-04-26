#include <iostream>
#include "enemy.h"
using namespace std;
int main() {
std::cout << "Hello!\n";

  enemy duke("Duke");
  duke.status();

  cout << "There was a storm! Duke loses 2 health!\n";
  duke.changeHealth(-2);
  cout << "Duke's health is now " << duke.getHealth() << ".\n";

  cout << "What would you like to name duke?\n";
  string input;
  cin >> input;
  duke.setName(input);
  cout << "Duke is now named " << duke.getName() << ".\n";
}