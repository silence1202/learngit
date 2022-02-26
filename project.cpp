#include <conio.h>
#include <iostream>
#include <cstdio>
using namespace std;
const int one_second = 29000;
void deal_with_input()
{
    char ch;
    if (_kbhit())
    {                  //如 果 有 按 键 按 下， 则_kbhit () 函 数 返 回 真
        ch = _getch(); //使 用_getch() 函 数 获 取 按 下 的 键 值
        printf("%c", ch);
    }
}
int count = 0;
int main()
{
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