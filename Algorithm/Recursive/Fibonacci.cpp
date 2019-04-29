/**
 * 斐波那契数列
 * author 叶晨韬
 * date 2019/4/25
 **/

int fib(int n)
{
    if(n < 2)
	return n;
    return fib(n - 1) + fib(n - 2);
}
