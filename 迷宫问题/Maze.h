#pragma once
#include"Stack.h"
#include<cassert>
const int N = 10;
struct Pos
{
	int _row;
	int _cols;
	Pos(int row = 0,int cols = 0)
		:_row(row)
		,_cols(cols)
	{}
};
void InitMaze(int *maze)
{
	FILE *fout = fopen("MazeMap.txt","r");
	assert(fout);
    
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			char num = fgetc(fout);
			if(num == ' '||num == '\n')
			{
				num = fgetc(fout);
			}
			maze[i*N+j] = num-'0';
		}
	}

}
void PrintMaze(int *maze)
{
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			cout<<maze[i*N+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool GetPath(int *maze,Stack<Pos>& s,Pos entry)
{
	s.Push(entry);
	maze[entry._row*N+entry._cols] = 2;
	Pos p;
	while(p._row != N-1)
	{
		p =s.Top();
		//上
		if(maze[(p._row-1)*N+p._cols] == 0)
		{
			p._row--;
			maze[p._row*N+p._cols] = 2;
			s.Push(p);
			continue;
		}
		//右
		if(maze[p._row*N+p._cols+1] == 0)
		{
			p._cols++;
			maze[p._row*N+p._cols] = 2;
			s.Push(p);
			//PrintMaze(maze);
			continue;
		}
		//下
		if(maze[(p._row+1)*N+p._cols] == 0)
		{
			p._row++;
			maze[p._row*N+p._cols] = 2;
			s.Push(p);
			continue;
		}
	
		//左
		if(maze[p._row*N+p._cols-1] == 0)
		{
			p._cols--;
			maze[p._row*N+p._cols] = 2;
			s.Push(p);
			continue;
		}
	
		s.Pop();
		
	}
	return p._row == N-1;
}
void TestMaze()
{
	Stack<Pos> p;
	int maze[N][N];
	InitMaze((int*)maze);
	PrintMaze((int*)maze);
	cout<<"是否有通路："<<GetPath((int*)maze,p,Pos(2,0))<<endl;
	PrintMaze((int*)maze);
}