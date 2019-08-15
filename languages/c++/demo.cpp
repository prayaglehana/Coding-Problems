#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);

}



int main() {

    int T;


    int N,A[100001];

        scanf("%d",&T);
        while(T--){int n=0;
                  long int counter=0;
                  int exists[1001]={0};

                        scanf("%d",&N);

                        for(int i=0;i<N;++i){
                           // int x;
                                    scanf("%d",&A[i]);
                                        ++exists[A[i]];
                                    }

                                //sort(A, A+n);

//                                cout<<"EXISTE FUNCTION :";
//                                for(int i=0;i<=A[n-1];++i){
//                                    cout<<exists[i]<<" ";
//                                }
//                               cout<<endl;

                                for(int i=0;i<N;++i){
                                    for(int j=i+1;j<N;++j){
                                        //A1=A[i],avg=A[j],A2=2*A[j]-A[i];
                                                    if((A[i]%2==0&&A[j]%2==0)||(A[i]%2==1&&A[j]%2==1))
                                                    {


                                                                int avg=(A[i]+A[j])/2;


                                                                                            if(exists[avg])
                                                                                                {//cout<<"pair ("<<A[i]<<","<<A[j]<<")"<<endl;

                                                                                                        counter++;
                                                                                                    }

                                                    }


                                    }
                                }
                               printf("%ld\n",counter);





        }

	return 0;
}

