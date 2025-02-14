#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1st Approach -> Brute-force Approach
/*vector<vector<int>> rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>> rotate(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            rotate[j][n-i-1] = matrix[i][j];
        }
    }

    return rotate;
}*/

//2nd approach -> Optimal Approach
void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    vector < vector < int >> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector < vector < int >> rotated = rotate(arr);
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        } 
        cout << "\n";
    }

    return 0;
}