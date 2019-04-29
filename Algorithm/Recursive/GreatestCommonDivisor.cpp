/**
 * 最大公约数
 * author 叶晨韬
 * date 2019/4/26
 **/

int gcd(int p, int q)
{
    if (q == 0)
        return p;
    return gcd(q, p % q);
}
