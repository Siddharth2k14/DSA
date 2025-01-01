#include<iostream>
#include<algorithm>
using namespace std;

string reverse_words(string S){
    string ans = "";
    string temp = "";

    for(int i = S.length()-1; i >= 0; i--){
        if(S[i] == '.'){
            reverse(temp.begin(), temp.end());
            ans = ans + temp;
            ans.push_back('.');
            temp = "";
        }
        else{
            temp.push_back(S[i]);
        }
    }

    reverse(temp.begin(), temp.end());
    ans = ans + temp;
    return ans;
}

int main(){
    string S;
    cout << "Enter the string here " << endl;
    cin >> S;

    cout << "The reverse string is " << reverse_words(S) << endl;
    return 0;
}