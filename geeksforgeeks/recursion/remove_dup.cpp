#include <bits/stdc++.h>
using namespace std;

bool containsDupli(string s){
    for(int i=1;i<s.length();++i){
        if(s[i]==s[i-1]) return true;
    }
    return false;
}

string removeDupli(int i,string &s,string op,char prev){
    if(i==s.length()) {
       // cout<<op<<endl;
        return op;
    }


    if(prev==s[i]){
        while(i<s.length() and s[i]==prev)++i;
        op.pop_back();

        return removeDupli(i,s,op,'\0');
    }


    return removeDupli(i+1,s,op+s[i],s[i]);


}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;



	    do{

	        s=removeDupli(0,s,"",'\0');

	    }
	    while(containsDupli(s));
	    cout<<s<<endl;


	}
	return 0;
}
