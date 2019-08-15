#include<iostream>
using namespace std;
bool check_sort(int* a,int indx,int N){
//cout<<"pair"<<a[indx]<<","<<a[indx+1]<<endl;
if(indx==(N-2)) return a[indx]<a[indx+1];
if(a[indx]<=a[indx+1] && check_sort(a,indx+1,N)) return true;
else return false;
}
int main(){
int ar[1000];
int N;
cin>>N;
for(int i=0;i<N;++i)cin>>ar[i];

if(check_sort(ar,0,N)) cout<<"true";
else cout<<"false";
return 0;
}
