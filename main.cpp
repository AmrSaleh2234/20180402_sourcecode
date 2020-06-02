#include <iostream>
#include"maze.h"
#include<bits/stdc++.h>
using namespace std;
void solveMaze(string fileName)
{
    int rows;
    int cols;
    ifstream take(fileName);
    take >> rows;
    take >> cols;
    char  maze[rows][cols];
    //O(rows*cols)
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            take >> maze[i][j];

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<"=====================the path is ====================="<<endl;


        char *p[rows];//to pass 2d array without specific size in parameter make array of pointer each one point to entry of array
    for(int i=0; i<rows; i++)
    {
        p[i]=maze[i];
    }
    shortestPath(p,rows,cols);


}
int main()
{
    solveMaze("maze1.txt");
    return 0;
}
