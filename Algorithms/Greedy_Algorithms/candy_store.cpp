#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> CandyStore(int candies[], int N, int K){
    sort(candies, candies + N);
    int mini = 0;
    int buy = 0;
    int free = N-1;

    while(buy <= free){
        mini = mini + candies[buy];
        buy = buy + 1;
        free = free - K;
    }

    int maxi = 0;
    buy = N-1;
    free = 0;

    while(free <= buy){
        maxi = maxi + candies[buy];
        buy--;
        free = free + K;
    }

    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);
    return ans;
}

int main() {
    int N;
    cout << "Enter the number of candies: ";
    cin >> N;

    int K;
    cout << "Enter the value of K: ";
    cin >> K;

    int* candies = new int[N];
    cout << "Enter the candies: ";
    for(int i = 0; i < N; i++) {
        cin >> candies[i];
    }

    vector<int> result = CandyStore(candies, N, K);
    cout << "Minimum total: " << result[0] << endl;
    cout << "Maximum total: " << result[1] << endl;

    delete[] candies;
    return 0;
}