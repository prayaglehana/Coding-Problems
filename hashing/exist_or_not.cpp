#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;

	cin>>T;
	while(T--){
		bool *exist=new bool[200002];
		int N;
		cin>>N;
		while(N--){
			int x;
			cin>>x;
			exist[x+100000]=true;
		}

		int Q;
		cin>>Q;
		int ar[100000];
		for(int i=0;i<Q;++i)cin>>ar[i];
		for(int i=0;i<Q;++i){


			if(!exist[ar[i]+100000]) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}


	}
	return 0;
}
