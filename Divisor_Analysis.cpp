#include <bits/stdc++.h>
using namespace std;


using ll = long long;
ll mod = 1e9+7;

ll exponent(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll result = exponent(a,b/2);
    if(b%2!=0){
        return (((result*result)%mod)*a)%mod;
    }
    return (result*result)%mod;


}

void solve()
{
    int n; cin>>n;
    // count are simply multiplication of powers+1
    // sum of divisors is multiplication of GP
    // product is simply count/2 * number

    long long cnt = 1;
    ll sum = 1;
    ll product = 1;
    ll number = 1;
    ll squareRoot = 1;

    for (int i = 0; i < n; i++)
    {
        ll val,power; cin>>val>>power;
        cnt = (cnt*(power+1))%mod;
        sum  = sum*((exponent(val,power+1)-1+mod)%mod*exponent(val-1,mod-2)%mod)%mod;
        number = (number*exponent(val,power))%mod;
        squareRoot = (squareRoot*exponent(val,power/2))%mod;

        
    }
    product =  exponent(number,cnt/2);
    if(cnt%2!=0){
        product  =(product*squareRoot)%mod;
    }

    cout<<cnt<<" "<<sum<<" "<<product<<endl;
    


    

}

int main() {
solve();

return 0;
}