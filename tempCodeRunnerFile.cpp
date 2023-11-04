#include <bits/stdc++.h>
using namespace std;

void build_st(int pos,int s,int e,vector<int>& arr,vector<int>& s_tree){
    if(s==e){
        s_tree[pos] = arr[s];
        return ;
    }
    int mid = (s+e)/2;
    if(s!=e){
        build_st(2*pos+1,s,mid,arr,s_tree);
        build_st(2*pos+2,mid+1,e,arr,s_tree);
        s_tree[pos] = s_tree[2*pos+1]+s_tree[2*pos+2];
    }

}

void update_st(int pos,int l,int r,int val,int s,int e,vector<int> & s_tree , vector<int> & lazy){
     // if totally inside
     if(l<=s && r>=e){
        s_tree[pos] += (e-s+1)*val;
        lazy[2*pos+1] = val;
        lazy[2*pos+2] = val;
        return;
     }
     if(l>e || r<s){
        return ;
     }

    int mid   = (s+e)/2;
    update_st(2*pos+1,l,r,val,s,mid,s_tree,lazy);
    update_st(2*pos+2,l,r,val,mid+1,e,s_tree,lazy);
}

int find_val(int pos,int ind,int s,int e,vector<int> & s_tree, vector<int> & lazy){
    if(lazy[pos]!=0){
        s_tree[pos] = (e-s+1)*lazy[pos];
        if(s!=e){
            lazy[2*pos+1] = lazy[pos];
            lazy[2*pos+2] = lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(ind<s || ind>e){
        return 0;
    }

    if(s==ind && e==ind){
        if(lazy[pos]!= 0){
            s_tree[pos]+= lazy[pos];
            lazy[pos] = 0;
        }
        return s_tree[pos];
    }
    int mid = (s+e)/2;
    return find_val(2*pos+1,ind,s,mid,s_tree,lazy);
    return find_val(2*pos+2,ind,mid+1,e,s_tree,lazy);

}

void solve()
{
    int n; cin>>n;
    int q; cin>>q;
    vector<int>arr(n);
    for(int & v: arr) cin>>v;

    vector<int>s_tree(4*n);

    build_st(0,0,n-1,arr,s_tree);
    vector<int>lazy(4*n);

    while(q--){
        int c; cin>>c;
        if(c==1){
            int a,b,u; cin>>a>>b>>u;
            a--; b--;
            update_st(0,a,b,u,0,n-1,s_tree,lazy);
        }else{
            int pos; cin>>pos;
            pos--;
            cout<<find_val(0,pos,0,n-1,s_tree,lazy)<<endl;
        }
    }

}

int main() {
solve();

return 0;
}