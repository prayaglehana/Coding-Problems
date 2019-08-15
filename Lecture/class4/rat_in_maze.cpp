#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char **path;
char **maze;
void showPath(int r,int c ){
    for(int x=0;x<r;++x){
            for(int y=0;y<c;++y){
                cout<<path[x][y]<<" ";
                    }
            cout<<endl;
        }

}
int ways(int i,int j,int &r,int &c){

    if(i==r || j==c) return 0;
    if(maze[i][j]=='X') return 0;

    if(i==(r-1) && j==(c-1))
        {   //cout<<endl;
            path[i][j]='1';
            showPath(r,c);
            return 1;
        }

    path[i][j]='1';
    int R=ways(i,j+1,r,c);
    if(R>0) return 1;
    int D=ways(i+1,j,r,c);
    path[i][j]='0';


    return (D+R);


}
int main(){
    int n,m;
    cin>>n>>m;
    maze=new char*[n];
    for(int i=0;i<n;++i)maze[i]=new char[m];

    path=new char*[n];
    for(int i=0;i<n;++i)path[i]=new char[m];

    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        for(int j=0;j<m;++j){
             maze[i][j]=s[j];
             path[i][j]='0';
        }
    }



if(ways(0,0,n,m)==0) cout<<"-1"<<endl;
return 0;
}


