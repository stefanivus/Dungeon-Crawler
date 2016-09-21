#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

using namespace std;

void print_map(string map[10][10])//Print map function
{
	
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
      	{
		   cout << map[j][i];
	    }
	    cout << "\n";
	}
}

class enemy{//Enemy class
	public:
	    int enemy_dir;//Defining enemy variables
	    int enemy_x;
	    int enemy_y;
	    void define(string map[10][10])//Randomly placing enemies on the map, used at start of game
	    {
	    	int x,y;
	    	x = rand() % 8 + 1;
	    	y = rand() % 8 + 1;
	    	while (map[x][y] == "T" || map[x][y] == "E")
	    	{
	    		x = rand() % 8 + 1;
	    	    y = rand() % 8 + 1;
	    	}
	    	this->enemy_x = x;
			this->enemy_y = y; 
	    	map[x][y] = "E";
	    }
	    void move(string map[10][10],int x, int y)//Moves enemy by one space
		{
			enemy_dir = rand() % 4 + 1;//Random direction enemy will move in
			
			while((enemy_dir == 1 && enemy_y == 0) || (enemy_dir == 2 && enemy_y == 9) || (enemy_dir == 3 && enemy_x == 0) || (enemy_dir == 4 && enemy_x == 9))//If direction is off the map, change it
			{
			  enemy_dir = rand() % 4 + 1;	
			}
			while((enemy_dir == 1 && map[enemy_x][enemy_y-1] != "-" && map[enemy_x][enemy_y-1] != "P") || //If direction goes into trap or another enemy, change
			      (enemy_dir == 2 && map[enemy_x][enemy_y+1] != "-" && map[enemy_x][enemy_y+1] != "P") || 
			      (enemy_dir == 3 && map[enemy_x-1][enemy_y] != "-" && map[enemy_x-1][enemy_y] != "P") || 
			      (enemy_dir == 4 && map[enemy_x+1][enemy_y] != "-" && map[enemy_x+1][enemy_y] != "P"))
			    {
			    	if (map[enemy_x][enemy_y-1] != "-" && map[enemy_x][enemy_y+1] != "-" && map[enemy_x-1][enemy_y] != "-" && map[enemy_x+1][enemy_y] != "-")//If there are no empty spaces to move to
		            { 
		                 if (map[enemy_x][enemy_y-1] != "P" && map[enemy_x][enemy_y+1] != "P" && map[enemy_x-1][enemy_y] != "P" && map[enemy_x+1][enemy_y] != "P")//And Player isnt one of the surrounding blocks
		                 {
		                       break;//Ditch the loop
		                 }
	                }
	               enemy_dir = rand() % 4 + 1;
	               
	               while((enemy_dir == 1 && enemy_y == 0) || (enemy_dir == 2 && enemy_y == 9) || (enemy_dir == 3 && enemy_x == 0) || (enemy_dir == 4 && enemy_x == 9))//If direction is off the map, change it
			       {
			          enemy_dir = rand() % 4 + 1;	
			       }
	               
	            }
				
		 if (map[enemy_x][enemy_y-1] == "-" || map[enemy_x][enemy_y+1] == "-" || map[enemy_x-1][enemy_y] == "-" || map[enemy_x+1][enemy_y] == "-" || map[enemy_x][enemy_y-1] == "P" || map[enemy_x][enemy_y+1] == "P" || map[enemy_x-1][enemy_y] == "P" || map[enemy_x+1][enemy_y] == "P")//If there is at least one movable space that is empty or a Player 
		 { 
		    if (enemy_dir == 1)//If direction is 1 go up
		    {
		       	map[enemy_x][enemy_y] = "-";
		        enemy_y -= 1;
	           	map[enemy_x][enemy_y] = "E";
	                
		    }
		    else if(enemy_dir == 2)//If direction is 2 go down
		    {
		    	map[enemy_x][enemy_y] = "-";
		        enemy_y += 1;
	        	map[enemy_x][enemy_y] = "E";
		    }
		    else if(enemy_dir == 3)//If direction is 3 go left
		    {
		    	map[enemy_x][enemy_y] = "-";
		        enemy_x -= 1;
	        	map[enemy_x][enemy_y] = "E";
		    }
		    else if(enemy_dir == 4)//If direction is 4 go right
		    {
		    	map[enemy_x][enemy_y] = "-";
		        enemy_x += 1;
	        	map[enemy_x][enemy_y] = "E";
		    }
	     }
	     else//If unable to move, do nothing
	     {
	     	return;
	     }
	    }

};
	


int main()
{  
while(true)//Perma game loop
{
    //Defining variables
	string map[10][10];
	int i,j,x,y;
	string pl_name = "P";
	int game = 0;
	string dir;
	string up = "U";
	string down = "D";
	string left = "L";
	string right = "R";
	int pl_x = 0;
	int pl_y = 0;
	srand(time(NULL));
	for(i=0;i<10;i++)//Defining map
	{
		for(j=0;j<10;j++)
      	{
		   map[i][j] = "-";
	    }
	}
	for(i=0;i<7;i++)//Defining traps
	{
	    y = rand() % 8 + 1;
		x = rand() % 8 + 1;
		map[x][y] ="T";
	}
	map[9][9] = "X";//Defining treasure
	map[pl_x][pl_y] = pl_name;//Defining player position
	enemy enemy1;//Defining enemies from class
	enemy enemy2;
	enemy enemy3;
	enemy enemy4;
	enemy enemy5;
	enemy enemy6;
	enemy enemy7;
	enemy1.define(map);
	enemy2.define(map);
	enemy3.define(map);
	enemy4.define(map);
	enemy5.define(map);
	enemy6.define(map);
	enemy7.define(map);
	
	print_map(map);//Prints map
	cout << "\n\n\n\n                         Welcome to Dungeon Crawler!\n\n"  <<endl;
	cout << "COMMANDS:\nMove up = U\nMove down = D\nMove left = L\nMove right = R\n\n";
	cout << "SYMBOLS: \nP = Player(you)\nE = Enemy\nT = Trap\nX = Treasure\n- = Empty space\n\n";
	cout << "RULES: \nYour objective is to move your character through the dungeon and reach the treasure \nIf you run into an enemy or trap you die\nEnemies move one space per turn\nTraps stay in place \n\n";
	cout << "Press 1 when you are ready to start: ";
	cin >> game;
	while(game != 1)
	{
		cin >> game;
	}
	
while(game == 1)//Start game loop
{
	cout << "\n\n\n\n";
	print_map(map);//Print map
	enemy1.move(map,enemy1.enemy_x,enemy1.enemy_y);//Moving enemies
	enemy2.move(map,enemy2.enemy_x,enemy2.enemy_y);
	enemy3.move(map,enemy3.enemy_x,enemy3.enemy_y);
	enemy4.move(map,enemy4.enemy_x,enemy4.enemy_y);
	enemy5.move(map,enemy5.enemy_x,enemy5.enemy_y);
	enemy6.move(map,enemy6.enemy_x,enemy6.enemy_y);
	enemy7.move(map,enemy7.enemy_x,enemy7.enemy_y);
	if(map[pl_x][pl_y] == "E")//If player is on same spot as Enemy , game over
	{
		game = 0;
		cout << "\nEnemy kills player";
	 	cout << "\nGAME OVER"<< endl;
	 	getch();
	 	break;
		
	}
	
	cout << "\n Move where?(U=up,D=down,L=left,R=right): ";
	cin >> dir;
	while((dir != up && dir != down && dir != left && dir != right) || //If player types invalid command or tries to go off map
	      (dir == up && pl_y == 0 )|| 
	      (dir == down && pl_y == 9) || 
	      (dir == left && pl_x == 0) || 
	      (dir == right && pl_x == 9))
	{
		cout << "Invalid direction"<<endl;
		cout << "\n Move where?(U=up,D=down,L=left,R=right):";
	    cin >> dir;
	}
	
	
	
    if (dir == up)//If UP chosen
	{
	 if(map[pl_x][pl_y-1] == "T")//If step on trap, game over
	 {
	 	game = 0;
	 	cout << "\nPlayer steps on trap";
	 	cout << "\nGAME OVER"<< endl;
	 	getch();
	 	break;
	 }
	 else if(map[pl_x][pl_y-1] == "X")//If step on treasure, you win
	 {
	 	game = 0;
	 	cout << "\nPlayer takes treasure";
	 	cout << "\nYOU WIN!"<< endl;
	 	getch();
	 	break;
	 }
	 else if(map[pl_x][pl_y-1] == "E")//If step on enemy, game over
	 {
	 	game = 0;
	 	cout << "\nEnemy kills player";
	 	cout << "\nGAME OVER"<< endl;
	 	getch();
	 	break;
	 }
	 else//Move up
	 {
		map[pl_x][pl_y] = "-";
		pl_y -= 1;
		map[pl_x][pl_y] = pl_name;
		}
	}
	else if (dir == down)//Repeat for all directions
	{
	 if(map[pl_x][pl_y+1] == "T")
	 {
	 	game = 0;
	 	cout << "\nPlayer steps on trap";
	 	cout << "\nGAME OVER"<< endl;
	 	getch();
	 	break;
	 }
	 else if(map[pl_x][pl_y+1] == "X")
	 {
	 	game = 0;
	 	cout << "\nPlayer takes treasure";
	 	cout << "\nYOU WIN!"<< endl;
	 	getch();
	 	break;
	 }
	 else if(map[pl_x][pl_y+1] == "E"){
	 	game = 0;
	 	cout << "\nEnemy kills player";
	 	cout << "\nGAME OVER"<< endl;
	 	getch();
	 	break;
	 }
	 else
	 {
		map[pl_x][pl_y] = "-";
		pl_y += 1;
		map[pl_x][pl_y] = pl_name;
     }
	}
	else if (dir == left)
	{
	 if(map[pl_x-1][pl_y] == "T")
	 {
	 	game = 0;
	 	cout << "\nPlayer steps on trap";
	 	cout << "\nGAME OVER"<< endl;
	 	getch();
	 	break;
	 }
	 else if(map[pl_x-1][pl_y] == "X")
	 {
	 	game = 0;
	 	cout << "\nPlayer takes treasure";
	 	cout << "\nYOU WIN!"<< endl;
	 	getch();
	 	break;
	 }
	 else if(map[pl_x-1][pl_y] == "E"){
	 	game = 0;
	 	cout << "\nEnemy kills player";
	 	cout << "\nGAME OVER"<< endl;
	 	getch();
	 	break;
	 }
	 else
	 {
		map[pl_x][pl_y] = "-";
		pl_x -= 1;
		map[pl_x][pl_y] = pl_name;
     }
	}
	else if (dir == right)
	{
	 if(map[pl_x+1][pl_y] == "T")
	 {
	 	game = 0;
	 	cout << "\nPlayer steps on trap";
	 	cout << "\nGAME OVER"<< endl;
	 	getch();
	 	break;
	 }
	 else if(map[pl_x+1][pl_y] == "X")
	 {
	 	game = 0;
	 	cout << "\nPlayer takes treasure";
	 	cout << "\nYOU WIN!"<< endl;
	 	getch();
	 	break;
	 }
	 else if(map[pl_x+1][pl_y] == "E"){
	 	game = 0;
	 	cout << "\nEnemy kills player";
	 	cout << "\nGAME OVER"<< endl;
	 	getch();
	 	break;
	 }
	 else
	 {
		map[pl_x][pl_y] = "-";
		pl_x += 1;
		map[pl_x][pl_y] = pl_name;
	 }
	}

	
}

}
	return 0;
}


