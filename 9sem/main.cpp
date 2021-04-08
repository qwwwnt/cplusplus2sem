#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<string, int> &a,
         pair<string, int> &b) {
    return a.second < b.second;
}

template<typename N>
N divide(N st, N fio) {
    if (st.find(fio) == st.end()) {
        throw std::invalid_argument("Can't divide by zero");
    }
}

class Students {
public:
    std::map<string, int> st;

    Students() {}

    void insert(string fio, int ball) {
        st.insert({fio, ball});
    }

    void list_students() {
        for (std::map<string, int>::iterator p = st.begin(); p != st.end(); ++p)
            std::cout << "FIO: " << (*p).first << "; ball = " << (*p).second << std::endl;
    }

    void standings() {
        vector<pair<string, int> > A;
        for (auto &it : st) {
            A.push_back(it);
        }
        sort(A.begin(), A.end(), cmp);
        for (auto &it : A) {

            cout << "FIO: " << it.first << "; ball = " << it.second << endl;
        }
    }

    void find(string fio) {
        auto it = st.find(fio);
        if (st.find(fio) == st.end()) { throw std::invalid_argument("This student doesnt exist"); }
        cout << it->second << endl;
    }

    void range(int ball) {
        for (std::map<string, int>::iterator p = st.begin(); p != st.end(); ++p)
            if ((*p).second == ball) {
                std::cout << (*p).first << std::endl;
            }
    }

};

int main() {
    Students s;
    s.insert("Andrew", 2);
    s.insert("Kola", 1);
    s.insert("Alex", 0);
    s.insert("Kira", 2);
    s.insert("Danil", 3);

    s.list_students();

    s.standings();

    s.range(2);

    s.find("hh");
}
