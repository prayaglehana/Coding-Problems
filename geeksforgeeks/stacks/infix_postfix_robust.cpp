#include <bits/stdc++.h>
#include <string>
using namespace std;
stack<char> st;
bool priority(char s){
    switch(s){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        default :
            return 0;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--){
	    string str,s;
	    cin >> str;
	    st.push('(');
	    str.push_back(')');
        for(int i=0;str[i]!='\0';i++){
            if(priority(str[i])==0 && str[i]!='(' && str[i]!=')'){
                s.push_back(str[i]);
            }
            else if(str[i] == '(')
                st.push(str[i]);
            else if(str[i] == ')'){
                while(st.top()!='('){
                    s.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if(priority(str[i])){
                while(priority(st.top()) >= priority(str[i]) && priority(st.top())){
                    s.push_back(st.top());
                    st.pop();
                }
                st.push(str[i]);
            }
            else{}
        }
        cout << s << endl;
    }
	return 0;
}
