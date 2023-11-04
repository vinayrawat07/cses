#include <bits/stdc++.h>
using namespace std;
using ll = long long ;


struct Node{
    ll prefix; 
    ll sum;
};

vector<ll>arr;
vector<Node>s_tree;

void build_st(int pos,int s,int e){
    if(s==e){
        s_tree[pos].sum = s_tree[pos].prefix = arr[s];
        return;
    }else{
        int mid = (s+e)/2;
        build_st(2*pos+1,s,mid);
        build_st(2*pos+2,mid+1,e);
        s_tree[pos].sum = s_tree[2*pos+1].sum+s_tree[2*pos+2].sum;
        s_tree[pos].prefix = max(s_tree[2*pos+1].prefix, s_tree[2*pos+1].sum+s_tree[2*pos+2].prefix);
    }
}

void update(int pos,int ind,ll val,int s,int e){
    if(ind<s || ind>e){
        return;
    }
    if(ind==s && ind==e){
        s_tree[pos].sum  = s_tree[pos].prefix = arr[s] = val;
       
        return;
    }else{
        int mid = (s+e)/2;
        update(2*pos+1,ind,val,s,mid);
        update(2*pos+2,ind,val,mid+1,e);
        s_tree[pos].sum = s_tree[2*pos+1].sum+s_tree[2*pos+2].sum;
        s_tree[pos].prefix = max(s_tree[2*pos+1].prefix, s_tree[2*pos+1].sum+s_tree[2*pos+2].prefix);
    }
}

Node getmaxi(int pos,int l,int r,int s,int e){
    if(l>e || r<s){
        Node temp;
        temp.prefix = 0;
        temp.sum = 0;
        return temp;
    }
    if(l<=s && r>=e){
        return s_tree[pos];
    }
    int mid = (s+e)/2;
     Node a = getmaxi(2*pos+1,l,r,s,mid);
     Node b = getmaxi(2*pos+2,l,r,mid+1,e);

    Node res;
    res.sum = a.sum+ b.sum;
    res.prefix = max(a.prefix,a.sum+b.prefix);
    return res;
}



void solve()
{
    int n,q; cin>>n>>q;
    arr.resize(n);
    for(ll & v: arr) cin>>v;

    s_tree.resize(4*n);
    build_st(0,0,n-1);

    for (int i = 0; i < q; i++)
    {
        int c; cin>>c;
        if(c==1){
            ll ind,val; cin>>ind>>val;
            ind--;
            update(0,ind,val,0,n-1);  
        }else{
            int l,r; cin>>l>>r;
            l--; r--; 
            Node ans= getmaxi(0,l,r,0,n-1);
            ll a = max(ans.prefix,(ll)0);
            cout<<a<<endl;

           
        }
    }
   
    



}

int main() {
solve();

return 0;
}