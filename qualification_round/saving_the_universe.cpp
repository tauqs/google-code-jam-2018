#include <iostream>
#include <cmath>
using namespace std;

int get_min_count(int D, string s){
    
    int ans = 0;
    int n = s.length();
    int arr[n];
    
    int cindex = 0;
    
    int currDamage = 0;
    int currPower = 1;
    for(int i=0; i<n; i++){
        if(s[i] == 'C'){
            arr[cindex] = i;
            cindex++;
            currPower*=2;
        }
        else{
            currDamage += currPower;
        }
    }
    
    if(currDamage <= D) return 0;
    
    for(int i=cindex-1; i>=0; i--){
        int tmp = n - 1 - (cindex -1 - i) - arr[i];
        int x = pow(2,i);
        int y = (currDamage - D + x-1)/x;
        if(tmp < y){
            y = tmp;
        }
        ans += y;
        currDamage -= x*y;
        if(currDamage <= D) return ans;
    }
    
    return -1;
}

int main() {
    
    int t;
    cin>>t;
    
    int d;
    string s;
    
    for(int i=0; i<t; i++)
    {
        cin>>d;
        cin>>s;
        int ans = get_min_count( d, s);
        if(ans >=0){
            printf("Case #%d: %d\n",(i+1), ans);
        }
        else{
            printf("Case #%d: IMPOSSIBLE\n",(i+1));
        }
        
    }
    return 0;
}
