
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    
      int  r1=rand()%10;
      int  c1=rand()%10;
      int  c2=rand()%10;
      int  r2=c1;
      int A[r1][c1];
      int B[r2][c2];
      int C[r1][c2];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
             
             A[i][j]=rand()%1000+1000;
        } 
    }
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
             
             B[i][j]=rand()%1000+1000;
        } 
    }
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
             
             C[i][j]=0;
        } 
    }
    
    //#pragma omp parallel for 
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            for(int k=0;k<r2;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
     for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<C[i][j]<<" ";       
        }
        cout<<endl;
    }
    return 0;
}
