#include<iostream>
using namespace std;

void selectionSort(int *a,int N){

    for(int i=0;i<N;++i){
            int min_indx=i;
            for(int j=i+1;j<N;++j){
                    if(a[min_indx]>a[j]) min_indx=j;
            }
        swap(a[i],a[min_indx]);

    }
}
int main(){
    int N;
    cin>>N;
    int a[10000];
    for(int i=0;i<N;++i){
        cin>>a[i];
    }

    selectionSort(a,N);

    for(int i=0;i<N;++i){
        cout<<a[i]<<endl;

    }


return 0;   }
