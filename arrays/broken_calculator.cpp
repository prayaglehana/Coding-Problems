#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void showArray(int *ar,int n){
   // cout<<"array : ";
    for(int i=n-1;i>=0;--i) cout<<ar[i]<<"";
    cout<<endl;
}
string multiply(int *a,int n1,int *b,int n2){
    int *res=new int[n1+n2];
    for(int i=0;i<n1+n2;++i)
        res[i]=0;


    int c=0;
    int r=0;
    for(int i=0;i<n2;++i){
        int carry=0;
        r=i;
        c=0;
        int  p;
        int t;

        for(int j=0;j<n1;++j){
                p=b[i]*a[j]+carry;
                t=res[r]+p%10+c;
                res[r]=(t)%10;
                ++r;
                c=(t)/10;
                carry=(p)/10;
            }

        if(((p/10)+c)!=0) res[r++]=(p/10)+c;

    }

   string mul="";
   for(int k=0;k<r;++k)
        mul=mul+(char(res[k]+'0'));
    return mul;



}
int main(){

int a[10000];// 32 * 21
int b[10];

int N,a_len=0;
cin>>N;
a[0]=0;

int n=N;

while(n>0){
    a[a_len++]=n-10*(n/10);
    n/=10;
}


for(int i=N-1;i>=2;--i){

    int b_len=0;
    int it=i;
    while(it>0){
        b[b_len++]=it-10*(it/10);
        it/=10;
    }
//    cout<<endl;
//    showArray(a,a_len);
//    showArray(b,b_len);
//    cout<<endl;
    string m=multiply(a,a_len,b,b_len);

    for(int j=0;j<m.length();++j)
        a[j]=m[j]-'0';
    a_len=m.length();
}

//for(int i=0;i<a_len;++i) cout<<a[i]<<" ";
showArray(a,a_len);
//cout<<multiply(a,4,b,3);

return 0;}
