#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character {
	public:
		string name;
        int health;
        int attack_points;
        int defense_points;
        int special_attribute;
    public:
        Character(string name, int health, int attack_points, int defense_points, int special_attribute) {
            this->name = name;
            this->health = health;
            this->attack_points = attack_points;
            this->defense_points = defense_points;
            this->special_attribute = special_attribute;
        }

    void ranged_attack(Character& target) 
	{
    	int hit_chance = rand() % 100 + 1;
    	if (hit_chance > target.defense_points) 
		{
			int damage = this->attack_points + rand() % 10 + 1;
		}
		target.health -= damage;
	}

    void melee_attack(Character& target) 
	{
	    int hit_chance = rand() % 100 + 1;
    	if (hit_chance > target.defense_points) 
		{
      		int damage = this->attack_points + rand() % 5 + 1;
	        target.health -= damage;
    		if (target.health <= 0) 
			{
        		target.is_dead = true;
        	}
    	} 
		else 
		{
			cout << "The attack missed!\n";
    	}
	}

        void special_ability(Character& target) {
    // verificam daca jucatorul are destula energie pentru a folosi abilitatea
    if (this->energy < 10) {
        std::cout << "Not enough energy to use special ability!\n";
        return;
    }

    // scadem energie
    this->energy -= 10;

    // efectul abilita?ii speciale
    int effect = rand() % 3;
    switch(effect) {
        case 0:
            // blocheaza urmatorul atac al ?intei
            target.is_blocked = true;
            std::cout << "Target's next attack is blocked!\n";
            break;
        case 1:
            // face daune over time ?intei
            target.is_poisoned = true;
            std::cout << "Target is now poisoned!\n";
            break;
        case 2:
            // cre?te atacul caracterului curent
            this->attack_points += 5;
            std::cout << "Character's attack is increased!\n";
            break;
    }
}
};

void fight(Character& character1, Character& character2) {
    while (character1.health > 0 && character2.health > 0) {
        // începerea luptei
        character1.ranged_attack(character2);
        character2.melee_attack(character1);

        // verificam daca primul personaj are abilitatea speciala ?i o aplicam daca este cazul
        if (character1.special_attribute > 0) {
            character1.special_ability(character2);
        }

        // verificam daca al doilea personaj are abilitatea speciala ?i o aplicam daca este cazul
        if (character2.special_attribute > 0) {
            character2.special_ability(character1);
        }
    }

    // afi?am mesajul de final al luptei ?i declaram câ?tigatorul
    if (character1.health <= 0) {
        cout << character2.name << " a câ?tigat lupta împotriva lui " << character1.name << "!" << endl;
    } else {
        cout << character1.name << " a câ?tigat lupta împotriva lui " << character2.name << "!" << endl;
    }
}


