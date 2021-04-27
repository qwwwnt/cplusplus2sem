#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    std::vector<string> v;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        v.push_back(s);
    }

    std::sort(v.begin(), v.end(), [](const string &a, const string &b) { return a.length() < b.length(); });
    std::reverse(v.begin(), v.end());
    auto end = std::unique(v.begin(), v.end());

    for (auto i = v.begin(); i != end; ++i) {
        std::cout << *i << std::endl;
    }
    return 0;
}