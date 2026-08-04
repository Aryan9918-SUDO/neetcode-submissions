class Solution {
public:
    unordered_map<string, string> parent;

    // Find with Path Compression
    string find(string x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // Union
    void Union(string x, string y) {
        string px = find(x);
        string py = find(y);

        if (px != py) {
            parent[py] = px;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, string> owner;

        // Initialize parent and owner
        for (auto &account : accounts) {

            string name = account[0];

            for (int i = 1; i < account.size(); i++) {

                string email = account[i];

                parent[email] = email;
                owner[email] = name;
            }
        }

        // Union all emails in the same account
        for (auto &account : accounts) {

            string firstEmail = account[1];

            for (int i = 2; i < account.size(); i++) {

                Union(firstEmail, account[i]);
            }
        }

        // Group emails by parent
        unordered_map<string, vector<string>> groups;

        for (auto &it : parent) {

            string email = it.first;

            string root = find(email);

            groups[root].push_back(email);
        }

        vector<vector<string>> ans;

        for (auto &it : groups) {

            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> account;

            account.push_back(owner[it.first]);

            for (auto &email : emails) {
                account.push_back(email);
            }

            ans.push_back(account);
        }

        return ans;
    }
};