#include<iostream>
using namespace std;

void linear_sort(int *a,int low,int high,int cur,int N){

//    while(a[low+1]==0) ++low;
//    while(a[high-1]==2) --high;
//    ++low;
//    --high;
//    cur=low+1;
    //cout<<"low "<<low<<" high "<<high<<endl;
    while(true){
                if(cur>high ) break;


                if(a[cur]==2){
                    swap(a[cur],a[high]);
                    --high;

                }
                else if(a[cur]==1){
                    ++cur;
                }

                else if(a[cur]==0){

                    swap(a[cur],a[low]);
                    ++low;
                    ++cur;


                }
//
//                cout<<"low "<<low<<" cur "<<cur<<" high "<<high<<endl;
//                 for(int i=0;i<N;++i)  cout<<a[i]<<" ";
//                 cout<<endl;

    }

}
int main(){

    int N;
    cin>>N;
    int a[100000];
    for(int i=0;i<N;++i){
        cin>>a[i];
    }

    linear_sort(a,0,N-1,0,N);
 for(int i=0;i<N;++i)  cout<<a[i]<<endl;
return 0;
}
