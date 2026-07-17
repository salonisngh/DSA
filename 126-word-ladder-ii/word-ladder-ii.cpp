class Solution {
public:
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> dist;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string beginWord) {
        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        } else {
            for (auto &par : parent[word]) {
                dfs(par, beginWord);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        dist[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            string original = word;

            for (int i = 0; i < word.size(); i++) {

                char old = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    if (!st.count(word))
                        continue;

                    if (!dist.count(word)) {

                        dist[word] = dist[original] + 1;
                        parent[word].push_back(original);
                        q.push(word);

                    }
                    else if (dist[word] == dist[original] + 1) {

                        parent[word].push_back(original);
                    }
                }

                word[i] = old;
            }
        }

        if (!dist.count(endWord))
            return {};

        dfs(endWord, beginWord);

        return ans;
    }
};