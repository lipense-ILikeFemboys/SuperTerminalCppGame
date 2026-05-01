#include <iostream>
#include <cmath>
#include <ctime>
#include <thread>
#include <chrono>
#include <string>
#include <windows.h>

// 01/05/2026, friday, 8:39AM
// RETURNED 9:06AM. Since 839am i did nothing.
// 1048am and i finished the getInput system.

// NICE! FINISHED! 4:15PM RIGHT NOW!
//From the same day, May 01 2026, Friday of no-work...28 degrees celcius
// in Belo Horizonte, Minas Gerais (MG), Brazil. Weather: Clear.
// Weather Forecast?: to stay clear.
// By Felipe Chan.
using namespace std;



int fps = 12;

string playerSymbol = "O";
string worldSymbol = "*";
string coinSymbol = "Z";

int screenSizeX = 60;
int screenSizeY = 30;

int coins = 0;

int playerX;
int playerY;
int coinX;
int coinY;

bool running = false;

int playerStepX = 1;
int playerStepY = 1;
int runInPlayerStepX = 2;
int runInPlayerStepY = 2;

template <typename any>
void print(any what){
	
	cout << what << '\n';
	
}


void wait(double time){
	
	this_thread::sleep_for(chrono::duration<double>(time));
	
}


double mag(double value1, double value2){
	
	return sqrt(pow(value1, 2) + pow(value2, 2));
	
}


int gai(){ // get any input (keyboard or mouse) (928am)
	
	for(int key = 1; key < 256; key++){
		
		if(GetAsyncKeyState(key)){
			
			return key;
			
		}
		
	}
	
	return false;
	
}


void placeCoin(){
	
	int newCoinX;
	int newCoinY;
	
	do{
		newCoinX = (rand() % screenSizeX);
	}while(newCoinX == coinX);
		do{
		newCoinY = (rand() % screenSizeY);
	}while(newCoinX == coinX);
		
	coinX = newCoinX;
	coinY = newCoinY;
	
}




void checkInput(){
	
	int pressedKeyCode = gai();
	
	
	
	
	if(pressedKeyCode == 65){ // letter A, btw, its 303pm now
		
		
		if(running){
			
			if(playerX >= runInPlayerStepX){
				
				playerX -= runInPlayerStepX;
				
			} else if(playerX >= playerStepX){
				
				playerX -= playerStepX;
				
			} else if(playerX >= 1){
				
				playerX -= 1;
				
			}
			
		} else if(playerX >= playerStepX){
			
			playerX -= playerStepX;
			
		} else if(playerX >= 1){
			
			playerX -= 1;
			
		}
		
		
	}
	
	
	
	if(pressedKeyCode == 68){ // letter D, btw, its 327pm now
		
		
		if(running){
			
			if(playerX <= screenSizeX - runInPlayerStepX){
				
				playerX += runInPlayerStepX;
				
			} else if(playerX <= screenSizeX - playerStepX){
				
				playerX += playerStepX;
				
			} else if(playerX <= screenSizeX - 1){
				
				playerX += 1;
				
			}
			
		} else if(playerX <= screenSizeX - playerStepX){
			
			playerX += playerStepX;
			
		} else if(playerX <= screenSizeX - 1){
			
			playerX += 1;
			
		}
		
		
	}
	
	
	
	if(pressedKeyCode == 87){ // letter W, btw, its 348PM now
		
		
		if(running){
			
			if(playerY >= runInPlayerStepY){
				
				playerY -= runInPlayerStepY;
				
			} else if(playerY >= playerStepY){
				
				playerY -= playerStepY;
				
			} else if(playerY >= 1){
				
				playerY -= 1;
				
			}
			
		} else if(playerY >= playerStepY){
			
			playerY -= playerStepY;
			
		} else if(playerY >= 1){
			
			playerY -= 1;
			
		}
		
		
	}
	
	
	
	if(pressedKeyCode == 83){ // letter S, btw, its 340PM now
		
		
		if(running){
			
			if(playerY <= screenSizeY - runInPlayerStepY){
				
				playerY += runInPlayerStepY;
				
			} else if(playerY <= screenSizeY - playerStepY){
				
				playerY += playerStepY;
				
			} else if(playerY <= screenSizeY - 1){
				
				playerY += 1;
				
			}
			
		} else if(playerY <= screenSizeY - playerStepY){
			
			playerY += playerStepY;
			
		} else if(playerY <= screenSizeY - 1){
			
			playerY += 1;
			
		}
		
		
	}
	
	
	
	
	if(pressedKeyCode == 16){ // Any SHIFT counts. Btw, 354pm now
		running = !running;
	}
	
	
}



void renderWorld(){	//358pm now

string phrase = "Coins: " + to_string(coins);

print("/////////////////////////");
	
	for(int y = 0; y <= screenSizeY; y++){
		
		string line;
		
		for(int x = 0; x <= screenSizeX; x++){
			
			if(x == playerX && y == playerY){
				line.append(playerSymbol);
			} else if(x == coinX && y == coinY){
				line.append(coinSymbol);
			} else {
				line.append(worldSymbol);
			}
			
		}
		
		print(line);
	}
	
	print("/////////////////////////");
	print(phrase);
	print("/////////////////////////");
	
}




void checkPhysics(){
	
	if(playerX == coinX && playerY == coinY){
		coins++;
		placeCoin();
	}
	
}





int main(){
	
	srand(time(NULL));
	placeCoin();
	
	playerX = floor(screenSizeX / 2);
	playerY = floor(screenSizeY / 2);
	
	
	double frameTime = 1.0 / fps;
	
	while(true){
		
		wait(frameTime);
		checkInput();
		checkPhysics();
		renderWorld();
		
	}
	
	
	return 0;
}