class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                               vector<string>& businessLine,
                               vector<bool>& isActive) {

    unordered_set<string> validBL = {
        "electronics", "grocery", "pharmacy", "restaurant"
    };

    auto isValidCode = [&](string &s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    };

    vector<string> electronics, grocery, pharmacy, restaurant;

    for (int i = 0; i < code.size(); i++) {
        if (!isActive[i] || !isValidCode(code[i]) || !validBL.count(businessLine[i]))
            continue;

        if (businessLine[i] == "electronics") electronics.push_back(code[i]);
        else if (businessLine[i] == "grocery") grocery.push_back(code[i]);
        else if (businessLine[i] == "pharmacy") pharmacy.push_back(code[i]);
        else restaurant.push_back(code[i]);
    }

    sort(electronics.begin(), electronics.end());
    sort(grocery.begin(), grocery.end());
    sort(pharmacy.begin(), pharmacy.end());
    sort(restaurant.begin(), restaurant.end());

    vector<string> ans;
    ans.insert(ans.end(), electronics.begin(), electronics.end());
    ans.insert(ans.end(), grocery.begin(), grocery.end());
    ans.insert(ans.end(), pharmacy.begin(), pharmacy.end());
    ans.insert(ans.end(), restaurant.begin(), restaurant.end());

    return ans;
}

};