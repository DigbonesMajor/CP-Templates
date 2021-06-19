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
    int a;cin>>a;
    vector<int> dp(a+1,INT_MAX);
    dp[a]=0;
    for(int j=a;j>=1;j--)
    {
        if(dp[j]==INT_MAX) continue;
        string temp=to_string(j);
        for(auto x:temp)
        {
            if(x-'0'!=0) dp[j-(x-'0')]=min(dp[j-(x-'0')],dp[j]+1);
        }
    }
    cout<<dp[0];
    
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