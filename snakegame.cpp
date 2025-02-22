#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

enum Direction{STOP = 0,LEFT,RIGHT,UP, DOWN};
Direction dir;
bool gameover;
const int height = 20;
const int width = 20;
int headx, heady, fruitx, fruity, score;
int tailx[100],taily[100];
int tail_length;

void setup();
void draw();
void input();
void logic();

int main()
{
    char start;
    cout << "\t-------------------------" << endl;
    cout << "\t\t---Start Game---" << endl;
    cout << "\t-------------------------" << endl;
    cout << "Press 's' to Start Game: ";
    cin >> start;
    if (start == 's')
    {
        setup();
        while (!gameover)
        {
            draw();
            input();
            logic();
            Sleep(30); // This function make loops slow for better performance.
            system("cls");
            
        }
    }
}

void setup()
{
    gameover = false;
    dir = STOP;
    headx = width / 2; // for print snake head in center so divided by 2.
    heady = height / 2;
    fruitx = rand() % width; // for print fruit random.
    fruity = rand() % height;
    score = 0;
    //tail_length=0;
}

void draw()
{
    system("cls");
    // Upper boarder:
    cout << "\t\t";
    for (int i = 0; i < width - 8; i++)
    {
        cout << "||";
    }
    cout << endl;

    // Snake, fruit, space and side borders:
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Left Boarder:
            if (j == 0)
            {
                cout << "\t\t||";
            }
            // snake head:
            if (i == headx && j == heady)
            {
                cout << "O";
            }
            // Fruit:
            else if (i == fruity && j == fruitx)
            {
                cout << "*";
            }
            // space,snake Tail:
            else
            {
                bool print = false;
                for (int k = 0; k < tail_length; k++)
                {
                    if (tailx[k] == j && taily[k] == i) // Tail
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " "; // space
                }
            }
            // right Boarder
            if (j == width - 1)
            {
                cout << "||";
            }
        }
        cout << endl;
    }
    // Lower boarder:
    cout << "\t\t";
    for (int i = 0; i < width - 8; i++)
    {
        cout << "||";
    }
    cout << endl;
    cout << "\t\t\tScore: " << score << endl;
}

void input()
{
    if (_kbhit())
        switch (getch())
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

        default:
            break;
        }
}

void logic()
{
  // Tail Logic:
    int prevx = tailx[0]; // First tail at zero index on x axis or y axis.
    int prevy = taily[0];
    int prev2x, prev2y; // For more tails we made two more variables.
    tailx[0] = heady; // Now first tail link with snake headx or heady axis.
    taily[0] = headx;
    for (int i = 1; i < tail_length; i++)
    {
        prev2x = tailx[i]; // second tail at 1 index on x axis or y axis.
        prev2y = taily[i];
        tailx[i] = prevx; // Now second tail link with first tail x or y axis.
        taily[i] = prevy;
        prevx = prev2x; // Now first tail store second tail.
        prevy = prev2y;
    }
    // Direction Logic:
    switch (dir)
    {
    case LEFT:
        heady--;
        break;
    case RIGHT:
        heady++;
        break;
    case UP:
        headx--;
        break;
    case DOWN:
        headx++;
        break;
    default:
        break;
    }

    // Touch wall logic:
    if (headx >= width) // if headx cross left wall than headx becomes zero.
    {
        headx = 0;
    }
    else if (headx < 0) // now headx less than zero so snake headx return from right wall.
    {
        headx = width - 1;
    }
    if (heady >= height)
    {
        heady = 0;
    }
    else if (heady < 0)
    {
        heady = height - 1;
    }

    // snake bite itself:
    for (int i = 0; i < tail_length; i++)
    {
        if (tailx[i] == headx && taily[i] == heady)
        {
            gameover = true;
        }
    }

    // Snake eat Fruit:
    
        if (headx == fruity && heady == fruitx)
        {
            score += 10;
            fruitx = rand()%width;
            fruity = rand()%height;
            tail_length++;
        }
}