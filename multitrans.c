#include <stdio.h>
#include <stdlib.h>
int singletrans2(int *B,int *S,int n,int C);
void trans2(int *B,int *S,int i,int j,int C,int *A);
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
int singletrans2(int *B,int *S,int n,int C)
{
  int A[4],c;
  trans2(B,S,0,n-1,C,A);
  printf("\nBuying Date = %d  , Buying rate = %d\n",A[0],B[A[0]]);
  printf("Selling Date = %d  , Selling rate = %d\n\n",A[1],S[A[1]]);
  c = (C/B[A[0]])*(S[A[1]]-B[A[0]]);
  printf("Maximum Profit = %d \n\n",c);
  return c;
}
void trans2(int *B,int *S,int i,int j,int C,int *A)
{
  if(i==j)
   {
     A[0]=A[1]=i;
     A[2]=A[3]=i;
     return;
   }
  int k,l,k1,l1,m,c,x,y;
  m = i + (j-i+1)/2;
  trans2(B,S,i,m-1,C,A);
  k=A[0];l=A[1];x=A[2];y=A[3];
  c = (C/B[k])*(S[l]-B[k]);
  trans2(B,S,m,j,C,A);
  k1=A[0];l1=A[1];
  if((C/B[k1])*(S[l1]-B[k1]) > c)
   {
     k=k1;l=l1;
     c = (C/B[k1])*(S[l1]-B[k1]);
   }
  k1=x;l1=A[3];
  if((C/B[k1])*(S[l1]-B[k1]) > c)
   {
     k=k1;l=l1;
     c = (C/B[k1])*(S[l1]-B[k1]);
   }
  A[0]=k;A[1]=l;
  if(B[x]>B[A[2]]) x=A[2];
  if(S[y]<S[A[3]]) y=A[3];
  A[2]=x;
  A[3]=y;
}
void multitrans(int *B,int *S,int n,int C)
{
  printf("\nInitial capital : %d\n",C);

}
