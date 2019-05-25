/**
 * 邻接矩阵图类型
 * author 叶晨韬
 * date 2019/5/14
 **/
#include <stdio.h>
#define FINITY 5000      //此处用5000代表无穷大
#define M 20             //最大顶点数
typedef char vertextype; //顶点值类型
typedef int edgetype;    //权值类型
typedef struct
{
    vertextype vexs[M];   //顶点信息域
    edgetype edges[M][M]; //邻接矩阵
    int n, e;             //图中顶点总数与边数
} Mgraph;

//建立图的邻接矩阵存储结构
//邻接矩阵的指针变量g
//存放图信息的文件名s
//图的类型参数c c=0表示建立无向图，否则表示建立有向图
void creat(Mgraph *g, char *s, int c)
{
    int i, j, k, w;
    FILE *rf;
    rf = fopen(s, "r"); //从文件中读取图的边信息
    if (rf)
    {
        fscanf(rf, "%d%d", &g->n, &g->e); //读入图的顶点数与边数
        for (i = 0; i < g->n; i++)        //读入图中的顶点数
            fscanf(rf, "%1s", &g->vexs[i]);
        for (i = 0; i < g->n; i++) //初始化邻接矩阵
            for (j = 0; j < g->n; j++)
                if (i == j)
                    g->edges[i][j] = 0;
                else
                    g->edges[i][j] = FINITY;
        for (k = 0; k < g->e; k++) //读入边信息
        {
            fscanf(rf, "%d%d%d", &i, &j, &w);
            g->edges[i][j] = w;
            if (c == 0) //建立无向图邻接矩阵
                g->edges[j][i] = w;
        }
        fclose(rf); //关闭文件
    }
    else
        g->n = 0;
}

/*G.txt
-------
4 4
0123
0 1 56
0 2 34
0 3 78
2 3 25
-------
4 4 表示该图包括4个顶点4条边，字符0123表示顶点V0,V1,V2,V3的结点信息，其他的4个三元组
代表4条边信息
*/
