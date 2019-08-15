#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector <string> s;

void printNumber(string output,int count_1,int count_0,int i,int N){
  if(i>N){
    if(count_0<=count_1 )
        s.push_back(output);
        //cout<<" op "<<output<<" "<<count_1<<" "<<count_0<<endl;
    return;
  }
  if((count_1+(N-i+1))<count_0) return;
  printNumber(output+"1",count_1+1,count_0,i+1,N);
  if(i!=1) printNumber(output+"0",count_1,count_0+1,i+1,N);


}
bool compare(string a,string b){
   return a>b;
}
int main(){
    int T;
    cin>>T;
    while(T--){
            int N;
            cin>>N;
            string op="";

            printNumber(op,0,0,1,N);
            //sort(s.begin(),s.end(),compare);

            for(string x:s)
                cout<<x<<" ";
            s.clear();
            cout<<endl;

    }

}
