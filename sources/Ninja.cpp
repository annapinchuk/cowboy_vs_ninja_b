#include "Ninja.hpp"
namespace ariel
{
    Ninja::Ninja(string name, Point location, int hit_points, int speed) : Character(name, location, hit_points, 2), speed(speed) {}
    Ninja::~Ninja() {}
    // receives a pointer to the enemy and moves towards the enemy. The ninja advances a distance equal to its speed
    void Ninja::move(Character *enemy)
    {
        if (this->isAlive())
        {
            double distance = this->getLocation().distance(enemy->getLocation());
            if (distance > this->speed)
            {
                Point p = this->getLocation().moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
                this->setLocation(p);
            }
            else
            {
                this->setLocation(enemy->getLocation());
            }
        }
    } // Receives a pointer to the enemy. If the ninja is alive and the enemy is less than 1 meter away deal 40 damage to the enemy. Otherwise, no damage will be dealt to the enemy.
    void Ninja::slash(Character *enemy)
    {
        if (this == enemy || !enemy->isAlive() || !this->isAlive())
        {
            throw std::runtime_error("can't shoot");
        }
        double distance = this->getLocation().distance(enemy->getLocation());
        if (distance <= 1)
        {
            enemy->hit(40);
        }
    }
    string Ninja::print()
    {
        string s;
        if (!this->isAlive())
        {
            s = "N (" + this->getName() + ") ";
        }
        else
        {
            s = "N " + this->getName() + " " + to_string(this->getHealthpoints()) + " ";
        }
        s += this->getLocation().print();
        return s;
    }
}