#include <iostream> //text to and from console
#include <cstdlib> //the c standard library for rand()
#include <ctime> //this is for seeding rand
using namespace std;

int main() {
  std::cout << "Hello World!\n";

  //testing randomness
//seed rand()
  srand(time(0));
  cout << "Random number: " <<rand() << ".\n";
  cout << "Random number: " <<rand() << ".\n";
  cout << "Random number: " <<rand() << ".\n";
  cout << "Random number: " <<rand() << ".\n";

 //modulus operator gives the remainder of a division problem.
  //output
  cout << "13 / 10 = " << 13 / 10 << ".\n";
//remainder
  cout << "With a remainder of " << 13 % 10 << ".\n";

  //
  cout << "num between 1 and 10 (inclusive) = " <<rand() % 10 + 1 << ".\n";
  cout << "num between 1 and 10 (inclusive) = " <<rand() % 10 + 1 << ".\n";



  //give me a random number between 1970 and 2020
  //rand() 51 + 1970
  //rand() range((max-min) +1) +min
  
  cout << "num between 1970 and 2020 (inclusive) = " <<rand() % 51 + 1970 << ".\n";
  
//declare and define one of each
  //boolean, integer, float, string
int score = 3000; 
string playerName = "Coltaine";
float earthGravity = -2.0; //in meters per second
bool playerIsGrounded = true;

  bool debug = true; //if true give more info
  
if(debug) {
  cout << "[DEBUG IS ON]\n";
  
  }


int input;
int min = 1;
int max = 10;

  //created a min max under the input, need input before "min max"
cout << "I am thinking of a number between "<<min<<" and "<<max<<".\n";
//cout << "Can you give me a number between "<<min<<" and "<<max<<"?\n";

  cout << "Can you guess it?\n";

  int theNumber = rand() % ((max - min) + 1) + min;

  if(debug) {
    cout << "[the number is " << theNumber << "]\n";
  }

  
cin >> input;

  //now we test the input
// if players guess (input) is less than
if(input < theNumber) {
  cout << "That number is too low. \n";
}
  
  
  //else if = or statement
  //same but if greater than 10
else if(input > theNumber) {
  cout << "You still suck... that's too high! \n";
}
 //else... if they get it right,  tell them they're doing it right 
  else {
    cout << "That's it! Good job\n";
  }





  
}