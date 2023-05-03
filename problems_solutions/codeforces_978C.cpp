#include <bits/stdc++.h>

using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define el '\n'

int main() {
    io;
    int n, m;
    cin >> n >> m;

    vector<long long> prefixSumOfDorms(n + 1);
    prefixSumOfDorms[0] = 0;

    for (int i = 1; i <= n; ++i) {
        long long dorm;
        cin >> dorm;
        prefixSumOfDorms[i] = dorm + prefixSumOfDorms[i - 1];
    }

    long long letter;
    int currentDorm = 1;
    while(m--){
        cin >> letter;
        while(letter > prefixSumOfDorms[currentDorm])
            currentDorm++;
        cout << currentDorm << ' ' << letter - prefixSumOfDorms[currentDorm - 1] << el;
    }
}