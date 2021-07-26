// https://leetcode.com/problems/word-break/submissions/

#include<bits/stdc++.h>
using namespace std; 

map<string, bool> m; 
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
    //base case
    int n = s.length();
    if (s=="") return 1;

    // choice tree implementation 
    if(m.find(s)!=m.end()) return m[s];
    unordered_set<string> dic;
        for(string& word: wordDict) dic.insert(word);
    
    string prefix="";
    for(int i=0; i<n; i++){
        prefix+=s[i];
        if(dic.find(prefix) != dic.end()){
            if(wordBreak(s.substr(i+1), wordDict))
                return m[s]=1; 
        }
    }
    return m[s]=0;
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