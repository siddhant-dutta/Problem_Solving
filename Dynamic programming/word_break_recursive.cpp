// https://leetcode.com/problems/word-break/submissions/

#include<bits/stdc++.h>
using namespace std; 

int wordBreak(string s, vector<string>& wordDict){
    //base case 
    int n = s.length();
    if (s=="") return 1;
    // choice tree implementation 
    unordered_set<string> dic;
        for(string& word: wordDict) dic.insert(word);
    
    string prefix="";
    for(int i=0; i<n; i++){
        prefix+=s[i];
        if(dic.find(prefix) != dic.end()){
            if(wordBreak(s.substr(i+1), wordDict))
                return 1; 
        }
    }
    return 0;
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