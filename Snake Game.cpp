// Snake Game Project		06/14/2020

#include<iostream>
#include<cstdlib>
#include<conio.h> 
#include<Windows.h>
using namespace std;
bool gameover;
const int width = 20;
const int length = 20;
int x, y, fruitx, fruity, score;
int tailx[100], taily[100];
int ntail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;


void Setup()
{
	gameover = false;
	dir = STOP;
	x = width / 2;
	y = length / 2;
	fruitx = rand() % width;
	fruity = rand() % length;
	score = 0;
}

void Draw()
{

	system("CLS");
	
	for(int i = 0; i < width+ 2; i++)
	{
		cout << "#";	
	}
	
	cout << endl;
	
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < width; j++)
		{
			if (j==0)
			{
				cout << "#";
			}
			
			if(i == y && j == x)
			{
					cout << "~";
			}
			else if(i == fruity && j == fruitx)
			{
					cout << "$";
			}
			
			else
			{
				bool print = false;
				for(int k = 0; k < ntail; k++ )
				{
					if(tailx[k] == j && taily[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if(!print)
				{
					cout << " ";
				}
				
			}
				
			
			if(j == width-1)
			{
				cout << "#";
			}
				
		}
		cout << endl;
	}
	
	for(int i = 0; i < width+2; i++)
	{
		cout << "#";	
	}
	cout << endl << "Score:" << score << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameover = true;
				break;
		}
	}	
}

void Logic()
{
	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for(int i = 1; i < ntail; i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	switch (dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
		
		}
	//	if(x > width || x < 0 || y > length || y < 0)
	//		gameover = true;
			
		if(x >= width) x = 0; else if (x <= 0) x = width - 1;
		if(y >= length) y = 0; else if (y < 0) y = length - 1;
		
		for(int i =0; i < ntail; i++)
		{
			if(tailx[i] == x && taily[i] == y)
			gameover = true;
		}
			
		if (x == fruitx && y == fruity)
		{
			score += 10;
			fruitx = rand() % width;
			fruity = rand() % length;
			ntail++;
			
		}
		
}

int main()
{
	Setup();
	while (!gameover)
	{
		Draw();
		Input();
		Logic();
		Sleep(0);
	}
	return 0;
}


