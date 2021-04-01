#include <iostream>
#include <numeric>
#include <algorithm>
#include <random>
#include <deque>
#include <array>
#include <list>
#include <iterator>
#include <map>

bool check(int x) {
    return (x % 2 == 0);
}

int main() {

    // 1
    std::default_random_engine generator;
    std::uniform_real_distribution<> dis(1, 10);
    std::array<int, 10> arr;
    std::generate(arr.begin(), arr.end(), [&]() mutable { return dis(generator); });

    // 2
    std::list<int> lis;
    std::partial_sum(arr.begin(), arr.end(), std::back_inserter(lis));

    // 3
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';
    std::copy(lis.begin(), lis.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';

    // 4
    std::map<int, bool> mp;
    for (auto &x : lis)
        mp[x] = check(x);
    for (std::map<int, bool>::iterator p = mp.begin(); p != mp.end(); ++p)
        std::cout << "mp[" << (*p).first << "] = " << (*p).second << std::endl;

}
