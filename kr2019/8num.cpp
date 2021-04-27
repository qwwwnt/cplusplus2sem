#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    std::multimap<string, int> sensorvalue;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int value;
        cin >> s;
        cin >> value;
        sensorvalue.insert({s, value});
    }

    int ns;
    cin >> ns;
    std::vector<string> outsensor;
    for (int i = 0; i < ns; i++) {
        string s;
        cin >> s;
        outsensor.push_back(s);
    }

    std::map<std::string, std::vector<int>> outmedianmap;
    for (int i = 0; i < ns; i++) {
        string namesensor = outsensor[i];
        std::vector<int> v;
        for (std::map<string, int>::iterator p = sensorvalue.begin(); p != sensorvalue.end(); ++p) {
            if (namesensor == (*p).first) {
                v.push_back((*p).second);
            }
        }
        sort(v.begin(), v.end());
        outmedianmap.insert({outsensor[i], v});

    }

    for (int i = 0; i < ns; i++) {
        for (std::multimap<string, std::vector<int>>::iterator p = outmedianmap.begin(); p != outmedianmap.end(); ++p) {
            if (outsensor[i] == (*p).first) {
                if (((*p).second).size() == 0) {
                    outsensor[i] = "no data";
                    std::cout << outsensor[i] << std::endl;
                } else if (((*p).second).size() != 0) {
                    std::cout << (*p).second[trunc((((*p).second).size() - 1) / 2)] << std::endl;
                }
            }
        }
    }
}
