#include<iostream>
#include<math.h>
using namespace std;
int main(){
int x={1,2,3,4,5}
int N=sizeof(x)/sizeof(int);
int bit_count[16];
for(int i=0;i<N;++i){
    for(int j=0;j<16;++j)
        bit_count[j]=bit_count[j]+(x[i]&1>>j);

}
cout<<bit_count;
return 0;
}
