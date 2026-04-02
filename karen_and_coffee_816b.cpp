#include <bits/stdc++.h>
using namespace std;
#define int int64_t

// Contest: 816B (Karen and Coffee)
// Solution: To avoid tle, it needs double prefix sum. 1st one shows that each temp is admissible by how many condition. And 2nd one is the prefix sum of whether it satisfies condition or not
// Keyword: sweep line difference array double prefix sum binary search dsa

signed main() {
    int n, k, q;
    cin >> n >> k >> q;
    int a[200001] = {};

    // Temperature is admissible among l to r. So, setting 1 in left position and -1 just to the next of r as a boundary marker. [1 0 1 1 0 -1 0]
    for(int i=0; i<n; i++){
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }

    // Prefix sum [1 1 2 3 3 2 2]
    for(int i=1; i<200001; i++){
        a[i] += a[i-1];
    }

    // Array of possibility (whether safisty the condition or not). [0 0 1 1 1 1 1]
    for(int i=0; i<200001; i++){
        (a[i]>=k) ? a[i]=1 : a[i]=0;
    }

    // Another prefix sum. [0 0 1 2 3 4 5]
    for(int i=1; i<200001; i++){
        a[i] += a[i-1];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << a[r]-a[l-1] << endl;
    }
}
