/**
 * 图的深度优先遍历算法
 * author 叶晨韬
 * date 2019/5/17
 **/
#include "AdjacencyList.h"
int visited[M];

/*函数功能：从顶点i开始深度优先遍历图的连通分量*/
/*函数参数：图的邻接表g，遍历起点i           */
/*函数返回值：无                           */
void dfs(LinkedGraph g, int i)
{
    EdgeNode *p;
    printf("visit vertex: %c \n", g.adjlist[i].vertex); //访问顶点i
    visited[i] = 1;
    p = g.adjlist[i].FirstEdge;
    while (p) //从p的邻接点出发进行深度优先搜索
    {
        if (!visited[p->adjvex])
            dfs(g, p->adjvex);
        p = p->next;
    }
}

/*函数功能：深度优先遍历图*/
/*函数参数：图的邻接表g  */
/*函数返回值：无        */
void DfsTraverse(LinkedGraph g)
{
    int i;
    for (i = 0; i < g.n; i++)
        visited[i] = 0; //初始化标志数组
    for (i = 0; i < g.n; i++)
        if (!visited) //vi未被访问过
            dfs(g, i);
}
