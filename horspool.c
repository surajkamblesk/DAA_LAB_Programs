#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000
#define SIZE 256
int Table[SIZE];
void ShiftTable(char Pattern[])
{
int i,m;
m = strlen(Pattern);
for(i = 0;i < SIZE;i++)
Table[i] = m;
for(i = 0;i < m-1;i++)
Table[Pattern[i]] = m-i-1;}
int Horspool(char Text[],char Pattern[])
{
int i,m,n,k;
m = strlen(Pattern);
n = strlen(Text);
ShiftTable(Pattern);
i = m-1;
while(i < n)
{
k = 0;
while(k < m && Pattern[m-1-k] == Text[i-k])
k++;
if(k == m)
return i-m+1;
else i = i + Table[Text[i]];
}
return -1;
}
int main()
{
int i;
char Text[MAX],Pattern[MAX];
printf("Enter the text: ");
gets(Text);
printf("Enter the pattern: ");
gets(Pattern);
i = Horspool(Text,Pattern);
if(i != -1)
printf("Pattern found in text at position %d.\n",i+1);
else printf("Pattern not found in the text.\n");
return 0;
}