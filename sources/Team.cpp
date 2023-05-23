#include "Team.hpp"
namespace ariel
{
    // This class is a group of up to ten fighters, where a fighter can be a ninja or a warrior.
    // Each group is assigned a leader who is one of the fighters. When a group is created, it gets a leader pointer.
    // Going over all members of the group (for attacking, printing, or comparing) will always be done in the following order:
    // first go over all the cowboys, then go over all the ninjas.
    // Within each group, the transition will be made according to the order in which the characters were added.
    // When searching for the closest character, and two characters are at the same distance, the first character that was checked between them will be selected.
    Team::Team(Character *leader) : leader(leader), members()
    {
        if (this->leader->getIsPlaying())
        {
            throw std::runtime_error("The leader is already playing");
        }
        add(leader);
    }
    // destructor frees the memory allocated to all members of the group
    Team::~Team()
    {
        for (size_t i = 0; i < members.size(); i++)
        {
            members[i]->setIsPlaying(false);
            delete members[i];
        }
    }
    // set the leader of the team
    void Team::setLeader(Character *chara) { this->leader = chara; }
    // Adding add() takes a pointer to a cowboy or ninja, and adds it to the matching group.
    void Team::add(Character *member)
    {
        if (member == nullptr)
        {
            throw std::invalid_argument("The member is null");
        }
        if (members.size() >= 10 || member->getIsPlaying())
        {
            throw std::runtime_error("The group is full");
        }
        else
        {
            members.push_back(member);
            member->setIsPlaying(true);
        }
    }
    // stillAlive() returns an integer number of group members remaining alive.
    int Team::stillAlive()
    {
        int count = 0;
        for (size_t i = 0; i < members.size(); i++)
        {
            if (members[i]->isAlive())
            {
                count++;
            }
        }
        return count;
    }
    // get closest alive member
    Character *Team::getClosest(Character *leader)
    {
        double min = std::numeric_limits<double>::max();
        Character *closest = nullptr;
        for (size_t i = 0; i < members.size(); i++)
        {
            if (members[i]->isAlive() && leader->distance(members[i]) < min)
            {
                min = leader->distance(members[i]);
                closest = members[i];
            }
        }
        return closest;
    }
    // attack() receives a pointer to an enemy group.
    // Attacking the enemy group will be done in the following way:
    // First check if the leader of the attacking group is alive.
    // Otherwise, a new leader must be chosen, who is the living character closest (in terms of location) to the dead leader.
    // Then the group will choose a victim from among the enemy group.
    // The victim is the member of the living enemy group who is closest to the leader of the attacking group.
    // All living members of the attacking group will attack the chosen victim.
    // Cowboys who have bullets in their guns will shoot the victim, and cowboys who don't have bullets will load their weapons.
    // Ninjas within 1 meter of the victim will kill the victim, and ninjas further away will advance towards the victim.
    // At each stage, if the victim is dead, a new victim will be chosen (which will be, again, the living enemy character closest to the leader of the attacking group).
    // If there are no living members in the attacking group or the enemy group the attack will end
    void Team::attack(Team *enemy)
    {
        if (enemy == nullptr)
        {
            // throw invalid argument exception
            throw std::invalid_argument("The enemy team is null");
        }
        if (this->leader->isAlive())
        {
            Character *victim = enemy->getClosest(this->leader);
            if (victim == nullptr)
            {
                // trow run time  exception
                throw std::runtime_error("There is no enemy to attack");
            }
            // cowboys attack first and then ninjas
            for (size_t i = 0; i < members.size(); i++)
            {
                if (!victim->isAlive()) // if the victim is dead, a new victim will be chosen
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
                    { // cast the character to cowboy
                        Cowboy *cowboy = dynamic_cast<Cowboy *>(members[i]);
                        if (cowboy->hasboolets())
                        {
                            cowboy->shoot(victim);
                        }
                        else
                        {
                            cowboy->reload();
                        }
                    }
                }
            }
            for (size_t i = 0; i < members.size(); i++)
            {
                if (!victim->isAlive()) // if the victim is dead, a new victim will be chosen
                {
                    victim = enemy->getClosest(this->leader);
                    if (victim == nullptr)
                    {
                        return;
                    }
                }
                if (members[i]->isAlive())
                {
                    if (members[i]->getType() == 2)
                    {
                        // cast the character to ninja
                        Ninja *ninja = dynamic_cast<Ninja *>(members[i]);
                        if (ninja->distance(victim) <= 1)
                        {
                            ninja->slash(victim);
                        }
                        else
                        {
                            ninja->move(victim);
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
                // trow run time  exception
                throw "There is no leader to attack";
                return;
            }
            this->setLeader(newLeader);
            attack(enemy);
        }
    }
    // print() goes through all the characters in the group and prints all their details
    void Team::print()
    {
        // first the cowboys and then the ninja
        for (size_t i = 0; i < members.size(); i++)
        {
            if (members[i]->isAlive())
            {
                if (members[i]->getType() == 1)
                {
                    members[i]->print();
                }
            }
        }
        for (size_t i = 0; i < members.size(); i++)
        {
            if (members[i]->isAlive())
            {
                if (members[i]->getType() == 2)
                {
                    members[i]->print();
                }
            }
        }
    }
}