#pragma once
#include "Character.hpp"
using namespace std;
// instance of character successor class
namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets_left;
    public:
        // Constructor that initializes the Cowboy object with the given name, location , 110 hit_points and 6 bullets
        Cowboy(string name, Point location);
        ~Cowboy();
        void shoot (Character* other);  // if the cowboy is alive and has bullets, reduce the hit_points of the character by 10 and reduce the number of bullets by 1 ,
        // otherwise do nothing
        bool hasboolets();          // returns true if the cowboy has bullets, false otherwise
        void reload();              // if the cowboy is alive, reload the number of bullets to 6, otherwise do nothing
        string print();             // prints the name of the character, the hp, and the point where the character is. If the character dies the hp will not be printed, and the character's name will appear in parentheses.
    };
}