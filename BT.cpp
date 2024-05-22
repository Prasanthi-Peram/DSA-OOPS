#include <bits/stdc++.h>
using namespace std;
//N Queen problem
/*bool isSafe(int **arr, int x,int y,int n){
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
}*/

//Rat in a maze
//Backtracking is an algorithmic-technique for solving recursive problems by trying to build every possible solution incrementally and removing those solutions that fail to satisfy the constraints of the problem at any point of time
/*bool isSafe(int **arr,int x,int y,int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}
bool ratinMaze(int **arr,int x, int y,int n,int **solArr){
    if((x==(n-1)) && (y==(n-1))){
        solArr[x][y]=1;
        return true;
    }
    if(isSafe(arr,x,y,n)){
        solArr[x][y]=1;
        if(ratinMaze(arr,x+1,y,n,solArr)){
            return true;
        }
        if(ratinMaze(arr,x,y+1,n,solArr)){
            return true;
        }

        solArr[x][y]=0; //Backtracking
        return false;
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
            cin>>arr[i][j];
        }
    }cout<<endl;

    int** solArr=new int*[n];
    for(int i=0;i<n;i++){
        solArr[i]=new int[n];
        for(int j=0;j<n;j++){
            solArr[i][j]=0;
        }
    }

    if(ratinMaze(arr,0,0,n,solArr)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solArr[i][j]<<" ";
            }cout<<endl;
        }
    }
    return 0;
}*/

//Combinatorial sum by backtracking
/*int main(){
    //1. Return all possible pairs 2. You don't know the input size-->use dynamic arrays

    vector<int> arr;
    int num=0;

    while(num!=)


    
    return 0;
}*/