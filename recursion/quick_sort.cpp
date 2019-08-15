#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void quickSort(int *ar,int l,int r){

    if(l>=r ) return;
//    if((r-l)==1) {
//        if(ar[l]<=ar[r]);
//        else swap(ar[l],ar[r]);
//    }
    int p=rand()%((r-l)+1);
    int pivot=ar[p+l];

    //cout<<"new partition "<<p<<" : ";
    //for(int h=l;h<=r;++h) cout<<ar[h]<<" ";
    swap(ar[p+l],ar[r]);


    int i=l,j=r-1;



    while(true){

        while(i<=j && ar[i]<=pivot) ++i;
        while(j>=i && ar[j]>pivot) --j;

        if(i>j) break;
        swap(ar[i++],ar[j--]);


    }

    swap(ar[i],ar[r]);
    //cout<<"updated partition "<<p<<" : ";
    //for(int h=l;h<=r;++h) cout<<ar[h]<<" ";
    //cout<<"next"<<endl;
  //  cout<<endl;

    quickSort(ar,l,l+p-1);
    quickSort(ar,l+p+1,r);


}
int main(){
  int N;
  int ar[200000];
  srand(time(NULL));
  cin>>N;


  for(int i=0;i<N;++i)cin>>ar[i];
  quickSort(ar,0,N-1);

  for(int i=0;i<N;++i)   cout<<ar[i]<<" ";


return 0;}
