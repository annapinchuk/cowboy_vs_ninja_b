#include "Character.hpp"
namespace ariel {
    Character::Character(string name , Point location , int hit_points) : name(name), location(location), hit_points(hit_points){}
    string Character::getName(){return this->name;}
    Point Character::getLocation(){return this->location;}
    int Character::getHealthpoints(){return this->hit_points;}
    void Character::setName(string name){
        this->name = name;
    }
    void Character::setLocation(Point location){
        this->location = location;
    }
    void Character::setHealthpoints(int hit_points){
        this->hit_points = hit_points;
    }
    bool Character::isAlive(){return this->hit_points > 0;} // returns true if the character is alive, false otherwise more than 0 hit_points
    double Character::distance(Character *c){
        return this->location.distance(c->getLocation());
     }; // calculate the distance between two characters
    void Character::hit(int damage){
        this->hit_points -= damage;
    }; // reduce the hit_points of the character by the given damage
}