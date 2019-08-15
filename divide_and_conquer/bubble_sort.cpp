#include<iostream>
using namespace std;

void swapping(int* a,int N){
for(int j=1;j<N;++j ){
    if(a[j]<a[j-1])
        swap(a[j],a[j-1]);
    }
}

void bubbleSort(int *a,int N){
    if(N==0) return;
    swapping(a,N);
    bubbleSort(a,N-1);
}
int main(){
    int N;
    cin>>N;
    int a[10000];
    for(int i=0;i<N;++i){
        cin>>a[i];
    }

    bubbleSort(a,N);
    for(int i=0;i<N;++i){
        cout<<a[i]<<endl;

    }

return 0;
}
