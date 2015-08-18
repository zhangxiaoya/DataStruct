#include <iostream>

using namespace std;
#define MAXSIZE 100

// definition
typedef struct ArcNode
{
    // arc node
    int adjvex;
    struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode
{
    // vertex node
    int vex;
    ArcNode* firstArc;
}VNode;

typedef struct
{
    // global graph
    VNode adjlist[MAXSIZE];
    int n,e;
}AGraph;

bool visited[MAXSIZE];

void DFSTraverse(AGraph* G,int vex)
{
   ArcNode* p;
   visited[vex] = true;
   p = G->adjlist[vex].firstArc;
   while(p!=NULL)
   {
       if(!visited[p->adjvex])
       {
           DFSTraverse(G,p->adjvex);
       }
       p = p->nextarc;
   }
}

void DFS(AGraph* G)
{
    int i;
    for(i=0;i<G->n;++i)
        if(visited[i] == false)
            DFSTraverse(G,i);
}

int main()
{

    return 0;
}

