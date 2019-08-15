#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int conseqSum(int *a, int N)
{
    int max_so_far=0;
    int this_sum=0;
    for(int i=0;i<N;++i){
        if(a[i]==1) ++this_sum;
        else {
                max_so_far=max(this_sum,max_so_far);
                this_sum=0;
        }
    }
   return max(this_sum,max_so_far);


}

int main(){
int T;
cin>>T;
while(T--){
    int A[51][51];
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N*M;++i){
        int x;
        cin>>x;
        int J=i%M;
        int I=floor(i/M);
      //  cout<<I<<" "<<J<<endl;
        A[I][J]=x;
    }
//    for(int i=0;i<N;++i){
//        for(int j=0;j<M;++j){
//            cout<<A[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    int ar[51];
    int max_=0;

    for(int L=0;L<M;++L){
        for(int R=L;R<M;++R){
                for(int i=0;i<N;++i){
                      int sum_=0;
                      for(int j=L;j<=R;++j)sum_+=A[i][j];

                      if(sum_==((R-L)+1)) ar[i]=1;
                      else ar[i]=0;


                }
//                cout<<endl;
//                cout<<" L "<<L<<" R "<<R<<endl;
//                for(int i=0;i<N;++i){
//                   cout<<ar[i];
//                }
//                cout<<endl;




                int thisSum=conseqSum(ar,N);
                thisSum=min(thisSum,((R-L)+1));



                if(max_<thisSum) max_=thisSum;
        }
    }
    cout<<max_<<endl;

}

return 0;
}


