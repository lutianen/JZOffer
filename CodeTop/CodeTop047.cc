/**
 * @brief 比较版本号
 * @link https://leetcode.cn/problems/compare-version-numbers/
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> vs1, vs2;
        getVers(vs1, version1);
        getVers(vs2, version2);

        if (vs1.size() != vs2.size()) {
            size_t len = vs1.size() < vs2.size() ? vs2.size() : vs1.size();
            while (vs1.size() < len) vs1.push_back("0");
            while (vs2.size() < len) vs2.push_back("0");
        }

        for (size_t i = 0; i < vs1.size(); ++i) {
            if (std::stoi(vs1[i]) < std::stoi(vs2[i]))
                return -1;
            else if (std::stoi(vs1[i]) > std::stoi(vs2[i]))
                return 1;
        }

        return 0;
    }

private:
    void getVers(vector<string>& vs, const string& version) {
        if (version.empty()) return;

        size_t cur = 0;
        int st = 0, ed = 0;
        while (cur < version.size()) {
            if (version[cur] == '.' || cur == version.size() - 1) {
                ed = version[cur] == '.' ? cur - 1 : cur;
                vs.push_back(version.substr(st, ed - st + 1));
                st = cur + 1;
            }
            ++cur;
        }
    }
};

int main() {
    Solution so;
    // string version1 = "1.01", version2 = "1.001";
    string version1 = "1.0", version2 = "1.0.0";
    // string version1 = "0.1", version2 = "1.1";
    std::cout << so.compareVersion(version1, version2) << std::endl;
    ;
}