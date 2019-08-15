#include<bits/stdc++.h>
using namespace std;

int segment(char ch){

    switch (ch){
        case '0' : return 6;
        case '1' : return 2;
        case '2' : return 5;
        case '3' : return 5;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 3;
        case '8' : return 7;
        case '9' : return 5;
    }


}
int totalSegments(string s,int n){
    int tsegments=0;
    for(int i=0;i<n;++i) tsegments+=segment(s[i]);
    return tsegments;
}

string smallestNumber(int t,int n){
        string op="";
        int curT=0;
        for(int i=1;i<=n;++i){

            for(int j=0;j<=9;++j){
                char digit=j+'0';
                //cout<<"d"<<digit<<" mashq "<<((curT+segment(digit))+(n-i)*2)<<endl;
                if(((curT+segment(digit))+(n-i)*2)<=t && ((curT+segment(digit))+(n-i)*7)>=t){
                    op+=digit;
                    curT+=segment(digit);
                    break;
                }
            }


        }

      return op;
}


int main(){
int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int tsegments=totalSegments(s,n);
  //  cout<<tsegments<<endl;
    cout<<smallestNumber(tsegments,n)<<endl;

}

return 0;}
