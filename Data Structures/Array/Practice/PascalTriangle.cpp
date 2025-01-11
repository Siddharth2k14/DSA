#include<iostream>
#include<vector>
using namespace std;

//Variantion 1
/*int nCr(int n, int r){
    long long res = 1;
    
    for(int i = 0; i < r; i++){
        res = res * (n-i);
        res = res / (i+1);
    }

    return res;
}

int PascalTriangle(int r, int c){
    int element = nCr(r-1, c-1);
    return element;
}*/

//Variant 2
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> rowAns;
    rowAns.push_back(1);

    for(int col = 1; col < row; col++){
        ans = ans * (row-col);
        ans = ans / (col);
        rowAns.push_back(ans);
    }

    return rowAns;
}

vector<vector<int>> pascalTriangle(int numRows){
    vector<vector<int>> ans;
    for(int i = 1; i <= numRows; i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    // int r = 6;
    // int c = 3;

    // cout << "The element at " << r << " and " << c << " is " << PascalTriangle(r, c) << endl;

    // return 0;

    int n = 10;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;

}