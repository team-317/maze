#include<maze.h>
extern int maze[MAX_X][MAX_Y];

char getch()
{
    char ch;
    //保存原有终端属性和新设置的终端属性
    static struct termios oldt, newt;

    //获得终端原有属性并保存在结构体oldflag
    tcgetattr( STDIN_FILENO, &oldt);

    //设置新的终端属性
    newt = oldt;
    newt.c_lflag &= ~(ICANON);
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    //取消回显
    system("stty -echo");
    ch = getchar();
    system("stty echo");

    //让终端恢复为原有的属性
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void move()
{
    int x=1,y=1;	//出发点
    //一直游戏，直到走出
    while(1) {
        //判断输入的命令
        switch(getch()) {
        case 's':
            if(maze[x+1][y]==0) {
                //清空当前位置信息
                maze[x][y] = 0;
                x = x + 1;
                //当前位置
                maze[x][y] = 7;
                printMaze();
                if((x==MAX_X-1)&&(y==MAX_Y-2)) {
                    cout<<"\n\n\t\t成功走出"<<endl;
                    return;
                }
            }
            break;
        case 'd':
            if(maze[x][y+1]==0) {
                if(maze[x][y+1]==0) {
                    maze[x][y] = 0;
                    y = y + 1;
                    maze[x][y] = 7;
                    printMaze();
                    if((x==MAX_X-1)&&(y==MAX_Y-2)) {
                        cout<<"\n\n\t成功走出"<<endl;
                        return;
                    }
                }
            }

            break;
        case 'w':
            if(maze[x-1][y]==0) {
                maze[x][y] = 0;
                x = x - 1;
                maze[x][y] = 7;
                printMaze();
                if((x==MAX_X-1)&&(y==MAX_Y-2)) {
                    cout<<"\n\n\t成功走出"<<endl;
                    return;
                }
            }
            break;
        case 'a':
            if(maze[x][y-1]==0) {
                maze[x][y] = 0;
                y = y - 1;
                maze[x][y] = 7;
                printMaze();
                if((x==MAX_X-1)&&(y==MAX_Y-2)) {
                    cout<<"\n\n\t成功走出"<<endl;
                    return;
                }
            }
            break;
        }
    }
}
