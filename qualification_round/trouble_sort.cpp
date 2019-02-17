#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int get_error_index(int n){
    
    int ne = (n+1)/2;
    int no = n/2;
    int e[ne];
    int o[no];
    
    for(int i=0; i< n; i++){
        if(i%2==0){
            cin>>e[i/2];
        }
        else{
            cin>>o[i/2];
        }
    }
    
    sort(e, e + ne);
    sort(o, o + no);
    
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i<ne && j<no){
        if(j>=i){
            if(e[i]>o[j]){
                return 2*i;
            }
            i++;
        }
        else{
            if(e[i]<o[j]){
                return 2*j+1;
            }
            j++;
        }
    }
    
    return -1;
}

int main() {

    int t;
    cin>>t;
    
    int n;
    
    for(int i=0; i<t; i++)
    {
        cin>>n;
        
        int ans = get_error_index(n);
        if(ans >=0){
            printf("Case #%d: %d\n",(i+1), ans);
        }
        else{
            printf("Case #%d: OK\n",(i+1));
        }
        
    }
    return 0;
}
