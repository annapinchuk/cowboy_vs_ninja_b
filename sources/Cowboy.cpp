#include "Cowboy.hpp"
namespace ariel
{
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), bullets_left(6) {}
    void Cowboy::shoot(Cowboy *other)
    {
        if (this->isAlive() && this->bullets_left > 0)
        {
            other->hit(10);
            this->bullets_left--;
        }
    } // if the cowboy is alive and has bullets, reduce the hit_points of the character by 10 and reduce the number of bullets by 1

    bool Cowboy::hasboolets()
    {
        return this->bullets_left > 0;
    } // returns true if the cowboy has bullets, false otherwise

    void Cowboy::reload()
    {
        if (this->isAlive())
        {
            this->bullets_left = 6;
        }
    } // if the cowboy is alive, reload the number of bullets to 6, otherwise do nothing

    void Cowboy::print()
    {
        if (!this->isAlive())
        {
            cout << "C (" << this->getName() << ") ";
            this->getLocation().print();
            cout << endl;
        }
        else
        {
            cout << "C " << this->getName() << " " << this->getHealthpoints() << " ";
            this->getLocation().print();
            cout << endl;
        }

    } // prints the name of the character, the hp, and the point where the character is. If the character dies the hit points will not be printed, and the character's name will appear in parentheses.

}