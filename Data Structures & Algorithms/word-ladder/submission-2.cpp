class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        if(s.find(beginWord)!=s.end()) s.erase(beginWord);
        while(!q.empty()){
            string str = q.front().first;
            int count = q.front().second;
            q.pop();
            for(int i = 0 ; i < str.size() ; ++i){
                string temp = str;
                for(char ch = 'a' ; ch<='z';++ch){
                    str[i] = ch;
                    if(s.find(str)!=s.end()){
                        if(str == endWord) return count+1;
                        q.push({str,count+1});
                        s.erase(str);
                    }
                }
                str = temp;
            }
        }
        return 0;
    }
};
