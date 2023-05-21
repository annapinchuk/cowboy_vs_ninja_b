#pragma once
#include "Character.hpp"
// instance of character successor class
namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed; // the speed of the ninja

    public:
        // Constructor that initializes the Ninja object with the given name, location , hit_points and speed
        Ninja(string name, Point location, int hit_points, int speed) : Character(name, location, hit_points), speed(speed){};
        ~Ninja(){}; // destructor
        void move (Character *enemy){};  // receives a pointer to the enemy and moves towards the enemy. The ninja advances a distance equal to its speed
        void slash(Character *enemy){};  // Receives a pointer to the enemy. If the ninja is alive and the enemy is less than 1 meter away,
        // print
        string print(){return "0";}; // prints the name of the character, the hp, and the point where the character is. If the character dies the hp will not be printed, and the character's name will appear in parentheses.
        // the ninja will deal 40 damage to the enemy. Otherwise, no damage will be dealt to the enemy.
    };
}