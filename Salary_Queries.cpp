#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ordered_set = tree<pair<ll,ll>,null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>;

void solve()
{
    ordered_set st;
    int n,q; cin>>n>>q;
    vector<ll>arr(n);

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        
        st.insert({arr[i],i});
    }

    while(q--){
        char c ; cin>>c;
        if(c=='!'){
            ll ind,val;
            cin>>ind>>val;
            ind--;
            ll oldVal = arr[ind];
            st.erase({oldVal,ind});
            arr[ind] = val;
            st.insert({val,ind});
        }else{
            ll mini,maxi; cin>>mini>>maxi;
            int k = st.order_of_key({mini,0});
            int l = st.order_of_key({maxi,INT_MAX});
            cout<<(l-k)<<endl;
        }

    }
    

    
}

int main() {
solve();

return 0;
}