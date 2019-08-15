#include <bits/stdc++.h>
using namespace std;
void showStack(stack<char> s,int i){
    cout<<"i "<<i<<" stack : ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    stack<char> stck;
        int cnt=0;
	    string postfix="";

	    for(int i=0;i<str.length();++i){

            if(str[i]=='^' || str[i]=='*' || str[i]=='/'|| str[i]=='+'||
                        str[i]=='-' || str[i]=='(' || str[i]==')'){

                            if(str[i]==')'){

                                while(stck.top()!='('){
                                    postfix+=stck.top();
                                    stck.pop();

                                }

                                stck.pop();
                            }
                            else{

                                stck.push(str[i]);
                            }

             }
            else{

                    postfix+=str[i];
                }
            showStack(stck,i);
	    }
	    cout<<postfix<<endl;
	}
	return 0;
}
