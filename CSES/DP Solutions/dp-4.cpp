//comparator should return flase for equal values
#include<bits/stdc++.h>
using namespace std;
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//unordered_map<long long, int, custom_hash> safe_map;
const int p=1e9+7;
void run()
{
    int a,target;cin>>a>>target;
    vector<int> ans(a),dp(target+1,0);
    for(int i=0;i<a;i++)
    {
        cin>>ans[i];
        if(ans[i]<=target) dp[ans[i]]++;
        for(int j=1;j<=target;j++)
        {
            if(dp[j] and j+ans[i]<=target) dp[j+ans[i]]=(dp[j+ans[i]]+dp[j])%p;
        }
    }
    cout<<dp[target];
    
}
int main()
{
    int a=1;
    while(a--)
    {
        run();
        cout<<endl;
    }
}