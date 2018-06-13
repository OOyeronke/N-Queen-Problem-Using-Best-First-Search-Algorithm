/* Write C++ programs for the implementation of Depth-first search(DFS) for a given graph */

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int cost[10][10],i,j,k,n,stck[10],top,v,visit[10],visited[10],root;
 
int main()
{
int m;
cout <<"enter no of vertices: ";
cin >> n;
cout <<"enter no of edges: ";
cin >> m;
cout <<"\nEDGES \n";
for(k=1;k<=m;k++)
{
cin >>i>>j;
cost[i][j]=1;
}
 
cout <<"enter initial vertex: ";
cin >>v;
cout << "enter the goal vertex: ";
cin >> root;
cout <<"ORDER OF VISITED VERTICES: ";
cout << v <<" ";
visited[v]=1;
k=1;
while(k<n)
{
	if(v==root){
		return v;
	}
	else{

for(j=n;j>=1;j--)
if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
{
visit[j]=1;
stck[top]=j;
top++;
}
v=stck[--top];

cout<<v << " ";
k++;
visit[v]=0; visited[v]=1;
}

	}
}
