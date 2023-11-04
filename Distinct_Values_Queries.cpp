// NOT a hard question simple coordinate compression and then MO'S algorithm


// When i make function in solve the TLE shows in atmost every function
// when i define auto & qr -- then TLE for 3 function 
// when i use Query& qr then it passed

#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;


const int rootN = 555;
int freq[200000];
int arr[200000];
int distinct;


struct Query{
    int l;  // for left
    int r;  // for right    
    int no; // index should be stable
    int blockno;    // which block no it will lie-- Actually It has no function in this question (if anyother question will then it used )

    bool operator < (Query& q2)
    {
        if(blockno < q2.blockno)
            return 1;
        else if(blockno > q2.blockno)
            return 0;
        else return r < q2.r;
    }


};

void Add(int & elem){           // if distinct element is added 
    if(!freq[elem]) distinct++;
    freq[elem]++;
}

void remove(int & elem){
    freq[elem]--;
    if(!freq[elem]) distinct--;
}


void adjust(int & curr_l,int & curr_r, Query& q){
    while(curr_l>q.l){              // Self explanatory
        curr_l--;
        Add(arr[curr_l]);
    }

    while(curr_r<q.r){
        curr_r++;
        Add(arr[curr_r]);
    }

    while(curr_l<q.l){
        remove(arr[curr_l]);
        curr_l++;    
    }

    while(curr_r>q.r){
        remove(arr[curr_r]);
        curr_r--;
    }


}




void findDistinct(vector<Query>& queries){

    sort(queries.begin(),queries.end());
    distinct = 1;
    memset(freq,0,sizeof freq);
    vector<int>ans(queries.size());
    

    int curr_l = queries[0].l;
    int curr_r = queries[0].l;

    freq[arr[curr_l]]++;

    for(Query& qr : queries){
        adjust(curr_l,curr_r,qr);
        ans[qr.no] = distinct;
    }

    for(int  x: ans){
        cout<<x<<'\n';
    }
    

}




int main() {
fast_io;
int n,q; cin>>n>>q;
    map<int,int>compressed_index;

    
    int index = 1;          // compressionn is done all values lies btw 1 to 2e5+1;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(compressed_index.find(arr[i])!= compressed_index.end()){
            arr[i] = compressed_index[arr[i]];
        }else{
            compressed_index[arr[i]] = index;
            arr[i] = index++;
        }
    }
    vector<Query>queries(q);           // make simple Query array 
   
    for (int i = 0; i < q; i++)
    {
        int u,v;
       cin >> u >>v;
       queries[i].l = u-1;
       queries[i].r = v-1;
       queries[i].no = i;
       queries[i].blockno = u/rootN;
    }
    findDistinct(queries);

return 0;
}