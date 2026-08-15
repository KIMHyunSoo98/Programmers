#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p1={1,2,3,4,5}, p2={2,1,2,3,2,4,2,5}, p3={3,3,1,1,2,2,4,4,5,5};
    vector<int> correct={0, 0, 0};
    int len1=5, len2=8, len3=10;
    
    for (int i=0; i < answers.size(); i++){
        correct[0] += (p1[i%len1] == answers[i]);        
        correct[1] += (p2[i%len2] == answers[i]);        
        correct[2] += (p3[i%len3] == answers[i]);
    }
    
    // sort(correct.begin(), correct.end(), [](const pair<int,int>& a, const pair<int,int>& b){
    //     if (a.first != b.first) 
    //         return a.first > b.first;
    //     return a.second < b.second;
    // });
    
    // for (auto& p: correct)
    //     cout << p.first << " " << p.second << endl;
    
    int max = *max_element(correct.begin(), correct.end());
    
    for (int i=0; i<3; i++)
        if (max == correct[i])
            answer.push_back(i+1);
    
    return answer;
}