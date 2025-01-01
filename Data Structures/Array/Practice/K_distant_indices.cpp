#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//1st Approach
/*void keyFinder(vector<int> &nums, int key, vector<int> &keyIndex){
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == key){
            keyIndex.push_back(i);
        }
    }
}

vector<int> KDistantIndices(vector<int> &nums, int key, int k){
    vector<int> ans;
    vector<int> keyIndex;

    keyFinder(nums, key, keyIndex);

    int n = nums.size();

    for(int i = 0; i < n; i++){
        for(auto keyIdx : keyIndex){
            if(abs(i-keyIdx) <= k){
                ans.push_back(i);
                break;
            }
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    return ans;

}*/

//2nd Approach
vector<int> KDistantIndices(vector<int> &nums, int key, int k){
    vector<int> ans;
    int n = nums.size();
    set<int> result;

    for(int i = 0; i < n; i++){
        if(nums[i] == key){
            for(int j = max(0, i-k); j <= min(n-1, i+k); j++){
                result.insert(j);
            }
        }
    }

    ans.assign(result.begin(), result.end());
    return ans;
}

int main(){
    vector<int> nums = {2,2,2,2,2};
    int key = 2;
    int k = 2;

    vector<int> ans = KDistantIndices(nums, key, k);
    for(auto i : ans){
        cout << i << " ";
    }cout << endl;

    return 0;
}