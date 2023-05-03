#include <bits/stdc++.h>

using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

const int N = 1e5 + 10;

bool isPrinted[N], isWaiting[N];
int n;

void printWaitingDependants(int x){
    while(isWaiting[x]) {
        cout << x << ' ';
        isPrinted[x] = true;
        x--;
    }
}

int main() {
    io;
    cin >> n;

    isPrinted[n + 1] = true;

    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        isWaiting[x] = true;
        if (isPrinted[x + 1])
        {
            printWaitingDependants(x);
        }
        cout << endl;
    }

}