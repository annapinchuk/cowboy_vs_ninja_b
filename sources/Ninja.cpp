#include "Ninja.hpp"
namespace ariel {
    Ninja::Ninja(string name, Point location, int hit_points, int speed) : Character(name, location, hit_points), speed(speed) {}
    Ninja::~Ninja() {}
    // receives a pointer to the enemy and moves towards the enemy. The ninja advances a distance equal to its speed
    void Ninja::move(Ninja *enemy) {
        if (this->isAlive()) {
            double distance = this->getLocation().distance(enemy->getLocation());
            if (distance > this->speed) {
                double x = this->getLocation().getX() + (this->speed * (enemy->getLocation().getX() - this->getLocation().getX()) / distance); // x = x0 + (v * (x1 - x0) / d)
                double y = this->getLocation().getY() + (this->speed * (enemy->getLocation().getY() - this->getLocation().getY()) / distance); // y = y0 + (v * (y1 - y0) / d)
                this->setLocation(Point(x, y));
            } else {
                this->setLocation(enemy->getLocation());
            }
        }
    } // Receives a pointer to the enemy. If the ninja is alive and the enemy is less than 1 meter away deal 40 damage to the enemy. Otherwise, no damage will be dealt to the enemy.
    void Ninja::slash(Ninja *enemy) {
        if (this->isAlive()) {
            double distance = this->getLocation().distance(enemy->getLocation());
            if (distance <= 1) {
                enemy->hit(40);
            }
        }
    }
    void Ninja::print() {
        if (!this->isAlive()) {
            cout << "N (" << this->getName() << ") ";
            this->getLocation().print();
            cout << endl;
        } else {
            cout << "N " << this->getName() << " " << this->getHealthpoints() << " ";
            this->getLocation().print();
            cout << endl;
        }
    }
}