/**
 * 图的广度优先遍历算法
 * author 叶晨韬
 * date 2019/5/17
 **/
#include "AdjacencyList.h"
int visited[M]; //全局标志向量

/*函数功能：从顶点i出发广度优先变量图g的连通分量*/
/*函数参数：图的邻接表g，遍历始点i            */
/*函数返回值：无                            */
void bfs(LinkedGraph g, int i)
{
    int j;
    EdgeNode *p;
    int queue[M], front, rear;          //FIFO队列
    front = rear = 0;                   //初始化空队列
    printf("%c ", g.adjlist[i].vertex); //访问源点v
    visited[i] = 1;
    queue[rear++] = i;   //被访问结点进队
    while (rear > front) //当队列非空时，执行下列循环体
    {
        j = queue[front++]; //出队
        p = g.adjlist[j].FirstEdge;
        while (p) //广度优先搜索邻接表
        {
            if (visited[p->adjvex] == 0)
            {
                printf("%c ", g.adjlist[p->adjvex].vertex);
                queue[rear++] = p->adjvex;
                visited[p->adjvex] = 1;
            }
            p = p->next;
        }
    }
}

/*函数功能：广度优先遍历图g     */
/*函数参数：邻接表g            */
/*函数返回值：返回连通分量的个数*/
int BfsTraverse(LinkedGraph g)
{
    int i, count = 0;
    for (i = 0; i < g.n; i++)
        visited[i] = 0; //初始化标志数组
    for (i = 0; i < g.n; i++)
        if (!visited[i]) //vi未访问过
        {
            printf("\n");
            count++; //连通分量个数加1
            bfs(g, i);
        }
    return count;
}

int main()
{
    LinkedGraph g;
    int count;
    creat(&g, "g11.txt", 0);
    count = BfsTraverse(g); //从顶点0出发广度优先遍历图g
    printf("\n 该图共有%d个连通分量。\n", count);
    return 0;
}
