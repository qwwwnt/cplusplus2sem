#include <iostream>
#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>
#include <deque>
#include <vector>

struct print {
    template<typename T>
    void operator()(const T &o) {
        std::cout << o << ' ';
    }
};

int main() {
    //1
    std::deque<int> deq;
    for (int count = 1; count <= 10; ++count) {
        deq.push_back(count);
    }
    for (int index = 0; index < deq.size(); ++index)
        std::cout << deq[index] << ' ';

    std::cout << '\n';

    // 3
    std::vector<int> vect;
    vect.resize(deq.size());
    std::copy(deq.begin(), deq.end(), vect.begin());
    for (auto i : vect) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // 4
    std::sort(vect.begin(), vect.end(),
              std::greater<>());
    for (auto i : vect) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // 5
    std::uniform_int_distribution<> distr(1, 10);
    std::default_random_engine engine(
            std::chrono::steady_clock::now()
                    .time_since_epoch().count());
    std::deque<int> numbers(10);
    std::iota(numbers.begin(), numbers.end(), 1);
    std::shuffle(std::begin(numbers), std::end(numbers), engine);
    for (auto x : numbers) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    // 6
    std::cout << std::inner_product(deq.begin(), deq.end(),
                                    vect.begin(), 0) << std::endl;

    // 7
    std::cout << std::count_if(deq.begin(), deq.end(), [](int i) { return i > 4; }) << std::endl;

    // 8
    std::cout << std::accumulate(vect.begin(), vect.end(), 0) << std::endl;

    // 9
    std::cout << std::accumulate(deq.begin(), deq.end(), 1, [](auto x, auto y) { return x * y; }) << std::endl;

    // 10
    auto st = std::remove_if(vect.begin(), vect.end(), [](int i) { return ((i > 3) and (i % 2 == 0)); });
    vect.erase(st, vect.end());
    for (auto i : vect) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // 11
    auto start = std::remove(deq.begin(), deq.end(), 4);
    deq.erase(start, deq.end());
    for (int index = 0; index < deq.size(); ++index)
        std::cout << deq[index] << ' ';
    std::cout << '\n';

    // 13
    std::vector<int> vectt;
    vect.resize(deq.size());
    std::copy(deq.begin(), deq.end(), vect.begin());

    std::for_each(vectt.begin(), vectt.end(), print());

    // 14
    auto min_el = std::min_element(deq.begin(), deq.end());
    std::cout << *min_el << std::endl;
    auto max_el = std::max_element(deq.begin(), deq.end());
    std::cout << *max_el << std::endl;
}
