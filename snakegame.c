#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <time.h>

int i, j, height = 20, width = 40;
int gameover, score;
int x, y, fruitX, fruitY, flag;

int tailX[100], tailY[100];
int countTail = 0;

void setup()
{
    gameover = 0;
    x = height / 2;
    y = width / 2;

label1:
    fruitX = rand() % 20;
    if (fruitX == 0)
        goto label1;

label2:
    fruitY = rand() % 40;
    if (fruitY == 0)
        goto label2;

    score = 0;
}

void draw()
{
    clear();
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                printw("#");
            else
            {
                if (i == x && j == y)
                    printw("0");
                else if (i == fruitX && j == fruitY)
                    printw("*");
                else
                {
                    int isPrinted = 0;
                    for (int k = 0; k < countTail; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printw("o");
                            isPrinted = 1;
                        }
                    }

                    if (isPrinted == 0)
                        printw(" ");
                }
            }
        }
        printw("\n");
    }
    printw("Score: %d", score);
    refresh();
}

void input()
{
    timeout(0);
    int ch = getch();
    switch (ch)
    {
    case 'a':
        flag = 1;
        break;
    case 's':
        flag = 2;
        break;
    case 'd':
        flag = 3;
        break;
    case 'w':
        flag = 4;
        break;
    case 'x':
        gameover = 1;
        break;
    }
}

void algorithm()
{
    usleep(10000);
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < countTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    if (x < 0 || x >= height || y < 0 || y >= width)
        gameover = 1;

    for (int i = 0; i < countTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;

    if (x == fruitX && y == fruitY)
    {
    label3:
        fruitX = rand() % 20;
        if (fruitX == 0)
            goto label3;

    label4:
        fruitY = rand() % 40;
        if (fruitY == 0)
            goto label4;
        score += 10;
        countTail++;
    }
}

int main()
{
    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);

    // Seed for random number generation
    srand(time(NULL));

    setup();
    while (!gameover)
    {
        input();
        algorithm();
        draw();
    }

    endwin();
    return 0;
}
