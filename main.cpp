#include"maze.h"

void menu();

void gamestart()
{
    //初始化地图
    flag = false;
    while(!flag) {
        stack_of_maze stack;
        //创建地图
        createMaze();
        //检查地图是否创建成功
        check(stack);
        //模仿进度条
        system("clear");
        cout<<"	*                loading.              *"<<endl;
        system("clear");
        cout<<"	*                loading..             *"<<endl;
        system("clear");
        cout<<"	*                loading...            *"<<endl;
    }
    //输出当前迷宫的输出状态
    printMaze();
    cout<<"??enter???"<<endl;
    getchar();
    //自行游戏
    if(!autogame) {
        move();
        cout<<"输入enter键继续"<<endl;
        getchar();
        menu();
    }
    //自动游戏
    else {
        stack_of_maze stack1;
        autoMove(stack1);					//行走中...
    }
    printMaze();							//输出迷宫的最终状态
    cout<<"输出迷宫的最终状态"<<endl;
    getchar();
    menu();
}

void menu()
{
    system("clear");
    int num;
    cout<<"	****************************************"<<endl;
    cout<<"	*                                      *"<<endl;
    cout<<"	*               1.查看路径             *"<<endl;
    cout<<"	*                                      *"<<endl;
    cout<<"	*               2.自动进行             *"<<endl;
    cout<<"	*                                      *"<<endl;
    cout<<"	*               3.自行游戏             *"<<endl;
    cout<<"	*                                      *"<<endl;
    cout<<"	*               4.退出游戏             *"<<endl;
    cout<<"	*                                      *"<<endl;
    cout<<"	****************************************"<<endl;
    slow = false;
    //选择模式
    switch(getch()) {
    case '1':
        autogame = true;
        gamestart();
        break;
    case '2':
        autogame = true;
        slow = true;
        gamestart();
        break;
    case '3':
        autogame = false;
        gamestart();
        break;
    case '4':
        exit(1);
        break;
    default:
        cout<<"\n\n\t错误操作，输入enter返回！"<<endl;
        getchar();
        menu();
    }
    getchar();
}

int main(int argc,char** argv)
{
    menu();
    return 0;
}
