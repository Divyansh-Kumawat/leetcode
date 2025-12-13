#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Comparator for outer priority queue
    struct OuterCompare {
        bool operator()(
            const pair<int, priority_queue<string, vector<string>, greater<string>>>& a,
            const pair<int, priority_queue<string, vector<string>, greater<string>>>& b
        ) const {
            return a.first > b.first; // min-heap based on business priority
        }
    };

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        auto isValidCode = [&](string &s) {
            if (s.empty()) return false;
            for (char c : s) {
                if (!isalnum(c) && c != '_')
                    return false;
            }
            return true;
        };

        // Inner PQs (lexicographical order)
        vector<priority_queue<string, vector<string>, greater<string>>> innerPQ(4);

        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i]) continue;
            if (!isValidCode(code[i])) continue;
            if (!priority.count(businessLine[i])) continue;

            innerPQ[priority[businessLine[i]]].push(code[i]);
        }

        // Outer PQ (business priority)
        priority_queue<
            pair<int, priority_queue<string, vector<string>, greater<string>>>,
            vector<pair<int, priority_queue<string, vector<string>, greater<string>>>>,
            OuterCompare
        > pq;

        for (int i = 0; i < 4; i++) {
            if (!innerPQ[i].empty()) {
                pq.push({i, innerPQ[i]});
            }
        }

        vector<string> result;

        while (!pq.empty()) {
            auto [p, codesPQ] = pq.top();
            pq.pop();

            while (!codesPQ.empty()) {
                result.push_back(codesPQ.top());
                codesPQ.pop();
            }
        }

        return result;
    }
};
