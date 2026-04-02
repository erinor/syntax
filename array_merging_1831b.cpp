#include <bits/stdc++.h>
using namespace std;

// Contest: 1831B (Array Merging)
// Solution: the maximum sum of longest contiguous frequency of same number
// Keyword: greedy constructive algorithm maximum longest contiguous continuous frequency subarray

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1,-1), b(n+1,-1);
    map<int, int> m, bm;

    // Storing longest contiguous frequency for all numbers in a map
    int len=1;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i]==a[i-1]){
            len++;
            m[a[i]] = max(m[a[i]], len);
        } else {
            len=1;
            m[a[i]] = max(m[a[i]], len);
        }
    }

    // Single global variable won't work. So, Using another map (bm) and tracking the longest contiguous frequency for 2nd array
    // Then, merged (increment) the frequencies
    len=1;
    for(int i=1; i<=n; i++){
        cin >> b[i];
        if(b[i]==b[i-1]){
            len++;
        } else {
            len=1;
        }
        if(len>bm[b[i]]){
            m[b[i]]++;
            bm[b[i]] = len;
        }
    }

    // Finding the maximum value among map m
    int mx = 0;
    for(auto &[k,v]: m){
        mx=max(mx, v);
    }
    cout << mx << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}
