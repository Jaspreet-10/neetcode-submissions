class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[], vector<bool>& exists) {
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;

        // Only add characters that actually exist
        for (int i = 0; i < V; i++) {
            if (exists[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return topo;
    }

    string foreignDictionary(vector<string>& dict) {
        vector<int> adj[26];
        vector<bool> exists(26, false);

        int N = dict.size();

        // Mark characters that actually exist
        for (auto word : dict) {
            for (auto c : word) {
                exists[c - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int len = min(s1.size(), s2.size());
            int ptr = 0;

            // Find first different character
            for (ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }

            // Invalid prefix case
            if (ptr == len && s1.size() > s2.size()) {
                return "";
            }
        }

        vector<int> topo = topoSort(26, adj, exists);

        // Cycle detection
        int totalCharacters = 0;
        for (int i = 0; i < 26; i++) {
            if (exists[i]) {
                totalCharacters++;
            }
        }

        if (topo.size() != totalCharacters) {
            return "";
        }

        string ans = "";

        for (auto node : topo) {
            ans += char(node + 'a');
        }

        return ans;
    }
};