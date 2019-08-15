#include<iostream>
#include<math.h>
using namespace std;
int main(){
int x[]={1,2,2,1,1,2,4};
int N=sizeof(x)/sizeof(int);
int bit_count[10]={0};
int bit_len=sizeof(bit_count)/sizeof(int);
int ans=0;

for(int i=0;i<N;++i){
    for(int j=0;j<bit_len;++j)
        bit_count[j]=bit_count[j]+(x[i]&(1<<j));

}
for (int p=bit_len-1;p>=0;--p)
    {cout<<bit_count[p]%3;
    bit_count[p]=bit_count[p]%3;}

for (int p=bit_len-1;p>=0;--p)
    ans=ans+bit_count[p]*(1<<p);

cout<<"\nans:"<<ans;
return 0;
}
