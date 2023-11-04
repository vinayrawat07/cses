#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxVal = 1e6+10;
void solve()
{
    int n; cin>>n;
    vector<int>value(n);
    for(int& v: value) cin>>v;

    vector<vector<int>> divisorOf(maxVal);      // We have to push all the divisor from 1 to 1e6+10; 
    for(int i =  2;i<=maxVal;i++){
        if(divisorOf[i].size()==0){
            divisorOf[i].push_back(i);                      
            for (int j = 2*i; j < maxVal; j += i)           //O(maxVal*log(maxVal))
            {
                divisorOf[j].push_back(i);
            }
            
        }
    }

    vector<int> valuesDivisibleBy(maxVal);
    vector<int> primeDivisiorOf(maxVal);

    for (  int i = 0; i < n; i++)
    {
        for(int mask = 1; mask< (1<<(divisorOf[value[i]].size()));mask++){
            int combination = 1;
            int primeDivisor = 0;

            for(int pos = 0;pos< divisorOf[value[i]].size(); pos++){
                if(mask & (1<<pos)){
                    combination*= divisorOf[value[i]][pos];
                    primeDivisor++;

                }

            }
            //cout<<combination<<endl;      ---     
            valuesDivisibleBy[combination]++;               // As let say 75 divided by  3,5  so 3*5*15 are stored there 
            primeDivisiorOf[combination] = primeDivisor;    // here 


        }
        
    }
    
    // for(int i = 1;i<=21;i++){
    //     cout<<divisorOf[i].size()<<" "<<valuesDivisibleBy[i]<<" "<<primeDivisiorOf[i]<<endl;
    // }


    ll totalNoofPossiblePairs = (ll) n*(n-1)/2;
    ll validPairs = 0;
    for (int i = 0; i < maxVal; i++)
    {
        if(primeDivisiorOf[i]%2!=0){
            validPairs += ((ll)valuesDivisibleBy[i]*(valuesDivisibleBy[i]-1))/2;
        }else{
            validPairs -= ((ll)valuesDivisibleBy[i]*(valuesDivisibleBy[i]-1))/2;
        }
    }

    cout<<totalNoofPossiblePairs - validPairs<<endl;
    
           

}

int main() {
solve();

return 0;
}