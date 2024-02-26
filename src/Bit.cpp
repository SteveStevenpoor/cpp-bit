#include "Bit.h"

Bit::Bit(std::vector<int> arr) {
    size_ = arr.size();
    data_ = new int[size_]();
    underArr_ = arr;

    for (int i = 0; i < size_; i++) {
        increment(i, arr[i]);
    }
}

void Bit::print() const {
    for (int i = 0; i < size_; i++) {
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
}

int Bit::f(int x) const {
    return x & (x + 1);
}

int Bit::g(int x) const {
    return x | (x + 1);
}

int Bit::getPrefixSum(const int pos) const {
    if (pos < 0) {
        return 0;
    }

    int ans = 0, curPos = pos;
    while (curPos >= 0) {
        ans += data_[curPos];
        curPos = f(curPos) - 1;
    }
    return ans;
}

void Bit::increment(const int pos, const int val) {
    int i = pos;
    while (i < size_) {
        data_[i] += val;
        i = g(i);
    }
}

int Bit::sum(const int left, const int right) const {
    return (getPrefixSum(right) - getPrefixSum(left - 1));
}

void Bit::update(const int pos, const int val) {
    increment(pos, val - underArr_[pos]);
    underArr_[pos] = val;
}

Bit::~Bit()
{
    delete[] data_;
}
