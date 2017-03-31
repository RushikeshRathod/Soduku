#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
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
 
    public: void Solve()
        {
         for(int i=0;i<9;i++)
            {
            for( int j=0;j<9;j++)
                {              
                  if(arr[i][j]==0)
                    {
                    int flag=0;
                    for(int k=1;k<=9;k++)
                        {
                        int temp=Check(k,i,j);                     
                        if(temp==1)
                            {
                            flag=flag+1;
                        }                      
                    }
                    if(flag==1)
                        {
                        for(int k=1;k<=9;k++)
                            {
                        int temp=Check(k,i,j); 
                            if(temp==1)
                                arr[i][j]=k;
                        }
                        
                    }
                    
                }
            }
        }
        int indicator=1;
        for(int i=0;i<9;i++)
            {
            for(int j=0;j<9;j++)
                {
                if(arr[i][j]==0)
                    {
                    indicator=indicator*0;
                }
                
            }
        }
        if(indicator==0)
            {
            Solve();
        }
        
    }
    
};




int main() {
    sudoku s1;
    s1.Input();
    s1.Solve();
    s1.Display();  
}
