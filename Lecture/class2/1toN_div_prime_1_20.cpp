#include<iostream>
#include<bitset>
#include<cstring>
using namespace std;

int getSubsetMask(int* ar,int number,int len,int N){
//cout<<"str"<<str;

long long int prod=1;
int total_set_bits=0;
for(int i=0;i<len;++i){
    if(((number>>i)&1)){
        prod=prod*ar[i];
        ++total_set_bits;
        cout<<ar[i]<<" ";

    }
}
cout<<endl;

if(total_set_bits%2) {cout<<"^"<<N/prod<<endl;return N/prod;}
else {cout<<"^"<<-N/prod<<endl;return -int(N/prod);}

}


int main(){

int ar[]={2,3,5,7,11,13,17,19};

int len=sizeof(ar)/sizeof(int);
int N;
cin>>N;

int sum_=0;
for(int i=2;i<=(((1<<len))-1);++i){
        cout<<"i"<<i<<" ";
        sum_+=getSubsetMask(ar,i,len,N);

}
cout<<"sum : "<<sum_;
return 0;
}



