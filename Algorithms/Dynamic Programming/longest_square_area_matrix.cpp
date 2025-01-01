#include<iostream>
#include<vector>
using namespace std;

//Using Recursion
int solve(vector<vector<int>> mat, int i, int j, int &maxi){
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;
    }
    
    int right = solve(mat, i, j+1, maxi);
    int diagonal = solve(mat, i+1, j+1, maxi);
    int down = solve(mat, i+1, j, maxi);
    
    int ans;
    if(mat[i][j] == 1){
        ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else{
        return 0;
    }
}

//Using Recursion & Memoization
int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int right = solveMem(mat, i, j+1, maxi, dp);
    int diagonal = solveMem(mat, i+1, j+1, maxi, dp);
    int down = solveMem(mat, i+1, j, maxi, dp);
    
    if(mat[i][j] == 1){
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else{
        return dp[i][j] = 0;
    }
}

//Using Tabulation    
int solveTab(vector<vector<int>> &mat, int &maxi){
    int row = mat.size();
    int col = mat[0].size();
    
    vector<vector<int>> dp(row+1, vector<int> (col+1, 0));
    
    for(int i = row-1; i >= 0; i--){
        for(int j = col-1; j >= 0; j--){
            
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];
            
            if(mat[i][j] == 1){
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
}

int maxSquare(int n, int m, vector<vector<int>> mat){
    // int maxi = 0;
    // solve(mat, 0, 0, maxi);
    // return maxi;
    
    int maxi = 0;
    vector<vector<int>> dp(n , vector<int> (m, -1));
    int ans = solveMem(mat, 0, 0, maxi, dp);
    return maxi;
    
    // int maxi = 0;
    // solveTab(mat, maxi);
    // return maxi;
}

int main() {
    int n, m;
    cout << "Enter the number of rows (n) and columns (m) of the matrix: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int maxSize = maxSquare(n, m, mat);
    cout << "Maximum size of the square submatrix with all 1's: " << maxSize << endl;

    return 0;
}