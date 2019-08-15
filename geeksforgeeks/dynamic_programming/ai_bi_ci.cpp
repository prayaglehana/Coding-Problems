#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getSum(int *x,int i,int j){
        int sum_=0;
                for(int k=i;k<=j;++k){
                    sum_=sum_+x[k];
                }
        return sum_;
}



void show(int *x,int N){

    for(int i=0;i<N;++i){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void setB(int *b,char* str,int N){
        for(int i=0;i<N;++i){
            b[i]=0;
        }
        for(int i=0;i<N;++i){
        if(str[i]=='b')
            {
                 b[i]=1+getSum(b,0,i-1);
            }

    }
}


void setA(int *a,char* str,int N){
        for(int i=0;i<N;++i){
            a[i]=0;
        }
        for(int i=0;i<N;++i){
        if(str[i]=='a')
            {
                a[i]=1+getSum(a,0,i-1);
            }

    }
}
void setAB(int *ab,int *a,char *str,int N){
       for(int i=0;i<N;++i){
            ab[i]=0;
        }
        for(int i=0;i<N;++i){
            if(str[i]=='b'){
                    int axby=getSum(ab,0,i-1);
                    int axb=getSum(a,0,i-1);
                    ab[i]=axby+axb;
            }
        }
}

void setABC(int *abc,int *ab,char *str,int N){
        for(int i=0;i<N;++i){
            abc[i]=0;
        }
        for(int i=0;i<N;++i){
            if(str[i]=='c'){
                    int axbycy=getSum(abc,0,i-1);
                    int axby=getSum(ab,0,i-1);
                    abc[i]=axbycy+axby;
            }
        }
}

int main(){

int a[100],b[100],ab[100],abc[100];

char str[100];
int T;
cin>>T;
while(T--){
    cin>>str;
    int N=strlen(str);
    setA(a,str,N);
    setAB(ab,a,str,N);
    setABC(abc,ab,str,N);

    cout<<getSum(abc,0,N-1)<<endl;
    show(a,N);
    show(ab,N);
    show(abc,N);

}

return 0;
}
