/**
 * 求阶乘(n!)
 * author 叶晨韬
 * date 2019/4/26
 **/

int fac(int n)
{
    if (n == 1)
        return 1;
    return n * fac(n - 1);
}
