#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll>arr,st1,st2;

void build_st1(int pos,int s,int e){
    if(s==e){
        st1[pos] = s+ arr[s];
        return ;
    }else{
        int mid = (s+e)/2;
        build_st1(2*pos+1,s,mid);
        build_st1(2*pos+2,mid+1,e);
        st1[pos] = min(st1[2*pos+1],st1[2*pos+2]);
    }
    
}

void build_st2(int pos,int s,int e){
    if(s==e){
        st2[pos] =  arr[s]-s;
        return ;
    }else{
        int mid = (s+e)/2;
        build_st2(2*pos+1,s,mid);
        build_st2(2*pos+2,mid+1,e);
        st2[pos] = min(st2[2*pos+1],st2[2*pos+2]);
    }
    
}

void update1(int pos,int ind,int val,int s,int e){
    if(ind<s || ind>e){
        return ;
    }
    if(ind==s && ind==e){
        st1[pos] = val+s;
        arr[s] = val;
        return;
    }
    int mid = (s+e)/2;
    if(s!=e){
        update1(2*pos+1,ind,val,s,mid);
        update1(2*pos+2,ind,val,mid+1,e);
        st1[pos] = min(st1[2*pos+1] , st1[2*pos+2]);
    }
}

void update2(int pos,int ind,int val,int s,int e){
    if(ind<s || ind>e){
        return ;
    }
    if(ind==s && ind==e){
        st2[pos] = val-s;
        
        return;
    }
    int mid = (s+e)/2;
    if(s!=e){
        update2(2*pos+1,ind,val,s,mid);
        update2(2*pos+2,ind,val,mid+1,e);
        st2[pos] = min(st2[2*pos+1] , st2[2*pos+2]);
    }
}

ll query1(int pos,int l ,int r,int s,int e){
    if(l>e || r<s){
        return INT_MAX;
    }
    if(l<=s && r>=e){
        return st1[pos];
    }
    
    int mid = (s+e)/2;
    return min(query1(2*pos+1,l,r,s,mid),query1(2*pos+2,l,r,mid+1,e));
}

ll query2(int pos,int l ,int r,int s,int e){
    if(l>e || r<s){
        return INT_MAX;
    }
    if(l<=s && r>=e){
        return st2[pos];
    }
    
    int mid = (s+e)/2;
    return min(query2(2*pos+1,l,r,s,mid),query2(2*pos+2,l,r,mid+1,e));
}

void print(){
    for(auto it: st1){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it: st2){
        cout<<it<<" ";
    }
    cout<<endl;
}




void solve()
{
    int n; cin>>n; int q; cin>>q;
    arr.resize(n);
    st1.resize(4*n,INT_MAX);
    st2.resize(4*n, INT_MAX);

    for(ll & v: arr) cin>>v;

    build_st1(0,0,n-1);
    build_st2(0,0,n-1);

    while (q--)
    {
         int c; cin>>c;
         if(c==1){
            ll ind,val;
            cin>>ind>>val;
            ind--;
           
            update1(0,ind,val,0,n-1);
            update2(0,ind,val,0,n-1);
          //  print();
            
         }else{
            int ind; cin>>ind;
            ind--;
            
            ll a1 = query1(0,ind,n-1,0,n-1);
            ll a2 = query2(0,0,ind,0,n-1);
           
            int ans =  min(a1-ind,a2+ind);
            cout<<ans<<endl;

         }
    }
    

    
}

int main() {
solve();

return 0;
}