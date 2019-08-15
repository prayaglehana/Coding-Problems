#include<iostream>
using namespace std;
int main(){

int ar[100];
int N;
int K;
cin>>N>>K;
for(int i=0;i<N;++i) cin>>ar[i];
int csum=0;
int i=0,j=0;
bool found =false;
while(true){
//if(i==j) csum=0;
if((csum+ar[j])<K)
    {csum+=ar[j];++j;}
else if((csum+ar[j])==K) {found =true;break;}
else {csum=csum-ar[i];++i;if(i>j)++j; }

if(j==N-1)break;

}

if(found) cout<<"i"<<i<<"j"<<j;
else cout<<"cannot be generated";

return 0;
}
