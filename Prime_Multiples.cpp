#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>primes(q);
    ll k  = q;
    for (int i = 0; i <  q; i++)
    {
        cin>>primes[i];
    }
    vector<ll>countDivisior(q+1);

    for(int mask = 1;mask<=(1<<k);mask++){
        int noOfDivisior = 0;
        ll temp = n;
        for(int i = 0; i< k;i++){
            if((1<<i) & mask){
                noOfDivisior++;
                temp /= primes[i];
            }
        }
        countDivisior[noOfDivisior] += temp;
    }
    ll ans = 0;
    for(int i = 1;i<=k;i++){
       
        if(i%2==0){
            ans -=countDivisior[i];
        }else{
            ans +=countDivisior[i];
        }
    }
    cout<<ans<<endl;
    
    
}

int main() {
solve();

return 0;
}