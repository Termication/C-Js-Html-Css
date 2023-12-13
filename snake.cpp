#include <iostream>
#include <conio.h>
#include <windows.h>

bool gameOver;
const int width = 20;
const int height = 20;
int x, y;         // Snake head coordinates
int fruitX, fruitY;   // Fruit coordinates
int score;        // Player score
int tailX[100], tailY[100];   // Snake tail coordinates
int tailLength;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                std::cout << "#";
            if (i == y && j == x)
                std::cout << "O";
            else if (i == fruitY && j == fruitX)
                std::cout << "F";
            else
            {
                bool printTail = false;
                for (int k = 0; k < tailLength; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "o";
                        printTail = true;
                    }
                }
                if (!printTail)
                    std::cout << " ";
            }

            if (j == width - 1)
                std::cout << "#";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;
    std::cout << "Score:" << score << std::endl;
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
            gameOver = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < tailLength; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
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
    }

    if (x >= width) x = 0;
    else if (x < 0) x = width - 1;

    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;

    for (int i = 0; i < tailLength; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tailLength++;
    }
}


int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10); // Sleep for a short duration to control game speed
    }

    return 0;
}
