
#include <bits/stdc++.h>
using namespace std;
int a[1000000];
void sortByFreq(int arr[],int n);
int main() {


	int t;
	cin >> t;


	while(t--){


	    int n;
	    cin >> n;

	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }

	    sortByFreq(a,n);
	    for(int i=0;i<n;++i)cout <<a[i]<<" "; cout<<endl;
	}

	return 0;
}


/*This is a function problem.You only need to complete the function given below*/
//Complete this function
//The array is declared globally
unordered_map<int,int> freq;
bool mycompare(int a,int b){
    if(freq[a]==freq[b]) return a<=b;

    return freq[a]>freq[b];
}
void sortByFreq(int arr[],int n)
{   freq.clear();
     vector <int> v;
     for(int i=0;i<n;++i){
         ++freq[arr[i]];
         v.push_back(arr[i]);
     }

    // for(int i=0;i<n;++i)cout<<arr[i]<<" : "<<freq[arr[i]]<<endl;
     sort(v.begin(),v.end(),mycompare);

     for(int i=0;i<n;++i){

         cout<<v[i]<<" ";
     }


}
