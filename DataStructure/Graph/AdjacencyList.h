/**
 * 邻接表图类型
 * author 叶晨韬
 * date 2019/5/14
 **/
#include <stdio.h>
#include <stdlib.h>
#define M 20           //预定义图的最大顶点数
typedef char DataType; //顶点信息数据类型
typedef struct node
{               //边表结点
    int adjvex; //邻接点
    struct node *next;
} EdgeNode;
typedef struct vnode
{                        //头结点类型
    DataType vertex;     //顶点信息
    EdgeNode *FirstEdge; //邻接链表头指针
} VertexNode;
typedef struct
{                          //邻接表类型
    VertexNode adjlist[M]; //存放头结点的顺序表
    int n, e;              //图的顶点数与边数
} LinkedGraph;

//建立图的邻接表
//邻接表指针变量g
//存放图信息的文件名filename
//图的类型参数c c=0表示建立无向图，否则表示建立有向图
void creat(LinkedGraph *g, char *filename, int c)
{
    int i, j, k;
    EdgeNode *s;
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp)
    {
        fscanf(fp, "%d%d", &g->n, &g->e); //读入顶点数与边数
        for (i = 0; i < g->n; i++)
        {
            fscanf(fp, "%1s", &g->adjlist[i].vertex); //读入顶点信息
            g->adjlist[i].FirstEdge = NULL;           //边表置为空表
        }
        for (k = 0; k < g->e; k++) //循环e次建立边表
        {
            fscanf(fp, "%d%d", &i, &j); //输入无序对(i, j)
            s = (EdgeNode *)malloc(sizeof(EdgeNode));
            s->adjvex = j; //邻接表序号为j
            s->next = g->adjlist[i].FirstEdge;
            g->adjlist[i].FirstEdge = s; //将新结点*s插入顶点vi的边表头部
            if (c == 0)                  //无向图
            {
                s = (EdgeNode *)malloc(sizeof(EdgeNode));
                s->adjvex = i; //邻接点序号为i
                s->next = g->adjlist[j].FirstEdge;
                g->adjlist[j].FirstEdge = s; //将新结点*s插入顶点vj的边表头部
            }
        }
        fclose(fp);
    }
    else
        g->n = 0; //文件打开失败
}
