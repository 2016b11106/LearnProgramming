/**
 * Prim求解最小生成树算法
 * author 叶晨韬
 * date 2019/5/17
 **/
#include "AdjacencyMatrix.h"
typedef struct edgedata //用于保存最小生成树的边类型定义
{
    int beg, en; //beg,en是边顶点序号
    int length;  //边长
} edge;

/*函数功能:prim算法构造最小生成树  */
/*函数参数:图的邻接矩阵g;边向量edge*/
/*函数返回值:无                   */
void prim(Mgraph g, edge tree[M - 1])
{
    edge x;
    int d, min, j, k, s, v;
    for (v = 1; v <= g.n - 1; v++) //建立初始入选点，并初始化生成树边集tree
    {
        tree[v - 1].beg = 0; //此处从顶点v0开始求最小生成树
        tree[v - 1].en = v;
        tree[v - 1].length = g.edges[0][v];
    }
    for (k = 0; k <= g.n - 3; k++) //依次求当前(第k条)最小两栖边，并加入TREE
    {
        min = tree[k].length;
        s = k;
        for (j = k + 1; j <= g.n - 2; j++)
            if (tree[j].length < min)
            {
                min = tree[j].length;
                s = j;
            }
        v = tree[s].en; //入选顶点为v
        /*通过交换，将当前最小边加入TREE中*/
        x = tree[s];
        tree[s] = tree[k];
        tree[k] = x;
        for (j = k + 1; j <= g.n - 2; j++) //由于新顶点v的加入，修改两栖边的基本信息
        {
            d = g.edges[v][tree[j].en];
            if (d < tree[j].length)
            {
                tree[j].length = d;
            }
        }
    }
    printf("\n The minimum cost spanning tree is:\n"); //输出最小生成树
    for (j = 0; j <= g.n - 2; j++)
        printf("\n%c---%c %d\n", g.vexs[tree[j].beg], g.vexs[tree[j].en], tree[j].length);
    printf("\nThe root of it is %c\n", g.vexs[0]);
}
int main()
{
    Mgraph g;
    edge tree[M - 1]; //用于存放最小生成树的M-1条边
    char filename[20];
    pritnf("Please input filename of Graph:\n"); //输入图信息的文件名X
    gets(filename);
    creat(&g, filename, 0); //创建无向图的邻接矩阵
    prim(g, tree);          //求解图的最小生成树
    return 0;
}
