// The same as team, but the transition to the characters will be according to the order of addition without distinguishing cowboys or ninjas
#pragma once
#include "Team.hpp"
namespace ariel
{
    class Team2 : public Team
    {
    public:
        // Constructor that initializes the team with the given leader
        Team2(Character *leader);
        // destructor
        /// attack() receives a pointer to an enemy group.
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
        void attack(Team *enemy);
        // print() method that prints all the team members.
        void print(); // pure virtual method that prints all the team members is different for each team
    };
}
