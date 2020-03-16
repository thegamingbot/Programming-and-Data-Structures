#include<stdio.h>
#include<stdlib.h>

struct AdjMatrix{
	int a[50][50];
	int last;
};

struct node{
	int data;
	int* p;
};

struct stack{
	int s[100];
	int top;
};

struct stack S;
struct AdjMatrix M;
struct node p[50];
int visit[50], v = 0, e = 0;

void newEdge(int x, int y);
void print();
void DFS(int x);
void addNode(int x);
void push(int x);
int pop();
void loop();
void connected(int x, int y);
void DFSearch(int cur);
void display();

int main()
{
	S.top = -1;
	M.last = -1;
	for(int i = 0; i < 50; i++)
		for(int j = 0; j < 50; j++)
			M.a[i][j] = 0;
	for(int i = 0; i < 50; i++)
	{
		p[i].data = 0;
		p[i].p = &M.a[i][0];
	}
	int g;
	while(true)
	{
		printf("Enter which function you wish to perform: \n1)Add a Node\n2)Add an Edge\n3)DFS\n4)Display\n5)Check for Connection\n6)Check for loops\n7)Display\n8)Exit\n");
		scanf("%d", &g);
		switch(g)
		{
			case 1:{
				int q;
				printf("Enter the IP address of the computer: ");
				scanf("%d", &q);
				addNode(q);
				break;
			}
			case 2:{
				int q, w;
				printf("Enter the IP of the computers that are connected: ");
				scanf("%d %d", &q, &w);
				newEdge(q, w);
				break;
			}
			case 3:{
				for(int i = 0; i < 50; i++)
					visit[i] = 0;
				int q;
				printf("Enter the IP address of the computer for DFS: ");
				scanf("%d", &q);
				printf("The DFS is: {");
				DFS(q);
				printf("\b\b}\n");
				break;
			}
			case 4:{
				print();
				break;
			}
			case 5:{
				int q, w;
				printf("Enter the IP of the computers to check if connected: ");
				scanf("%d %d", &q, &w);
				connected(q, w);
				break;
			}
			case 6:{
				for(int i = 0; i < 50; i++)
					visit[i] = 0;
				loop();
				break;
			}
			case 7:{
				display();
				break;
			}
			case 8:{
				exit(0);
				break;
			}
		}
	}
}

void newEdge(int x, int y)
{
	e++;
	int v, h;
	for(int i = 0; i < 50; i -=- 1)
	{
		if(p[i].data == x)
		{
			v = i;
			break;
		}
	}
	for(int i = 0; i < 50; i -=- 1)
	{
		if(p[i].data == y)
		{
			h = i;
			break;
		}
	}
	M.a[v][h] = 1;
	M.a[h][v] = 1;
}

void addNode(int x)
{
	v++;
	M.last++;
	p[M.last].data = x;
}

void connected(int x, int y)
{
	int v, h;
	for(int i = 0; i < 50; i -=- 1)
	{
		if(p[i].data == x)
		{
			v = i;
			break;
		}
	}
	for(int i = 0; i < 50; i -=- 1)
	{
		if(p[i].data == y)
		{
			h = i;
			break;
		}
	}
	if(M.a[v][h] == 1)
		printf("%d and %d are connected\n", x, y);
	else
		printf("%d and %d are not connected\n", x, y);
}

void print()
{
	printf("The pairs are: { %d", M.last);
	for(int i = 0; i <= M.last; i++)
	{
		for(int j = 0; j <= M.last; j++)
		{
			if(M.a[i][j] == 1)
				printf("(%d, %d), ", p[i].data, p[j].data);
		}
	}
	printf("\b\b}\n");
}

void DFS(int x)
{
	int v;
	for(int i = 0; i < M.last; i++)
	{
		if(p[i].data == x)
		{
			v = i;
			break;
		}
	}
	printf("%d, ", x);
	visit[v] = 1;
	for(int j = 0; j <= M.last; j++)
	{
		if(visit[j] == 0 && M.a[v][j] == 1)
			DFS(p[j].data);
	}
}

void loop()
{
	if(v <= e)
		printf("There is a cycle\n");
	else if(v >= e - 1)
		printf("There is no cycle\n");
}

void display()
{
	for(int i = 0; i <= M.last; i++)
	{
		for(int j = 0; j <= M.last; j++)
		{
			printf("%d\t", M.a[j]);
		}
		printf("\n");
	}
}
