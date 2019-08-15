#include<iostream>
using namespace std;
void mergeTwoArray(int *ar,int l,int r,int M,int N){


    int i=l,j=r,k=0;
    int T[200000];


    while(i<(l+M) && j<(r+N)){
            if(ar[i]<=ar[j]) T[k++]=ar[i++];
            else T[k++]=ar[j++];
        }

    while(i<(M+l))  T[k++]=ar[i++];
    while(j<(N+r))  T[k++]=ar[j++];

    for(int indx=0;indx<k;++indx) ar[l+indx]=T[indx];


}

void mergesort(int *ar,int i,int j){
        if(i>=j) return;
        int mid=(i+j)/2;

        mergesort(ar,i,mid);
        mergesort(ar,mid+1,j);

        mergeTwoArray(ar,i,mid+1,mid-i+1,j-mid);
}

int main(){
 int N;
 cin>>N;
 int ar[200000];
  for(int i=0;i<N;++i) cin>>ar[i];
 mergesort(ar,0,N-1);

 for(int i=0;i<N;++i){
    cout<<ar[i]<<" ";
    }


 return 0;
}
