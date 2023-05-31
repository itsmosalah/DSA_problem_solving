#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define el '\n'


void run_case(int test_case) {
    int n, k;
    cin >> n >> k;
    vector<int>remainders(n);
    ll sum = 0;

    for(int i = 0, x; i < n; i++) {
        cin >> x;
        sum += x / k;
        remainders[i] = x % k;
    }

    // try to greedily match remainders
    sort(remainders.rbegin(), remainders.rend());
    int l = 0, r = n - 1;
    while (l < r){
        while (remainders[l] + remainders[r] < k and l < r)
            r--;
        if (l == r)
            break;
        sum++; // remainders add up to K, meaning they match as a pair
        l++; r--;
    }

    cout << sum << endl;
}


int main(){
    io;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        run_case(i);
}
