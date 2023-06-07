#include <iostream>

using namespace std;

const int MAX_NUMBER_OF_MATRICES = 1001;

// BEGIN

struct matrix {
    int sizeL, sizeW;
    long long operations;
};

int n;

matrix dp[MAX_NUMBER_OF_MATRICES][MAX_NUMBER_OF_MATRICES];
matrix matrices[MAX_NUMBER_OF_MATRICES];

matrix matrix_multiply(matrix m1, matrix m2) {
    return {m1.sizeL, m2.sizeW,
            1ll * m1.sizeL * m1.sizeW * m2.sizeW
            + m1.operations + m2.operations};
}

matrix solve(int l, int r) {
    if (r - l == 1)
        return matrix_multiply(matrices[l], matrices[r]);

    if (l == r)
        return matrices[l];

    auto &ans = dp[l][r];
    if (~ans.operations)
        return ans;

    ans.operations = 9e18;

    for (int i = l; i < r; ++i) {
        auto ret = matrix_multiply(
                solve(l, i),
                solve(i + 1, r)
                );
        if (ret.operations < ans.operations)
            ans = ret;
    }

    return ans;
}

void matrixChainMultiplication() {
    for (auto & i : dp) for (auto & j : i)
            j.operations = -1;

    cout << "Enter the number of 2D matrices to get the minimum product operations for them: ";
    cin >> n;
    cout << '\n';

    do {
        cout << "Choose input format: \n enter 1 -> for " << n << " matrices, input " << n + 1 << " dimensions\n enter 2 -> input will be 2 dimensions for each matrix\n Choice: ";
        int choice; cin >> choice;
        if (choice == 1){
            cout << "Enter " << n + 1 << " dimensions: ";
            int dim;
            for (int i = 0; i <= n; ++i) {
                cin >> dim;

                if (i < n)
                    matrices[i].sizeL = dim;

                if (i > 0)
                    matrices[i - 1].sizeW = dim;
            }
        }
        else if (choice == 2){
            for (int i = 0, l, w; i < n; ++i) {
                cout << "Enter dimensions for matrix " << i + 1 << ": ";
                cin >> l >> w;
                cout << '\n';
                matrices[i] = {l, w, 0};
            }
        }

        if (choice == 1 or choice == 2) {
            cout << "Min number of operations: " << solve(0, n - 1).operations << '\n';
            break;
        }
        else {
            cerr << "Invalid choice!\n\n";
        }
    } while(true);


}



int main() {
    matrixChainMultiplication();
}