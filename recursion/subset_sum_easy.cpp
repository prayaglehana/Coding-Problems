#include<iostream>
using namespace std;

bool subsetSum(int *input,int *output,int i,int j,int N){
    if(i>=N) {
        int sum_=0;
        bool in=false;
        //cout<<"subset : ";
        for(int x=0;x<j;++x){
            in = true;
            sum_+=output[x];

            //cout<<output[x]<<" ";
        }
          // cout<<endl;

        if(in && sum_==0 ) return true;
        else return false;
    }
    output[j]=input[i];
    if(subsetSum(input,output,i+1,j+1,N)) return true;
    if(subsetSum(input,output,i+1,j,N)) return true;
}
int main(){
int T;
cin>>T;
while(T--){
    int N;
    cin>>N;
    int ar[4];
    int op[4];
    for(int i=0;i<N;++i) {cin>>ar[i];}

    if(subsetSum(ar,op,0,0,N)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;



}


return 0;}
