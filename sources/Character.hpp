#pragma once
#include <string>
#include "Point.hpp"
#include <stdexcept>

using namespace std;
namespace ariel
{
    class Character
    {
    private:
        string name;
        Point location;
        int hit_points;
        int type; // 1 for cowboy and 2 for ninja
        int is_playing; // 1 if the character is playing, 0 otherwise
    public:
        // Constructor that initializes the Character object with the given name, location and hit_points
        Character(string name, Point location, int hit_points, int type);
        ~Character();
        // getters and setters
        int getType();
        string getName();
        Point getLocation();
        int getHealthpoints();
        int getIsPlaying();
        void setIsPlaying(int is_playing);
        void setName(string name);
        void setLocation(Point location);
        void setHealthpoints(int hit_points);
        bool isAlive();                // returns true if the character is alive, false otherwise more than 0 hit_points
        double distance(Character *c); // calculate the distance between two characters
        virtual string print();                  // prints the name of the character, the hp, and the point where the character is. If the character dies the hp will not be printed, and the character's name will appear in parentheses.
        // Before the name will appear a letter indicating the type of character: N for ninja and C for cowboy.
        void hit(int damage); // reduce the hit_points of the character by the given damage
    };
}