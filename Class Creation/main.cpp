#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Animal {
public:
    string species;
    int age;
    float weight;
    string color;

    int health;
    int hunger;

    Animal(string givenSpecies = "Unknown", int givenAge = 0, float givenWeight = 0.0, string givenColor = "Unknown", int givenHealth = 100) {
        species = givenSpecies;
        age = givenAge;
        weight = givenWeight;
        color = givenColor;
      
        health = givenHealth;
        hunger = 0;
    }

    void status() {
        cout << "Species: " << species << "\n";
        cout << "Age: " << age << "\n";
        cout << "Weight: " << weight << "\n";
        cout << "Color: " << color << "\n";
      
        cout << "Health: " << health << "\n";
        cout << "Hunger: " << hunger << "\n";
    }

    void eat(float foodWeight) {
        weight += foodWeight;
        health += foodWeight * 5;
      
        if (health > 100) {
            health = 100;
        }
      
        hunger -= foodWeight * 10;
        if (hunger < 0) {
            hunger = 0;
        }
        cout << species << " ate " << foodWeight << " kg of food and now has " << weight << " kg weight, " << health << " health, and " << hunger << " hunger.\n";
    }

                //added eating and hunger after turn in, realized I couldnt turn in a second attempt.
    void play() {
        health -= 5;
        if (health < 0) {
            health = 0;
        }
      
        hunger += 10;
        if (hunger > 100) {
            hunger = 100;
        }
      
        cout << species << " played and now has " << health << " health, and " << hunger << " hunger.\n";
    }
};


int main() {
    srand(time(0));
    
    Animal animals[5] = {
        Animal("Dog", 3, 20.0, "Brown", 90),
        Animal("Cat", 2, 4.0, "Orange", 80),
        Animal("Hamster", 1, 0.2, "White", 85),
        Animal("Ferret", 2, 1.5, "Black", 75),
        Animal("MoleRat", 4, 0.5, "Gray", 70)
    };

    for (int i = 0; i < 5; i++) {
        animals[i].status();
        cout << endl;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int action = rand() % 2; 

            if (action == 0) {
                animals[i].play();
            } 
            
            else {
                float foodWeight = (rand() % 4 + 1) / 2.0; 
                animals[i].eat(foodWeight);
                 }

          
        animals[i].status();
          
        cout << endl;
    }
}
return 0;
}