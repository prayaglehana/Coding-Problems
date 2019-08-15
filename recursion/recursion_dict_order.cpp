#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
bool isPossible(char *s,char* c){
   int i=0;


   while(true) {
        if(c[i]<s[i])    return false;
        else if(c[i]==s[i]) ++i;
        else if(c[i]>s[i]) return true;

        if(s[i]=='\0' && c[i]=='\0') return false;

   }
   return true;

}
bool shouldSwap(char str[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}

// Prints all distinct permutations in str[0..n-1]
void findPermutations(char* s,char* str, int index, int n)
{
    if (index >= n) {

        if(isPossible(s,str))
            {//cout<< str << endl;
            string temp(str);
            ans.push_back(temp);
		}
        return;
    }

    for (int i = index; i < n; i++) {

        // Proceed further for str[i] only if it
        // doesn't match with any of the characters
        // after str[index]
        bool check = shouldSwap(str, index, i);
        if (check) {
            swap(str[index], str[i]);
            findPermutations(s,str, index + 1, n);
            swap(str[index], str[i]);
        }
    }
}

bool compare(string a,string b){
return a<b;}


int main(){

    char str[10000]="";
    char strN[10000]="";

    cin>>str;
    for(int i=0;str[i]!='\0';++i) strN[i]=str[i];

    int N=strlen(str);

    findPermutations(strN,str, 0,N);


	sort(ans.begin(),ans.end());

	//print the set
	for(string x:ans){ //for each loop
		cout<<x<<endl;
	}


    return 0;
}
