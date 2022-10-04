#include"maze.h"

bool flag = false;
bool slow = false;
bool autogame = true;
int maze[MAX_X][MAX_Y];		//迷宫

stack_of_maze::stack_of_maze()
{
    //初始化
    head = NULL;
}

stack_of_maze::~stack_of_maze()
{
    node* p = head;
    //逐个删除
    while(head!=NULL) {
        head = head->next;
        delete p;
        p = head;
    }
}

void stack_of_maze::push(int xx,int yy,char ddirection)
{
    //定义一个新的节点
    node* new_node = new node;
    //赋值
    if(new_node!=NULL) {
        new_node->x = xx;
        new_node->y = yy;
        new_node->direction = ddirection;
        new_node->next = NULL;
        // 判断是否为空，如果为空则直接把新节点赋值给栈，否则添加到栈顶
        if(head==NULL)
            head = new_node;
        else {
            new_node->next = head;
            head = new_node;
        }
    } else
        cout<<"内存分配失败"<<endl;

}

stack_of_maze::node* stack_of_maze::pop(int& xx,int& yy)
{
    if(head!=NULL) {
        node* p = head;
        head = head->next;
        xx = p->x;
        yy = p->y;
        delete p;
    }
    return head;
}

void stack_of_maze::print()
{
    if(head!=NULL) {
        node* p = head;
        while(p!=NULL) {
            cout<<" "<<p->x<<" "<<p->y<<" "<<p->direction<<endl;
            p = p->next;
        }
    } else
        cout<<"栈为空，打印失败"<<endl;
}

void createMaze()
{
    int maxway = MAX_X * MAX_Y;		//最大通路
    int x,y;

    //先填充迷宫
    for(x=0; x<MAX_X; x++)
        for(y=0; y<MAX_Y; y++)
            maze[x][y] = 1;

    //随机函数种子，以时间为参数
    srand((unsigned)time(NULL));
    //随机构建迷宫通路
    for(int i=0; i<maxway; i++) {
        x = rand() % (MAX_X-2) + 1;
        y = rand() % (MAX_Y-2) + 1;
        maze[x][y] = 0;
    }

    maze[1][1] = 0; 				//入口
    maze[MAX_X-2][MAX_Y-2] = 0;		//出口

    maze[0][1] = 3;
    maze[MAX_X-1][MAX_Y-2] = 0;
}

void printMaze()
{
    int x,y;
    //清屏，如果是windows环境使用system("cls")
    system("clear");
    //打印地图
    vector<string> mark{"  ", "墙", "x ", "↓ ", "→ ","↑ ", "← ", "我"};
    for(x=0; x<MAX_X; x++) {
        for(y=0; y<MAX_Y; y++) {
            int pos = maze[x][y];
            cout << mark[pos];
        }
        cout<<endl;
    }
    //是否选择慢速游戏
    if(slow) {
        sleep(1);	//延时函数
    }
}

void check(stack_of_maze &s)
{
    //备份地图
    int temp[MAX_X][MAX_Y];
    for(int x=0; x<MAX_X; x++)
        for(int y=0; y<MAX_Y; y++)
            temp[x][y] = maze[x][y];

    int x=1,y=1;					//出发点
    while(1) {
        temp[x][y] = 2;

        //向下
        if(temp[x+1][y]==0) {
            s.push(x,y,'D');
            // 在当前位置做一个向下的标志
            temp[x][y] = 3;
            x = x + 1;
            temp[x][y] = 7;			//当前位置
            // 判断是否到达出口，如果到达出口则flag标记为true，下同
            if((x==MAX_X-1)&&(y==MAX_Y-2)) {
                flag = true;
                return;
            } else
                continue;
        }

        // 向右
        if(temp[x][y+1]==0) {
            s.push(x,y,'R');
            // 在当前位置做一个向右的标志
            temp[x][y] = 4;
            y = y + 1;
            temp[x][y] = 7;
            if((x==MAX_X-1)&&(y==MAX_Y-2)) {
                flag = true;
                return;
            } else
                continue;
        }

        //向上
        if(temp[x-1][y]==0) {
            s.push(x,y,'U');
            // 在当前位置做一个向上的标志
            temp[x][y] = 6;
            x = x - 1;
            temp[x][y] = 7;
            if((x==MAX_X-1)&&(y==MAX_Y-2)) {
                flag = true;
                return;
            } else
                continue;
        }

        //向左
        if(temp[x][y-1]==0) {
            s.push(x,y,'L');
            //在当前位置做一个向右的标志
            temp[x][y] = 5;
            y = y - 1;
            temp[x][y] = 7;
            if((x==MAX_X-1)&&(y==MAX_Y-2)) {
                flag = true;
                return;
            } else
                continue;
        }

        //上下左右不通，则退回到起点
        if(s.pop(x,y)==NULL && temp[x-1][y]!=0 && temp[x][y-1]!=0 && temp[x][y+1]!=0 && temp[x+1][y]!=0) {
            temp[0][1] = 7;
            if(temp[1][1]!=1)
                temp[1][1] = 2;
            return;
        }
    }
}