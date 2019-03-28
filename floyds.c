#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define INF 99999
int min(int a,int b){
return (a > b)? b:a;
}
void Floyd(int Graph[SIZE][SIZE],int n)
{
int i,j,k;
for(k = 1;k <= n;k++)
for(i = 1;i <= n;i++)
for(j = 1;j <= n; j++)
Graph[i][j] = min(Graph[i][j],Graph[i][k] + Graph[k][j]);
}
int main()
{
int i,j,n;
printf("Enter the number of nodes: ");
scanf("%d",&n);
int Graph[SIZE][SIZE];
printf("Enter the weighted matrix:\n");
for(i = 1;i <=n;i++)
for(j = 1;j <=n;j++)
scanf("%d",&Graph[i][j]);
Floyd(Graph,n);
printf("\n\nThe all pair shortest path graph is:\n");
for(i = 1;i <=n;i++)
{
for(j = 1;j <=n;j++)
printf("%d ",Graph[i][j]);
printf("\n");
}
return 0;
}