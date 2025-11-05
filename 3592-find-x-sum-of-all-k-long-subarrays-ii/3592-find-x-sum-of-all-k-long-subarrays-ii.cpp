#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<long long, long long> cnt;
        
        // ( -freq, -value ), value
        multiset<pair<pair<long long,long long>, long long>> best, rest;
        long long curSum = 0; // sum of best
        
        auto insertVal = [&](long long v) {
            long long f = cnt[v];
            auto it = best.find({{-f, -v}, v});
            if (it != best.end()) {
                curSum -= f * v;
                best.erase(it);
            } else {
                it = rest.find({{-f, -v}, v});
                if (it != rest.end()) rest.erase(it);
            }
            cnt[v]++;
            f++;
            rest.insert({{-f, -v}, v});
        };

        auto removeVal = [&](long long v) {
            long long f = cnt[v];
            auto it = best.find({{-f, -v}, v});
            if (it != best.end()) {
                curSum -= f * v;
                best.erase(it);
            } else {
                it = rest.find({{-f, -v}, v});
                if (it != rest.end()) rest.erase(it);
            }
            cnt[v]--;
            f--;
            if (f > 0) rest.insert({{-f, -v}, v});
        };

        auto balance = [&]() {
            while ((int)best.size() < x && !rest.empty()) {
                auto it = rest.begin();
                long long f = -it->first.first;
                long long v = -it->first.second;
                rest.erase(it);
                best.insert({{-f, -v}, v});
                curSum += f * v;
            }
            while ((int)best.size() > x) {
                auto it = prev(best.end());
                long long f = -it->first.first;
                long long v = -it->first.second;
                best.erase(it);
                curSum -= f * v;
                rest.insert({{-f, -v}, v});
            }
            if (!best.empty() && !rest.empty()) {
                while (!best.empty() && !rest.empty()) {
                    auto itB = prev(best.end());
                    auto itR = rest.begin();
                    if (itB->first < itR->first) break;
                    long long f1 = -itB->first.first, v1 = -itB->first.second;
                    long long f2 = -itR->first.first, v2 = -itR->first.second;
                    best.erase(itB), rest.erase(itR);
                    curSum -= f1 * v1;
                    rest.insert({{-f1, -v1}, v1});
                    best.insert({{-f2, -v2}, v2});
                    curSum += f2 * v2;
                }
            }
        };

        vector<long long> ans;
        for (int i = 0; i < n; i++) {
            insertVal(nums[i]);
            if (i >= k) removeVal(nums[i - k]);
            balance();
            if (i >= k - 1) ans.push_back(curSum);
        }
        return ans;
    }
};
