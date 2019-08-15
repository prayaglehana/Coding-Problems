#include<iostream>
using namespace std;
int getMaxSum(int* a,int i,int j,bool turn,int N){
    if(i>j || i>=N  || j<0)
        return 0;
    if(i==j )
        return turn*a[i];

        if(!turn) return
            min((getMaxSum(a,i+1,j,!turn,N)),(getMaxSum(a,i,j-1,!turn,N)));
        return
            max((a[i]+getMaxSum(a,i+1,j,!turn,N)),(a[j]+getMaxSum(a,i,j-1,!turn,N)));
}

int main(){

    int N;
    cin>>N;

    int a[30];

    for(int i=0;i<N;++i)cin>>a[i];
        cout<<getMaxSum(a,0,N-1,true,N)<<endl;
    return 0;
}
