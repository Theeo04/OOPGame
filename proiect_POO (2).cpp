#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character{
	public:
		string name;
		int health;
		int attack_points;
        int defense_points;
	 
	 public:
	 	Character(string name, int health, int attack_points, int defense_points) 
		{
            this->name = name;
            this->health = health;
            this->attack_points = attack_points;
            this->defense_points = defense_points;
        }
        
        //functii pentru atac:
        
        void close_attack(Character& attacker, Character& target)
        {
        	attacker.attack_points=attacker.attack_points - 20;
        	target.health = target.health - 10;
        	cout << attacker.name << " ataca pe " << target.name << endl;
		}
		
		void far_attack(Character& attacker, Character& target)
		{
			attacker.attack_points=attacker.attack_points - 10;
        	target.health = target.health - 5;
		}
		
		void special_attack(Character& attacker, Character& target)  //valoare random
		{
			//rand(time(0)); 
    		int numarMaxim = 40;
    		int random = rand() % (numarMaxim + 1);
    		attacker.attack_points=attacker.attack_points - 30;
        	target.health = target.health - random;
		} 
		
		//functii defensiva
		
		void receive_health(Character& receiver)
		{
			receiver.health = receiver.health + 20;
			receiver.defense_points = receiver.defense_points - 50;
		}
		
		//afisarea atributelor
		
		void display_stats(Character& player) 
		{
   			cout << "Name: " << player.name << endl;
   			cout << "Health: " << player.health << endl;
   			cout << "Attack points: " << player.attack_points << endl;
   			cout << "Defense points: " << player.defense_points << endl;
		}
};

void decision(int tura, Character& Ch1, Character& Ch2)
{
    int alegere;
    cout << "Choose your attack:" << endl;
    cin >> alegere;

    if (tura % 2 == 0) // randul lui ch1 
    {
        if (alegere == 1) // close attack
            Ch1.close_attack(Ch1,Ch2);
        if (alegere == 2)
            Ch1.far_attack(Ch1,Ch2);
        if (alegere == 3)
            Ch1.special_attack(Ch1,Ch2);
        if (alegere == 4)
        	Ch1.receive_health(Ch1);

    } 
	else // randul lui ch2
    {
        if (alegere == 1) // close attack
            Ch2.close_attack(Ch2,Ch1);
        if (alegere == 2)
            Ch2.far_attack(Ch2,Ch1);
        if (alegere == 3)
            Ch2.special_attack(Ch2,Ch1);
        if (alegere == 4)
        	Ch2.receive_health(Ch1);
    }
}

void rules()
{
  cout << "Welcome to the game! Here are the rules:\n";
  cout << "- You will control two characters, each with their own health, attack points, and defense points.\n";
  cout << "- You will take turns attacking and defending, with each turn consisting of one attack and one defense.\n";
  cout << "- To attack, choose from one of three options: close attack-1, far attack-2, or special attack-3. Each attack will use up some of your attack points.\n";
  cout << "- To defend, choose from one of two options: receive health or increase defense points. Each defense will use up some of your defense points.\n";
  cout << "- The game is over when one of your characters runs out of health.\n";
  cout << "- Good luck!\n";
}

int main()
{
	rules();

    //definirea caracterelor
    Character Ch1("Player_1", 100, 120, 80);
    Character Ch2("Player_2", 100, 80, 120);
    
    Ch1.display_stats(Ch1);
    cout<<"\n";
    Ch2.display_stats(Ch2);

    const int rounds = 3;
    int tura;
    for (int i = 0; i < (rounds * 2) - 1 ; i++)
    {
    	tura = i;
    	cout<<"\n";
    	cout <<"Runda a " << i + 1 << "-a" << endl;
    	cout<<"\n\n";
        decision(tura, Ch1, Ch2);
        Ch1.display_stats(Ch1);
        cout<<"\n";
        Ch2.display_stats(Ch2);
        if(Ch1.health == 0)
        {
        	break;
        	cout << "Player 2 wins !";
		}
		if(Ch2.health == 0)
        {
        	break;
        	cout << "Player 1 wins !";
		}
    }
    if(Ch1.health > Ch2.health)
    {
    	cout << "Player 1 wins !";
	}
	else
	{
		if(Ch1.health > Ch2.health)
   		{
    		cout << "Player 1 wins !";
		}
		else
		{
			cout << "Draw !";
		}
	}
	
    return 0;
}

