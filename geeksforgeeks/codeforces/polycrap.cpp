#include<iostream>
using namespace std;

bool check(string a,string b){
        int i=0,j=0;
        if(b.length()<a.length()) return false;

        char prevCh=a[0];

        for(int i=0;i<a.length();++i){
                if(a[i]!=prevCh){
                    while(b[j]==prevCh)++j;
                    if(j>=b.length()) return false;

                }

                if(a[i]!=b[j]){
                    return false;
                }
                ++j;
                prevCh=a[i];
        }
    while(b[j]==prevCh)++j;
     if(j<b.length()) return false;


    return true;
}
int main(){

int T;
cin>>T;
while(T--){

    string a,b;
    cin>>a;
    cin>>b;
    if(check(a,b))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
return 0;}


