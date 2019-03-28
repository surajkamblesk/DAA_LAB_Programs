#include <stdio.h>
#include <stdlib.h>
int N,C,Weight[10],Profit[10],Vector[10][10],x[10];
int Max(int a,int b)
{
return a > b? a:b;
}void KnapSack()
{
int i,j;
for(i = 0;i <= N;i++)
{
for(j = 0;j <= C;j++)
{
if(i == 0||j == 0)
Vector[i][j] = 0;
else if(j - Weight[i] < 0)
Vector[i][j] = Vector[i-1][j];
else Vector[i][j] = Max(Vector[i-1][j],Vector[i-1][j-Weight[i]] + Profit[i]);
}
}
}
void PrintSoln()
{
int i = N,j = C;
while(i != 0 ||j != 0)
{
if(Vector[i][j] != Vector[i-1][j])
{
x[i] = 1;
j = j - Weight[i];
}
i--;
}
}
int main()
{
printf("Enter the number of weights: ");
scanf("%d",&N);
printf("Enter the capacity of the knapsack: ");
scanf("%d",&C);
printf("Enter the values of weights: ");
int i,j;
for(i = 1;i <= N;i++)
scanf("%d",&Weight[i]);
printf("Enter the values of profits: ");
for(i = 1;i <= N;i++)
scanf("%d",&Profit[i]);
KnapSack();
PrintSoln();for(i = 0;i <=N;i++)
{
for(j = 0;j <= C;j++)
printf("%2d ",Vector[i][j]);
printf("\n");
}
printf("\nMaximum profit is %d.",Vector[N][C]);
printf("\nObjects considered are: \n");
for(i = 1;i <= N;i++)
if(x[i] == 1)
printf("Object No: %d\tWeight: %d\tProfit: %d\n",i,Weight[i],Profit[i]);
return 0;
}