#include <stdio.h>
#include <stdlib.h>
int max(int a,int b);
void multitrans(int *B,int *S,int n,int C);
void main()
{
   int n,C,i;
   int *B,*S;
   scanf("%d",&n);
   getchar();
   B = (int *)malloc(n*sizeof(int));
   S = (int *)malloc(n*sizeof(int));
   printf("Buying price : ");
   for(i=0;i<n;i++)
   {
     scanf("%d",B+i);
     getchar();
   }
   printf("Selling price : ");
   for(i=0;i<n;i++)
  {
    scanf("%d",S+i);
    getchar();
  }
  printf("Capital : ");
  scanf("%d",&C);
  getchar();
  printf("\n\nMultiple transaction: \n");
  multitrans(B,S,n,C);
}
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
void multitrans(int *B,int *S,int n,int C)
{
    int i,j;
    int *DateB,*DateS,*items,*capital,*residue;
    DateB = (int *)malloc(n*sizeof(int));
    DateS = (int *)malloc(n*sizeof(int));
    items = (int *)malloc(n*sizeof(int));
    capital = (int *)malloc(n*sizeof(int));
    residue = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        DateB[i]=DateS[i]=0;
    }
    items[0]=C/B[0];
    residue[0]=C%B[0];
    capital[0]=max(C,(residue[0])+(items[0]*S[0]));
    if(capital[0]!=C) DateB[0]=DateS[0]=1;
    for(i=1;i<n;i++)
    {
        items[i]=capital[i-1]/B[i];
        if(items[i] > items[i-1])
        {
            residue[i] = capital[i-1]%B[i];
        }
        else
        {
            residue[i]=residue[i-1];
            items[i]=items[i-1];
        }
        capital[i]=max(capital[i-1],(residue[i])+(items[i]*S[i]));
        if(capital[i]==capital[i-1])  DateB[i]=DateS[i]=0;
        else
        {
            if(items[i]!=items[i-1]) DateB[i]=DateS[i]=1;
            else if(items[i]==items[i-1])
            {
                DateB[i]=0;
                DateS[i]=1;
                for(j=i-1;items[j-1]==items[j];j--)
                {
                   DateB[j]=DateS[j]=0;
                   if(j==0) break;
                 }
                DateS[j]=0;
            }
        }
    }
    for(i=0;i<n;i++)
       if(DateB[i]==1)
        {
           printf("The Buying date= %d , Buying Rate = %d\n",i,B[i]);
           for(j=i;j<n;j++)
             if(DateS[j])
              {
                 printf("The Selling date = %d , Selling Rate = %d\n\n",j,S[j]);
                 printf("The current capital is = %d\n\n",capital[j]);
                 i=j;
                 break;
              }
        }
    printf("\nThe Maximum possible profit is : %d\n",(capital[n-1]-C));
    return;
}




