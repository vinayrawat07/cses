#include <iostream>
#include <set>

struct CompareFirstElement {
    bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
        return lhs.first < rhs.first;
    }
};

int main() {
    std::set<std::pair<int, int>, CompareFirstElement> mySet;

    mySet.insert(std::make_pair(2, 5));
    mySet.insert(std::make_pair(1, 8));
    mySet.insert(std::make_pair(3, 3));

    std::pair<int, int> value(2, 0);

    auto it = mySet.lower_bound(value);

    if (it != mySet.end()) {
        std::cout << "Lower bound found: (" << it->first << ", " << it->second << ")\n";
    } else {
        std::cout << "Lower bound not found\n";
    }

    return 0;
}
