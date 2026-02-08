#include <bits/stdc++.h>
using namespace std;
#define int long long

//any helper function used within constexpr function must be a constexpr
constexpr int fact(int n){
    return (!n) ? 1 : n*fact(n-1);
}

// return type array and it's a constexpr function named builder
constexpr array<int, 16> builder(){
    //blank c++ array with size of 16
    array<int, 16> arr{};
    for(int i=0; i<16; i++){
        arr[i] = fact(i);
    }
    //returning array pointer
    return arr;
}

signed main() {
    //calling constexpr function and storing pointer of first index in a variable
    constexpr auto fact = builder();
    for(int x: fact) 
        cout << x << " ";
}
