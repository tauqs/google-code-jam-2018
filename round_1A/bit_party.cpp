#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h> 

using namespace std;

#define cmax 1000
typedef long long ll;

vector<ll> m(cmax);
vector<ll> s(cmax);
vector<ll> p(cmax); 

int main() {
	
	int t,R,B,C;
    cin>>t;
    
    for(int i=0; i<t; i++)
    {
    	cin>>R;
    	cin>>B;
    	cin>>C;

    	for(int j=0; j<C; j++){ 
    		cin>>m[j];
    		cin>>s[j];
    		cin>>p[j];
    	}

    	ll minT = 2;
    	ll maxT = 1e18 + 1e9;
    	vector<int> cap(C,0);
    	ll time;
 		while(minT<maxT){
 		   time = (minT + maxT)/ 2;
 		   for(int j=0; j< C; j++){
 		   	cap[j] = max(0, min(m[j],(time-p[j])/s[j]));
 		   }
 		   sort(cap.begin(), cap.end());
 		   ll num_bits = 0;
 		   for(int j=0; j<C; j++){
 		   		if(j>R-1) break;
 		   		if(num_bits>=B) break;
 		   		num_bits += cap[C-j-1];
 		   }
 		   if(num_bits>=B){
 		   		maxT = time;
 		   }
 		   else{
 		   		minT = time+1;
 		   }
 		}
        
    	printf("Case #%d: %lld\n",(i+1), minT);
    }
	return 0;
}