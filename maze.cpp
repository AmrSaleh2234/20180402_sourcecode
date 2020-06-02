#include"maze.h"
#include<bits/stdc++.h>
using namespace std;

typedef struct n
{
    int x;
    int y;
    int dir;//0 = north, 1= east, 2 =south, 3=west, -1=no direction
    n* parent;
} node;

void create(int  x, int y, int dir,node *parent,node *p )
{
    p->x=x;
    p->y=y;
    p->dir=dir;
    p->parent=parent;

}

//prototype
void visit(queue <node *> &q, int**arr,int x,int y,int rows,int cols,int dir,node * pherant,map<node *,bool> &visitedNodesWithDir);

void shortestPath(char **maze,int rows,int cols)
{

    int sx,sy; //source (x,y)
    int ex,ey; //destination (x,y)
    int dotsSqueres[rows][cols];
    /*
    * this nested loops for search about src = 'c' and destination = 'e'
    * and create virtekse of graph
    */
    //O(rows * cols)O(n^2)

    for (int i=0; i<rows ; i++)
    {

        for(int j=0; j<cols; j++)
        {

            if(maze[i][j]!='*')
            {
                dotsSqueres[i][j]=1;

            }
            if(maze[i][j]=='*')
            {
                dotsSqueres[i][j]=0;
            }
            if(maze[i][j]=='c')
            {
                sx=i;
                sy=j;
            }
            if(maze[i][j]=='e')
            {
                ex=i;
                ey=j;
            }
            //cout<<squeres[i][j]<<' ';
        }
    }
    if(sx-1<0)
    {
        cout<<"-1";
        return;
    }
    int dx[]  = { -1, 0, 1, 0 };
    int dy[]  = { 0, 1, 0, -1 };
    map<node *,bool> visitedNodes;//to store visited point with direction
    queue<node *>  q;
    node *src=new node;
    create(--sx,sy,0,NULL,src);//because first move must be north
    q.push(src);
    node * temp =new node;
    int *kk[rows];//to can pass array to visit fun  without put dimention 2 in visit parameter
    int dest=0;//destination

    for(int i=0; i<rows; i++)
    {
        kk[i]=dotsSqueres[i];
    }
    //O(V+E)
    while((!q.empty())&&(temp=q.front()))
    {

        q.pop();
        //check if we find destination
        if(temp->x==ex&&temp->y== ey)
        {
            dest++;
            break;
        }
        for(int i=0; i<2; i++)
        {
            int newDir = (temp->dir+ i) % 4;
            visit(q,kk,temp->x+dx[newDir],temp->y+dy[newDir],rows,cols,newDir,temp,visitedNodes);
        }
    }
    stack<node*>s;
    if(dest==0)
    {
        //if not found destination
        cout<<"-1";
    }
    else
    {
        //if found destination  print point (x y) to pass
        while(temp)
        {
            s.push(temp);
            temp=temp->parent;
        }
        cout<<sx+1<<" "<<sy<<endl;
        while(!s.empty())
        {
            cout<<s.top()->x<<" "<<s.top()->y;
            s.pop();
            !s.empty()?cout<<endl: cout<<"";
        }
    }
}//end shortestPath function



bool inMaze(int x, int y, int **arr, int cols,int rows)
{
    return !(x<0||x>=rows||y<0||y>=cols||arr[x][y]==0);


}

void visit(queue <node *> &q, int**arr,int x,int y,int rows,int cols,int dir,node * pherant,map<node *,bool> &visitedNodesWithDir)
{
    node *Adj=new node;
    create(x,y,dir,pherant,Adj);
    //check if not in maze to ignore this node
    if(!inMaze(x,y,arr,cols,rows)|| visitedNodesWithDir[Adj])
    {
        return;
    }
    visitedNodesWithDir[Adj]=1;//make it visited with specific direction
    q.push(Adj);

}
