#ifndef INCLUDE
#define INCLUDE
#include <iostream>			//输入输出流
#include <cstdlib>			//标准库
#include <unistd.h>			//延时函数库
#include <stdio.h>			//getchar()	
#include <ctime>			//时间函数
#include <termios.h>		//终端设置

using namespace std;

#define MAX_X 20
#define MAX_Y 30

bool flag = false;
bool slow = false;
bool autogame = true;
int maze[MAX_X][MAX_Y];		//迷宫

class stack_of_maze
{
private:
    //记录迷宫坐标
    struct node {
        int x;
        int y;
        char direction;  	//上一步路径（如何来的）
        node* next;
    };
    node* head;
public:
    //code
    stack_of_maze();

    ~stack_of_maze();

    void push(int xx,int yy,char ddirection);

    node* pop(int& xx,int& yy);

    void print();
};
void createMaze();
void printMaze();
void check(stack_of_maze &s);

void move();
char getch();

void autoMove(stack_of_maze &s);
#endif