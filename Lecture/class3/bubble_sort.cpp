#include<iostream>
using namespace std;
void swap(int* x,int *y){
int t=*x;
*x=*y;
*y=t;
}
int swapFunc(int* a,int i,int j){
    for(int indx=i;indx<j;++indx)
        if(a[indx]>a[indx+1]) swap(a[indx],a[indx+1]);

}
void bubbleSort(int *a,int i,int j){
if(i==j) return ;
swapFunc(a,0,j);
bubbleSort(a,i,j-1);
}
int main(){
int a[]={4,3,5,2,1};
int N=sizeof(a)/sizeof(int);
bubbleSort(a,0,N-1);
for(int j=0;j<N;++j)cout<<a[j]<<" "<<endl;
return 0;
}
