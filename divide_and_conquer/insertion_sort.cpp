#include<iostream>
using namespace std;

void insertionSort(int *a,int N){

    for(int i=1;i<N;++i){
        int j=i-1;
        int no=a[i];
        for(;j>=0 && a[j]>no;--j){
            a[j+1]=a[j];
        }
        a[j+1]=no;
        //for(int k=0;k<N;++k)  cout<<a[k]<<" ";
        //cout<<endl;


    }
}
int main(){

    int N;
    cin>>N;
    int a[10000];
    for(int i=0;i<N;++i){
        cin>>a[i];
    }

    insertionSort(a,N);
 for(int i=0;i<N;++i)  cout<<a[i]<<endl;
return 0;}
