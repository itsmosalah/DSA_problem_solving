#include <bits/stdc++.h>

using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

class NoPossibleAnswer : std::exception {};

class InitialBusPassengersCalculation {
    int answer;
    int numberOfWays{};
    int maxIncrease{};
    int maxDecrease{};
    int maxCapacity;
    vector<int>changes;
public:
    InitialBusPassengersCalculation(vector<int>&changes, int maxCapacity) : changes(changes), maxCapacity(maxCapacity) {
        try {
            answer = calculateAnswer();
        } catch (NoPossibleAnswer&e){
            answer = 0;
        }
    };

    int getAnswer() const{
        return answer;
    }
private:
    int calculateAnswer(){
        numberOfWays = calculateNumberOfWays();
        if (numberOfWays == 0)
            throw NoPossibleAnswer();
        return numberOfWays;
    }

    int calculateNumberOfWays(){
        calculateAllTimeMaxAndMin();
        return evaluateNumberOfWaysFormula();
    }

    void calculateAllTimeMaxAndMin(){
        maxIncrease = 0;
        maxDecrease = 0;
        int accumulativeChanges = 0;
        for (int change : changes){
            updateChangesBoundaries(accumulativeChanges += change);
        }
    }

    void updateChangesBoundaries(int accumulativeChanges){
        if (accumulativeChanges < 0)
            maxDecrease = min(maxDecrease, accumulativeChanges);
        maxIncrease = max(maxIncrease, accumulativeChanges);
    }

    int evaluateNumberOfWaysFormula() const{
        int minStartingValue = -maxDecrease;
        int maxStartingValue = maxCapacity - maxIncrease;
        return max(maxStartingValue - minStartingValue + 1, 0);
    }

};

int main() {
    io;
    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    auto solution = InitialBusPassengersCalculation(v, w);
    cout << solution.getAnswer() << endl;
}