class Solution {
public:
    int ladderLength(string beginWord, string endWord, 
    vector<string>& wordList){
        
        unordered_set<string>s(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        if(s.find(beginWord)!=s.end()){
            s.erase(beginWord);
        }
        q.push({beginWord, 1});

        while(!q.empty()){
            string word = q.front().first;
            string temp = word;
            int steps = q.front().second;
            q.pop();
            for(int i = 0 ; i < word.size() ; ++i){
                for(char ch = 'a' ; ch<='z' ; ch++){
                    word[i] = ch;
                    if(s.find(word)!=s.end()){
                        if(word == endWord) return steps+1;
                        s.erase(word);
                        q.push({word, steps+1});
                    }
                    word = temp;
                }
            }
        }
        return 0;
    }
};
