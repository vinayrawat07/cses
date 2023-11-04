#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node{
    ll sum;
    ll prefix;
    ll suffix;
    ll maxi;
    // Node operator+ (Node b){
    //     return {sum+b.sum , max(prefix,sum+b.prefix)}
    // }
};

vector<ll>arr;
vector<Node>s_tree;

void merge(int pos){
    s_tree[pos].sum =s_tree[2*pos+1].sum+s_tree[2*pos+2].sum;
    s_tree[pos].prefix =max(s_tree[2*pos+1].prefix, s_tree[2*pos+1].sum+ s_tree[2*pos+2].prefix);
    s_tree[pos].suffix = max(s_tree[2*pos+2].suffix, s_tree[2*pos+1].suffix + s_tree[2*pos+2].sum);
    s_tree[pos].maxi = max(s_tree[2*pos+1].maxi,max(s_tree[2*pos+2].maxi,s_tree[2*pos+1].suffix + s_tree[2*pos+2].prefix));
}

void build(int pos,int s,int e){
    if(s==e){
        s_tree[pos] = {arr[s],max(0ll,arr[s]),max(0ll,arr[s]),max(0ll,arr[s])};
        return;
    }else{
        int mid = (s+e)/2;
        build(2*pos+1,s,mid);
        build(2*pos+2,mid+1,e);
        merge(pos);
    }
}

void update(int pos,int ind,ll val,int s,int e){
    if(ind<s || ind>e){
        return;
    }
    if(ind==s && ind==e){
        arr[s] = val;
        s_tree[pos] = {arr[s],max(0ll,arr[s]),max(0ll,arr[s]),max(0ll,arr[s])};
        return;
    }else{
        int mid = (s+e)/2;
        update(2*pos+1,ind,val,s,mid);
        update(2*pos+2,ind,val,mid+1,e);
        merge(pos);
    }


}





void solve()
{
    int n,q; cin>>n>>q;
    arr.resize(n);
    s_tree.resize(4*n);

    for(ll & v: arr) cin>>v;

    build(0,0,n-1);

    while(q--){
        int ind,val;
        cin>>ind>>val;
        ind--;
        update(0,ind,val,0,n-1);
         
        cout<<s_tree[0].maxi<<endl;

    }


}

int main() {
solve();

return 0;
}