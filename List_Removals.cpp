#include <bits/stdc++.h>
using namespace std;

vector<int>s_tree;
void build_st(int pos,int s,int e){
    if(s==e){
        s_tree[pos]=1;
        return;
    }
    int mid = (s+e)/2;
    build_st(2*pos+1,s,mid);
    build_st(2*pos+2,mid+1,e);
    s_tree[pos] = s_tree[2*pos+1]+s_tree[2*pos+2];
}

void update(int pos, int ind ,int s,int e){
    if(ind<s || ind>e){
        return;
    }
    if(ind==s && ind==e){
        s_tree[pos] -=1;
    }

    int mid = (s+e)/2;

    if(s!=e){
        update(2*pos+1,ind,s,mid);
        update(2*pos+2,ind,mid+1,e);
        s_tree[pos] = s_tree[2*pos+1]+s_tree[2*pos+2];
    }


}

int findSum(int pos,int l,int r,int s,int e){
    if(l<=s && r>=e){
        return s_tree[pos];
    }
    if(r<s || l>e){
        return 0;
    }
    int mid = (s+e)/2;
    return findSum(2*pos+1,l,r,s,mid)+ findSum(2*pos+2,l,r,mid+1,e);
}


void solve()
{
    int n; cin>>n;
    vector<int>arr(n);
    for(int & v:arr) cin>>v;
   
   vector<int>present(n+1,1);
   s_tree.resize(4*n);
   build_st(0,0,n-1);

   for (int i = 0; i < n; i++)
   {
        int sum; cin>>sum;
        int ind = 0;
        int l  = 0;
        int r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
           

            int cnt = findSum(0,0,mid,0,n-1);

            if(cnt>sum){
                r = mid-1;
            }else if( cnt<sum){
                l = mid+1;
            }else{
                if(present[mid]){
                    ind = mid;
                    break;
                }else{
                    r = mid-1;
                }
            }
        } 
        cout<<arr[ind]<<" "; 
        present[ind] = 0;
        update(0,ind,0,n-1);
   }
   
    

}

int main() {
solve();

return 0;
}