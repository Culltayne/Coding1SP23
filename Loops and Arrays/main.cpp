#include <cstdlib>  //the c standard library for rand()
#include <ctime>    //this is for seeding rand
#include <iostream> //text to and from console
using namespace std;

int main() {
  srand(time(0));
  cout << "num between 10 and 50 (exclusive) = " << rand() % 39 + 11 << ".\n";

  // for loop
  //  for(initialization; test; action) {code}
  for (int counter = 0; counter < 10; counter++) {
    cout << counter << "\n";
  }

  // default for loop
  //  for(int i = 0; i < 100; i +=2)
  //    {
  //      cout << i << "\n";
  //    }

  // strings are an ordered list of characters
  string name = "Darth Vader";

  cout << "The first letter in " << name << " is " << name[0] << ".\n";
  // name[0] is the first element in the list

  cout << "There are " << name.size() << " characters in the name. \n";

  for (int i = 0; i < name.size(); i++) {
    cout << name[i] << "\n";
  }

  cout << "With a e s t h e t i c : \n\n";

  for (int i = 0; i < name.size(); i++) {
    cout << name[i] << " ";
  }
  cout << "\n";

  string phrase = "Cottonmouth";
  // 'break' and 'continue'
  // let's use 'continue' to skip all of the vowels
  cout << "without vowels:\n";
  for (int i = 0; i < phrase.size(); i++) {
    if (phrase[i] == 'a' || phrase[i] == 'e' || phrase[i] == 'u' ||
        phrase[i] == 'i' || phrase[i] == 'o' || phrase[i] == 'y') {
      continue;
    }

    cout << phrase[i];
  }

  cout << "\n";

  // arrays
  // an array is an ordered list of variable with a set size.
  string inv[5];

  inv[0] = "Tape";
  inv[1] = "String";
  inv[2] = "Paper";
  inv[3] = "Quarter";
  inv[4] = "Phone";

  cout << "the first item in our inventory is " << inv[0] << ".\n";
  cout << "\nYour inventory:\n";
  for (int i = 0; i < 5; i++) {
    if (inv[i] == "") {
      continue;
    }
    cout << inv[i] << "\n";
  }

  // a collection initializer creates the array with the vaues.

  string colors[] = {"Red", "Green", "Blue", "Yellow", "Black"};

  cout << "The first color is " << colors[0] << ".\n";

  bool pickedColor = false;
  while (pickedColor == false) {
    cout << "\n\nWhat color would you like your car to be?\n";

    string input;
    cin >> input;

    for (int i = 0; i < 5; i++) {
      if (colors[i] == input) {
        cout << "You have chosen a " << colors[i] << " car!\n";
        pickedColor = true;
        break;
      }

      // how do we know if we havent found it?
      if (i + 1 == 5)
      // next loop wont happen, we're at the end of the list
      {
        cout << input << " is not an available color\n";
      }
    }
  }
}