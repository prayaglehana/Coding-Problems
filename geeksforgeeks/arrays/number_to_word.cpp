#include <bits/stdc++.h>
using namespace std;

string getWord(int d,int pos){
    if(pos==1){

        switch(d){
            case 0: return "";
            case 1: return "one";
            case 2: return "twenty";
            case 3: return "thirty";
            case 4: return "forty";
            case 5: return "fifty";
            case 6: return "sixty";
            case 7: return "seventy";
            case 8: return "eighty";
            case 9: return "ninety";
        }
    }
    switch(d){
        case 0: return "zero";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
    }
}
string tens(int pos){
    switch(pos){
        case 0: return "";
        case 1: return "";
        case 2: return " hundred";
        case 3: return " thousand";

    }
}

int main() {
	int n;
	int t;
	cin>>t;
	while(t--){
	    int num;
	    cin>>num;
	    int n=ceil(log10(num));
	    string word="";
	    for(int p=n-1;p>=0;--p){
            if(n>2 and p==1)word+="and ";
	        int digit=(num%int(round(pow(10,p+1)))-num%int(round(pow(10,p))))/(round(pow(10,p)));
	        cout<<digit<<" ";
	        word+=getWord(digit,p)+tens(p)+" ";
	    }
	    cout<<word<<endl;

	}
	return 0;
}
