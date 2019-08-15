#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int showStack(stack<int> s){
    cout<<"stack : ";
    while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
    }
    cout<<endl;
}
void makeRightGreatest(int *a,int *r,int n){
        stack<int> s;

        int *indx=new int[n];
        int i=0;
        while(i<n){
                //showStack(s);
                if(s.empty()){
                    s.push(i);
                    ++i;
                    continue;
                }
                if(a[i]<=a[s.top()]){
                    s.push(i++);
                }
                else{
                    while(!s.empty() && a[i]>a[s.top()] ){
                        indx[s.top()]=i;
                        r[s.top()]=a[i];
                        s.pop();
                    }
                }
        }

        while(!s.empty()){
                int top=s.top();

                indx[top]=-1;
                r[top]=-1;
                s.pop();
        }

//        for(int i=0;i<n;++i)cout<<indx[i]<<" ";
//        for(int i=0;i<n;++i)cout<<r[i]<<" ";

        for(int i=1;i<n;++i){
            if(indx[i]==-1){
                if(a[0]>a[i])
                    r[i]=a[0];
                else if(indx[0]!=-1 && indx[0]<i){
                            if(a[indx[0]]>a[i])
                                    r[i]=a[indx[0]];
                }
            }
        }

}


int main(){

    int n;
    cin>>n;

    int *a=new int[n];

    int *r=new int[n];

    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    makeRightGreatest(a,r,n);
    for(int i=0;i<n;++i)cout<<r[i]<<" ";





return 0;}
