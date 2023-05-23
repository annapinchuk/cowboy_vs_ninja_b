#include "Character.hpp"
namespace ariel
{
    Character::Character(string name, Point location, int hit_points, int type) : name(name), location(location), hit_points(hit_points), type(type) {}
    Character::~Character() {}
    string Character::getName() { return this->name; }
    int Character::getType() { return this->type; }
    Point Character::getLocation() { return this->location; }
    int Character::getHealthpoints() { return this->hit_points; }
    void Character::setIsPlaying(int isPlaying) { this->is_playing = isPlaying ; }
    int Character::getIsPlaying() { return this->is_playing; }
    void Character::setName(string name)
    {
        this->name = name;
    }
    void Character::setLocation(Point location)
    {
        this->location = location;
    }
    void Character::setHealthpoints(int hit_points)
    {
        this->hit_points = hit_points;
    }
    bool Character::isAlive() { return this->hit_points > 0; } // returns true if the character is alive, false otherwise more than 0 hit_points
    double Character::distance(Character *c)
    {
        return this->location.distance(c->getLocation());
    } // calculate the distance between two characters
    void Character::hit(int damage)
    {
        if (damage < 0)
            throw std::invalid_argument("damage must be positive");
        this->hit_points -= damage;
    } // reduce the hit_points of the character by the given damage
    string Character::print()
    {
        string s = "";
        return s;
    } // prints the name of the character, the hp, and the point where the character is. If the character dies the hit points will not be printed, and the character's name will appear in parentheses.
}
