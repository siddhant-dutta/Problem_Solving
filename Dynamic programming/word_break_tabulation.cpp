#include<bits/stdc++.h>
using namespace std; 

int dp[301];

int wordBreak(string s, vector<string>& wordDict){
/*
    Hypothesis: wordBreak(s, wordDict) function will tell whether a string s can be 
        formed using the strings given in the wordDict 

    Base case: when the string is an empty string it can always be formed 

    Induction/ choice tree: 
        1) if a prefix of a given string s is present in the wordDict
        and the remaining part of the string i.e wordBreak(suffix, wordDict) = true 
        then wordDict(s, wordDict) = true 

        2) for a particular string s we check for all possible prefixes. If any of them 
        gives value true then it is possible to make the s otherwise we cannot make 
        the string s using the words given in the wordDict
*/
    int n = s.size();
    //base case initiallization
    memset(dp, 0, sizeof(dp));
    dp[n]=1;

    unordered_set<string> dic;
    for(string& word: wordDict) dic.insert(word);

    // choice tree implementation  
    for(int i=n-1; i>=0; i--){
        string prefix; 
        for(int j=i; j<n; j++){
            prefix.push_back(s[j]);
            if(dic.find(prefix) != dic.end()){
                if(dp[j+1]) dp[i] = 1; 
            }
        }
    }
    return dp[0];
}

int main(){
    string s; 
    vector<string> wordDict; 
    cin>>s;
    char d; 
    string inp; 
    cin>>d;
    bool p=false;
    while(d!=']'){
        if(d=='[' || d==','){
            cin>>d;
        }
        else if(d=='\"'&&p==false){
            cin>>inp; wordDict.push_back(inp);
            cin>>d; 
            p=true; 
        }
        else if(d=='\"' && p==true){
            cin>>d; p=false; 
        }
    }
    cout<<wordBreak(s, wordDict);
}