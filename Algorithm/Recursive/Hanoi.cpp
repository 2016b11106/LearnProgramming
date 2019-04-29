/**
 * 汉诺塔
 * author 叶晨韬
 * date 2019/4/26
 **/
#include <iostream>

int i = 1;
//n->盘子数量  from->起始柱  to->终点柱  depend->中转柱
void _hanoi(int n, char from, char to, char depend)
{
    if (n == 0)
        return;
    _hanoi(n - 1, from, depend, to);
    std::cout << "第" << i++ << "次：" << from << " -> " << to << std::endl;
    _hanoi(n - 1, depend, to, from);
}

void hanoi(int n)
{
    _hanoi(n, 'A', 'C', 'B');
}
