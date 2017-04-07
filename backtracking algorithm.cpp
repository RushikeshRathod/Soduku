#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
struct coordinates {
    int a;
    int b;
};

class sudoku
    {
    int arr[10][10];
    
    public: void Input()
    {
    for(int i=0;i<9;i++)
        {
        for(int j=0;j<9;j++)
            {
            cin>>arr[i][j];
        }
    }
}
    
    public: void Display()
    {
    for(int i=0;i<9;i++)
        {
        for(int j=0;j<9;j++)
            {
            cout<<arr[i][j]<<" ";
            if((j+1)%3==0)
                {
                cout<<" ";
            }
        }
        cout<<endl;
        if((i+1)%3==0)
                {
                cout<<endl;
            }
        
    }
}
    
    public: int Safetoaddinrow(int n, int r)
        {
        int temp;
        int flag=1;
        for(int i=0;i<9;i++)
            {
            temp=arr[r][i];
            if(temp==n)
                flag=flag*0;
        }
        if(flag==0)
            return 0;
        else
            return 1;
        
    }
    
    
    public: int Safetoaddincolumn(int n, int c)
        {
        int temp;
        int flag=1;
        for(int i=0;i<9;i++)
            {
            temp=arr[i][c];
            if(temp==n)
                flag=flag*0;
        }
        if(flag==0)
            return 0;
        else
            return 1;
        
    }
    public: int Safetoaddinsubmatrix(int n, int startx, int starty)
        {
        int temp;
        int flag=1;
        for(int i=startx;i<startx+3;i++)
            {
            for(int j=starty;j<starty+3;j++)
                {
                    temp=arr[i][j];
                    if(temp==n)
                        {
                    flag=flag*0;
                    }
            }
        }
        if(flag==0)
            return 0;
        else
            return 1;      
    }
    
    public: int Check(int k,int i, int j)
                    {
                        int p=Safetoaddinrow(k,i);
                        int q=Safetoaddincolumn(k,j);
                        int r=i/3;
                        int s=j/3;
                        r=r*3;
                        s=s*3;
                        int t=Safetoaddinsubmatrix(k,r,s);
                        int val=p*q*t;
                        return val;
             }
    coordinates c{
        0,0
    };
    
    
    public: bool Solve()
        {
         for(int k=1;k<=9;k++)
             {
             coordinates c1=FindnextEmpty();
              if(c.a==-1)
                  {
                  return true;
              }
             
                 int temp=Check(k, c1.a,c1.b);
                 if(temp==1)
                     {
                     arr[c1.a][c1.b]=k;
                     if(Solve())
                         {
                         return true;
                     }
                     arr[c1.a][c1.b]=0;
                 }           
         }
        return false;
        }
        
        
    
    
 coordinates FindnextEmpty()
    {
    for(int i=0;i<9;i++)
        {
        for(int j=0;j<9;j++)
            { 
              
              if(arr[i][j]==0)
                  { 
                  
                  c.a=i;
                  c.b=j;
                  return c;
              }
           
        }
         
    }
     c.a=-1;
     c.b=-1;
     return c;
}

};


int main() {
    clock_t t;
    t=clock();
    sudoku s1;
    s1.Input();
    s1.Solve();
    s1.Display();
    t=clock()-t;
    cout<<endl;
    float time=(float)t/CLOCKS_PER_SEC;
    cout<<time;
}
