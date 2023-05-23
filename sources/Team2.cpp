#include "Team2.hpp"
namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader) {}

    //  prints all the team members
    void Team2::print()
    {
        for (size_t i = 0; i < this->members.size(); i++)
        {
            this->members[i]->print();
        }
    }
    // attack with no difference between the members
    void Team2::attack(Team *enemy)
    {
        if (enemy == nullptr)
        {
            throw std::invalid_argument("The enemy team is null");
        }
        if (this->leader->isAlive())
        {
            Character *victim = enemy->getClosest(this->leader);
            if (victim == nullptr)
            {
                return;
            }
            for (size_t i = 0; i < members.size(); i++)
            {
                if (!victim->isAlive())
                {
                    victim = enemy->getClosest(this->leader);
                    if (victim == nullptr)
                    {
                        return;
                    }
                }
                if (members[i]->isAlive())
                {
                    if (members[i]->getType() == 1)
                    {
                        Cowboy *c = dynamic_cast<Cowboy *>(members[i]);
                        if (c->hasboolets())
                        {
                            c->shoot(victim);
                        }
                        else
                        {
                            c->reload();
                        }
                    }
                    else
                    {
                        Ninja *n = dynamic_cast<Ninja *>(members[i]);
                        if (n->distance(victim) <= 1)
                        {
                            n->slash(victim);
                        }
                        else
                        {
                            n->move(victim);
                        }
                    }
                }
            }
        }
        else
        {
            Character *newLeader = this->getClosest(this->leader);
            if (newLeader == nullptr)
            {
                throw "There is no enemy to attack";
                return;
            }
            this->setLeader(newLeader);
            attack(enemy);
        }
    }
}