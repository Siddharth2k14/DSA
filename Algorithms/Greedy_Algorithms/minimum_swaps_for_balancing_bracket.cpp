#include<iostream>
#include<cstring>
#include<vector>

int minNumberOfSwaps(std::string s){
    class std::vector<int> pos;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '['){
            pos.push_back(i);
        }
    }

    int count = 0; // To count encountered '['.
    int p = 0; // To track position of the next '['
    int sum = 0; // To store the result

    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '['){
            ++count;
            ++p;
        }
        else if(s[i] == ']'){
            --count;
        }

        if(count < 0){
            sum = sum + (pos[p]-i);
            std::swap(s[i], s[pos[p]]);
            ++p;

            count = 1;
        }
    }

    return sum;
}

int main(){
    std::string bracket;
    std::cout << "Enter the equal sequence of bracket here" << std::endl;
    std::cin >> bracket;

    std::cout << "The minimum number of swaps required to balance the sequence is -> " << minNumberOfSwaps(bracket) << std::endl;

    return 0;
}