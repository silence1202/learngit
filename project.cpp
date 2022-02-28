#include <conio.h>
#include <iostream>
#include <cstdio>
using namespace std;
const int one_second = 29000;
const int Maxsize = 20;
void deal_with_input()
{
    char ch;
    if (_kbhit())
    {                  //如 果 有 按 键 按 下， 则_kbhit () 函 数 返 回 真
        ch = _getch(); //使 用_getch() 函 数 获 取 按 下 的 键 值
        printf("%c", ch);
    }
}
char map[11][21] = {
    "####################",
    "#** ***#**#*****  ##",
    "#*   #******###*** #",
    "#** ##**#   **##*###",
    "##******### **#  **#",
    "#**  #** ###******##",
    "###*##**   #**## **#",
    "# ***###******#   *#",
    "##  *****#**#*** **#",
    "####################"};
void init()
{

    int m = 10,
        n = 20;
}
void display()
{
    system("cls");
    for (int i = 0; i < 10; i++)
    {
        puts(map[i]);
    }
}

class Player
{
private:
    // 现 在 的 位 置
    std::pair<int, int> location;
    // 代 表 该 玩 家 的 字 符
    char symbol;

public:
    // 初 始 化
    Player(int x, int y, char symbol)
    {
        this->location.first = x;
        this->location.second = y;
        this->symbol = symbol;
        map[x][y] = symbol;
    }

    // 更 新 位 置
    void update_location(int type)
    {
        int x = this->location.first;
        int y = this->location.second;
        map[x][y] = ' ';
        switch (type)
        {
        case 1: //上
            x++;
            break;
        case 2: //左
            y--;
            break;
        case 3: //下
            x--;
            break;
        case 4: //右
            y++;
            break;
        default:
            break;
        }
        if (map[x][y] == ' ')
        {
            this->location.first = x;
            this->location.second = y;
        }
        map[this->location.first][this->location.second] = this->symbol;
    }

    // 获 取 位 置
    std::pair<int, int> get_location()
    {
        return this->location;
    }
};

int count = 0;
int main()
{
    init();
    display();
    while (1)
    {
        deal_with_input();
        count++;
        if (count == one_second)
        {
            count = 0;
            printf("!");
        }
    }

    return 0;
}