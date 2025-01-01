#include<iostream>
#include<vector>
using namespace std;

int minimumDays(int s, int m, int n){
    int sundays = s/7;
    int buyingDays = s - sundays;
    int totalFood = s*m;
    int ans = 0;

    if(totalFood % n == 0){
        ans = totalFood/n;
    }
    else{
        ans = totalFood/n + 1;
    }

    if(ans <= buyingDays){
        return ans;
    }
    else{
        return -1;
    }
}

int main(){
    int n, m, s;
    cout << "Enter the maximum amount of food that can buy each day " << endl;
    cin >> n;

    cout << "Enter the number of days required to survive " << endl;
    cin >> s;

    cout << "Enter the amount of food required on each day " << endl;
    cin >> m;

    if(minimumDays(s, m, n) != -1)
        cout << "The minimum number of days survived is " << minimumDays(s, m, n);
    else
        cout << "You cannot survive" << endl;
    return 0;
}