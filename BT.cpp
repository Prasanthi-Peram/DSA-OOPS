#include <bits/stdc++.h>
using namespace std;
//N Queen problem
bool isSafe(int **arr, int x,int y,int n){
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }
    int row=x;
    int col=y;

    while(row>=0 && col>=0){
        if(arr[row][col]==1) return false;
       // cout<<endl;
        row--;
        col--;
    }
    row=x;
    col=y;

    while(row>=0 && col<n){
        if(arr[row][col]==1) return false;
        row--;
        col++;
    }

    return true;
}

bool nQueen(int **arr,int x,int n){//We don't need to specify col, because when we go to next row we check the possibility of placing the queen in each column
    if(x>=n){
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){//Checked for every row and every column
            arr[x][col]=1;

            //In the next subsequent rows are we able to place our queens?
            if(nQueen(arr,x+1,n)){
                return true;
            }

            arr[x][col]=0;//Backtracking
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    }
    return 0;
}