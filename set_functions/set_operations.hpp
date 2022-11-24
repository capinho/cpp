#include <set>

//operation for printing the set
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    for (auto& element : s) {
        os << element << " ";
    }
    return os;
}

// create union operator
template <typename T>
std::set<T> operator+(const std::set<T>& s1, const std::set<T>& s2) {
    std::set<T> result;
    for (auto& element : s1) {
        result.insert(element);
    }
    for (auto& element : s2) {
        result.insert(element);
    }
    return result;
}

// create difference operator
template <typename T>
std::set<T> operator-(const std::set<T>& s1, const std::set<T>& s2) {
    std::set<T> result;
    for (auto& element : s1) {
        if (s2.find(element) == s2.end()) {
            result.insert(element);
        }
    }
    return result;
}

// create symmetric difference operator
template <typename T>
std::set<T> operator^(const std::set<T>& s1, const std::set<T>& s2) {
    std::set<T> result;
    for (auto& element : s1) {
        if (s2.find(element) == s2.end()) {
            result.insert(element);
        }
    }
    for (auto& element : s2) {
        if (s1.find(element) == s1.end()) {
            result.insert(element);
        }
    }
    return result;
}

// create cartesian product operator
template <typename T>
std::set<T> operator*(const std::set<T>& s1, const std::set<T>& s2) {
    std::set<T> result;
    for (auto& element1 : s1) {
        for (auto& element2 : s2) {
            result.insert(element1 + element2);
        }
    }
    return result;
}

// create power set operator with set and int
template <typename T>
std::set<T> operator^(const std::set<T>& s, int n) {
    std::set<T> result;
    if (n < 0) {
        throw std::invalid_argument("n must be non-negative");
    }
    if (n == 0) {
        result.insert(T());
    }
    else {
        for (auto& element : s) {
            std::set<T> temp = s ^ (n - 1);
            for (auto& element2 : temp) {
                result.insert(element + element2);
            }
        }
    }
    return result;
}
