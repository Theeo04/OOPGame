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
        string special_attack_name;

	 public:
	 	Character(string name, int health, int attack_points, int defense_points,string special_attack_name)
		{
            this->name = name;
            this->health = health;
            this->attack_points = attack_points;
            this->defense_points = defense_points;
            this->special_attack_name = special_attack_name;
        }

        //functii pentru atac:

        void close_attack(Character& attacker, Character& target)
        {
        	attacker.attack_points=attacker.attack_points - (attacker.attack_points*20)/100;//celui care ataca i se va scadea 20% din puncte
        	target.health = target.health - (target.health*10)/100; //celui atacat i se va scadea 10% din viata
        	cout << attacker.name << " attack " << target.name << endl;
		}

		void far_attack(Character& attacker, Character& target)
		{
			attacker.attack_points=attacker.attack_points - (attacker.attack_points*30)/100;//celui care ataca i se va scadea 30% din puncte
        	target.health = target.health - (target.health*20)/100; //celui atacat i se va scadea 20% din viata
        	cout << attacker.name << " attack " << target.name << endl;
		}

		void special_attack(Character& attacker, Character& target)  //valoare random
		{
			//rand(time(0));
    		int numarMaxim = 40;
    		int random = rand() % (numarMaxim + 1);
    		attacker.attack_points=attacker.attack_points - 30;
        	target.health = target.health - random;
        	cout << attacker.name << " attack " << target.name << "with "<< attacker.special_attack_name << endl;
		}
		//poison
		void poison_attack(Character& attacker, Character& target)
		{
    		int numarMaxim = 100;
    		int random = rand() % (numarMaxim + 1);
    		if((random>=20)&&(random <= 40))//sansa de 20% ca target-ul sa fie otravit(-85) viata  
    		{
    			attacker.attack_points=attacker.attack_points - 50;
				target.health = target.health - 85;
			}
			cout << attacker.name << " poisoned " << target.name << " with -50 HP"<< endl;
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

class villain : public Character {
	public:
   		string weapon1;
   		string weapon2;

    public:
	 	villain(string name, int health, int attack_points, int defense_points, string weapon1, string weapon2, string special_attack_name) : Character(name, health, attack_points, defense_points, special_attack_name) 
	{
        this->weapon1 = weapon1;
        this->weapon2 = weapon2;
    }
        //attacker: villain
        //target: caracterul nostru
        
		//functii pentru atac:

        void attack1(villain& attacker, Character& target)
        {
        	attacker.attack_points=attacker.attack_points - (attacker.attack_points*20)/100;//celui care ataca i se va scadea 20% din puncte
        	target.health = target.health - (target.health*10)/100; //celui atacat i se va scadea 10% din viata
        	cout << attacker.name << " attack " << target.name << " with " << attacker.weapon1 <<" and received -" <<(target.health*10)/100 << " HP" <<  endl;
		}

		void attack2(villain& attacker, Character& target)
        {
        	attacker.attack_points=attacker.attack_points - (attacker.attack_points*30)/100;//celui care ataca i se va scadea 20% din puncte
        	target.health = target.health - (target.health*20)/100; //celui atacat i se va scadea 10% din viata
        	cout << attacker.name << " attack " << target.name << " with " << attacker.weapon2 <<" and received -" <<(target.health*20)/100 << " HP" <<  endl;
		}

		void special_attack(villain& attacker, Character& target)  //valoare random
		{
			//rand(time(0));
    		int numarMaxim = 40;
    		int random = rand() % (numarMaxim + 1);
    		attacker.attack_points=attacker.attack_points - 30;
        	target.health = target.health - random;
			cout << attacker.name << " attack " << target.name << " with " << attacker.special_attack_name <<" and received -" <<(target.health*20)/100 << " HP" <<  endl;
		}
		
		void receive_health(villain& receiver)
		{
			receiver.health = receiver.health + 20;
			receiver.defense_points = receiver.defense_points - 50;
		}
		
		void display_stats(villain& v)
		{
   			cout << "Name: " << v.name << endl;
   			cout << "Health: " << v.health << endl;
   			cout << "Attack points: " << v.attack_points << endl;
   			cout << "Defense points: " << v.defense_points << endl;
			cout << "First Weapon: " << v.weapon1 << endl;
			cout << "First Weapon: " << v.weapon2 << endl;
			cout << "Special Attack: " << v.special_attack_name << endl;
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
        	Ch1.poison_attack(Ch1,Ch2);
        if (alegere == 5)
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
        	Ch2.poison_attack(Ch2,Ch1);
        if (alegere == 5)
        	Ch2.receive_health(Ch2);
    }
}

//decizie story-mode

void decision2(int tura, Character& Ch, villain& v) {
    int alegere;
    cout << "Choose your attack: " << endl;
    cin >> alegere;

    if (tura % 2 == 0) { // randul lui Ch1
        if (alegere == 1) // close attack
            Ch.close_attack(Ch, v);
        if (alegere == 2)
            Ch.far_attack(Ch, v);
        if (alegere == 3)
            Ch.special_attack(Ch, v);
        if (alegere == 4)
        	Ch.receive_health(Ch);
    }
    else { // randul lui V1
        int numarMaxim = 100;
    	int random = rand() % (numarMaxim + 1);
    	if((random >=0)&&(random <=10)) // sansa de 10%
    	{
    		v.receive_health(v);
		}
		if((random >=11)&&(random <=40)) // sansa de 30%
    	{
    		v.special_attack(v,Ch);
		}
		if((random >=41)&&(random <=70)) // sansa de 30%
    	{
    		v.attack1(v,Ch);
		}
		if((random >=71)&&(random <=100)) // sansa de 30%
    	{
    		v.attack2(v,Ch);
		}
    }
}

void rules()
{
  cout << "Welcome to the game! Here are the rules:\n";
  cout << "- You will control two characters, each with their own health, attack points, and defense points.\n";
  cout << "- You will take turns attacking and defending, with each turn consisting of one attack and one defense.\n";
  cout << "- To attack, choose from one of five options: close attack-1, far attack-2, special attack-3, poison attack-4, receive health-5. Each attack will use up some of your attack points.\n";
  cout << "- To defend, choose from one of two options: receive health or increase defense points. Each defense will use up some of your defense points.\n";
  cout << "- The game is over when one of your characters runs out of health.\n";
  cout << "- Good luck!\n";
  cout << "\n";
}

void play_game1 (Character& Ch1,Character& Ch2) {
    Ch1.display_stats(Ch1);
    cout<<"\n";
    Ch2.display_stats(Ch2);

    const int rounds = 3;
    int tura;
    for (int i = 0; i < (rounds * 2) - 1 ; i++)
    {
        tura = i;
        cout<<"\n\n";
        cout <<"Round " << i + 1 << endl;
        cout<<"\n\n";
        decision(tura, Ch1, Ch2);
        Ch1.display_stats(Ch1);
        cout << "Remain ";
        cout<<"\n\n";
        Ch2.display_stats(Ch2);
        if(Ch1.health == 0)
        {
            break;
            cout << Ch2.name << " wins !";
        }
        if(Ch2.health == 0)
        {
            break;
            cout << Ch1.name << " wins !";
        }
    }
    if(Ch1.health > Ch2.health)
    {
        cout << Ch1.name << " wins !";
    }
    else
    {
        if(Ch1.health > Ch2.health)
        {
            cout << Ch1.name << " wins !";
        }
        else
        {
            cout << "Draw !";
        }
    }
    if(Ch1.health <= 0 ){
        cout << cout << Ch2.name << " wins !";;
    }
    if(Ch2.health <=0 ){
        cout << Ch1.name << " wins !";;
    }
}

bool play_game2(Character& Ch1, villain& v) {
    Ch1.display_stats(Ch1);
    cout<<"\n";
    v.display_stats(v);

    const int rounds = 3;
    int tura;
    for (int i = 0; i < (rounds * 2) - 1 ; i++)
    {
        tura = i;
        cout<<"\n";
        cout <<"Round " << i + 1 << endl;
        cout<<"\n\n";
        decision2(tura, Ch1, v);
        Ch1.display_stats(Ch1);
        cout<<"\n";
        v.display_stats(v);
        if(Ch1.health == 0)
        {
            return false;
            break;
        }
        if(v.health == 0)
        {
            return true;
        }
    }
    if(Ch1.health > v.health)
    {
        return true;
    }
    else
    {
        return false;
    }
    if(Ch1.health <= 0 ){
        return false;
        
    }
    if(v.health <=0 ){
        return true;
    }
}

int main()
{   
	rules();
    
	//alegere GameMod: 1-Story Mode ; 2-Player vs Player
    int gamemode;
    cout << "Choose your game mode: " << endl;
    cout<< "\n1 - Story Mode (vs AI)                   2 - Player vs Player" << endl;
    
	cin >> gamemode;
	bool verificare_defensiva;
	bool verificare_ofensiva;
    if(gamemode == 2)
    {
    	string name1;int health1;int attack_points1;int defense_points1;string special_attack_name1;
		string name2;int health2;int attack_points2;int defense_points2;string special_attack_name2;
		//introducere statusuri a primului jucator
		//afisaj reguli introducere date apoi intr-un do...while(bool)
		
		do
		{
			cout << "Introduce stats to create first character:";
			cout << "\n 	Name:";
			cin >> name1;
			cout << "\n 	HP: 120";
			health1 = 120; 
			cout << "\n 	Attack Points:";
			cin >> attack_points1;
			cout << "\n 	Defensive Points:";
			cin >> defense_points1;
			cout << "\n 	Name of Special Attack:";
			cin >> special_attack_name1;
			cout << "\n\n";
			//introducere statusuri celui de-al doilea jucator
			cout << "Introduce stats to create second character:";
			cout << "\n 	Name:";
			cin >> name2;
				cout << "\n 	HP: 120";
			health2 = 120; 
			cout << "\n 	Attack Points:";
			cin >> attack_points2;
			cout << "\n 	Defensive Points:";
			cin >> defense_points2;
			cout << "\n 	Name of Special Attack:";
			cin >> special_attack_name2;
			cout << "\n\n";
			if(attack_points1 > attack_points2)
			{
				if((attack_points1 > attack_points2 * 1.2) && (defense_points2 < defense_points1 * 1.2 ))
				{
					verificare_defensiva = false;
					verificare_ofensiva = false;
					cout << "The rules were not respected! Please re-enter the avatar data.";
				}
				else
				{
					verificare_defensiva = true;
					verificare_ofensiva = true;
				}	
			}
			if(attack_points2 > attack_points1)
			{
				if((attack_points2 > attack_points1 * 1.2) && (defense_points2 > defense_points1 * 1.2 ))
				{
					verificare_defensiva = false;
					verificare_ofensiva = false;
					cout << "The rules were not respected! Please re-enter the avatar data.";
				}
				else
				{
					verificare_defensiva = true;
					verificare_ofensiva = true;
				}	
			}
				
		}while((verificare_defensiva == false)||(verificare_ofensiva == false));
		Character Ch1(name1,health1,attack_points1,defense_points1,special_attack_name1);
		Character Ch2(name2,health2,attack_points2,defense_points2,special_attack_name2);
        play_game1(Ch1,Ch2);
    }

    if(gamemode == 1)
    {
    	string name;int health;int attack_points;int defense_points;string special_attack_name;
    	
    	cout << "Introduce stats to create your character: ";
		cout << "\n 	Name:";
		cin >> name;
		cout << "\n 	Name of Special Attack: ";
		cin >> special_attack_name;
		cout << "\n 	HP: 120";
		cout << "\n 	Attack Points: 100" ;
		cout << "\n 	Defensive Points:80";
		
    	
    	Character Ch(name, 120, 100, 80,special_attack_name);
        //declarare villain
        //villain(string name, int health, int attack_points, int defense_points, string weapon1, string weapon2, string special_attack_name)
        villain v1("Cessair", 90 , 100 , 1000 , "Dark Sword", "Brutal Core" ," Voice of Dark Souls");
        villain v2("Nirnasha", 130 , 120, 80 , "Consecration" , "Ashes", " Conqueror of the Storm");
        villain v3("Maleficent", 80, 95, 800, "Magical Staff", "Dark Magic", "Voice of Dark Souls");
        int wave = 3;
        
        cout<< "\n Now you face "<< v1.name << endl;
		bool next = play_game2(Ch,v1);
        if(next == true){
        	cout<<"\n";
        	cout<< v1.name << " wins";
		}
		else
		{
			cout<<"\n";
			cout<< Ch.name <<" wins";
			cout<< "\n Now you will face "<< v2.name << endl;
			next=play_game2(Ch,v2);
			if(next == false)
			{
				cout<<"\n";
				cout<< v2.name << " wins";
			}
			else
			{
				cout<<"\n";
				cout<< Ch.name <<" wins";
				cout<< "\n Now you will face "<< v3.name << endl;
				next=play_game2(Ch,v3);
				if(next == true)
				{
					cout<<"\n";
					cout<< "You won !";
				}
				else
				{
					cout<<"\n";
					cout<< v3.name << " wins";
				}
			}
		}
    }
    return 0;
}

