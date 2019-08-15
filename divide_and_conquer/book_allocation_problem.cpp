#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool checkIfPossible(int *a,int P,int N,int maxtime){
    int p=1,sum_p=0;
    for(int i=0;i<N;++i){
            if((sum_p+a[i])>maxtime){
                ++p;
                sum_p=a[i];
                if(sum_p>maxtime) return false;
            }
            else{
                sum_p+=a[i];
            }
    }
    if(p<=P) return true;

    return false;
}

int findMinMax(int *a,int minMax,int s,int e,int P,int N){
    if(s>e) return minMax;

    int mid=(s+e)/2;
    //cout<<"mid"<<mid<<endl;
    bool check=checkIfPossible(a,P,N,mid);

    if(check) {minMax=mid; return  findMinMax(a,minMax,s,mid-1,P,N);}

    else return findMinMax(a,minMax,mid+1,e,P,N);
}



int main(){

int t;
int a[10000];
cin>>t;
while(t--){
    int N,P;
    cin>>N>>P;

    for(int i=0;i<N;++i) cin>>a[i];
    int sum=accumulate(a, a+N, 0);

    cout<<findMinMax(a,sum,0,sum,P,N)<<endl;


}

return 0;
}
