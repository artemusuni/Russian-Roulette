#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;

int main() {
	srand(time(nullptr));
	bool YOUR_LIFE = 1;	// 1==alive, 0==dead
	bool OPONENT_LIFE = 1;
	bool TURN;	//who goes first
	
	int chaimber_bullets = 6;
	

	cout << "Throw the coin, my friend!(press any key)" << endl;
	cin.get();
       	TURN = rand() % 2;	//who goes first	
	
	if(TURN) {
		cout << "This time you were lucky, it is your turn" << endl;
	}
	else {
		cout << "Better luck next time, the oponent goes first" << endl;
	}	


	while(YOUR_LIFE == 1 && OPONENT_LIFE == 1) {	//the game loop
		int real_bullet = rand() % chaimber_bullets;
		if(TURN) {
			cout << "You take the gun and have 2 choices: \n\n 0-shoot yourself(next turn is also yours) \n\n anything else- shoot him\n\n waiting for your input...\n" << endl;
		       	char answer; //NOT SURE IF THIS WILL WORK
			cin >> answer;
			if(answer != '0') { //shoot him
				cout << "You point the gun on him, press the trigger and.." << endl;
				this_thread::sleep_for(chrono::seconds(3));
				if((rand() % chaimber_bullets) == real_bullet) {
					cout << "The gun FIRES and you see how his body is slowly falling from the chair...\n" << endl;
					chaimber_bullets--;
					OPONENT_LIFE = 0;
					TURN = 0;
				}
				else {
					cout << "The gun DOES NOT FIRE.\n" << endl;
					chaimber_bullets--;
					TURN = 0;
				
				
				}

			
			}
			else {	//shoot yourself
				cout << "You point the gun on your head, close your eyes and.." << endl;
				this_thread::sleep_for(chrono::seconds(2));
				cout << "...";
				this_thread::sleep_for(chrono::seconds(2));
				cout << "..." << endl;
				this_thread::sleep_for(chrono::seconds(2));
				
				if((rand() % chaimber_bullets) == real_bullet) {
					cout << "You feel someking of a weakness, falling to the ground....you died" << endl;
					chaimber_bullets--;
					YOUR_LIFE = 0;
					TURN = 1;
				}
				else {
					cout << "You hear the sound, open your eyes and you are STILL ALIVE!" << endl;
					chaimber_bullets--;
					TURN = 1;
				}

			}			





		}
		else {
			cout << "He is taking the gun and points at you..." << endl;
			cout << "You close your eyes... you hear the click of the gun and...\n" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "..." << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "..." << endl;
			this_thread::sleep_for(chrono::seconds(2));
			if((rand() % chaimber_bullets) == real_bullet) {
				cout << "YOU DIED\n" << endl;
				chaimber_bullets--;
				YOUR_LIFE = 0;
			}
			else {
				cout << "You slowly open your eyes and wow, you are still alive. There was no bullet in the chaimber\n" << endl;
				chaimber_bullets--;
				TURN = 1;
			
			}

		
		
		
		}




	
	}

	if(YOUR_LIFE == 1 && OPONENT_LIFE == 0) {	//if you win
		cout << "CONGRATULATIONS, YOU WON YOUR LIFE BACK, NOW LIVE LIKE YOU SHOUD." << endl;	

	}
	else if(YOUR_LIFE == 0 && OPONENT_LIFE == 1) {	//if you lose
		cout << "THIS IS NOT THE END, GREAT SOULS NEVER DIE" << endl;

	}

	//WILL ADD AN EASTER EGG
	// if you only shout yourself and it is the last bullet






}
