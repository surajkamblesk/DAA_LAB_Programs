#include <stdio.h>
#include <stdlib.h>
#define MAX 2000
int count;
void Heapify(int H[],int n)
{
int i;
for(i = n/2;i > 0;i--)
{
int k = i;
int v = H[k];
int heap = 0;
while(!heap && 2*k <= n)
{
int j = 2*k;
if(j < n)
{
if(H[j] < H[j+1])
{j = j+1;
}
count++;
}
if(v >= H[j])
{
heap = 1;
count++;
}
else
{
H[k] = H[j];
k = j;
count++;
}
}
H[k] = v;
}
}
void HeapSort(int H[],int n)
{
int temp,i;
Heapify(H,n);
for(i = n;i > 0;i--)
{
temp = H[i];
H[i] = H[1];
H[1] = temp;
Heapify(H,i-1);
}
}
int main()
{
int a[MAX],b[MAX],c[MAX],i,j,c1 = 0,c2 = 0,c3 = 0,n;
printf("Enter the number of elements: ");
scanf("%d",&n);
int arr[n];
printf("Enter the elements: ");
for(i = 1; i <= n; i++)
scanf("%d",&arr[i]);
printf("The sorted array is: ");HeapSort(arr,n);
for(i = 1; i <= n; i++)
printf("%d ",arr[i]);
printf("\nThe count is:%d\n",count);
for(i = 16; i < 2000; i = i*2)
{
for(j = 1; j <= i; j++)
{
a[j] = j;
b[j] = i-j;
c[j] = rand() % i;
}
count = 0;
HeapSort(a,i);
c1 = count;
count = 0;
HeapSort(b,i);
c2 = count;
count = 0;
HeapSort(c,i);
c3 = count;
printf("\n%d\t%d\t%d\t%d\n",i,c1,c2,c3);
}
return 0;
}