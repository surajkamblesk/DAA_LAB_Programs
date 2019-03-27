#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int indegree[SIZE];
int main()
{
int n,i,j,Stack[SIZE],top = -1,temp,result[SIZE],k = 0;
printf("Enter the number of nodes: ");
scanf("%d",&n);
int Graph[SIZE][SIZE];
printf("Enter the values of the adjacency matrix:\n");
for(i = 0;i < n;i++)
{
for(j = 0;j < n;j++)
{
scanf("%d",&Graph[i][j]);
if(Graph[i][j] == 1)
indegree[j]++;
}
}
for(i = 0;i < n;i++)
{
if(indegree[i] == 0)
Stack[++top] = i;
}
while(top != -1)
{temp = Stack[top--];
result[k++] = temp;
for(i = 0;i < n;i++)
{
if(Graph[temp][i] == 1)
{
indegree[i]--;
if(indegree[i] == 0)
Stack[++top] = i;
}
}
}
printf("the Topological ordering using DFS method is\n");
for(i = 0;i < n;i++)
printf("%d\t",result[i]);
return 0;
}