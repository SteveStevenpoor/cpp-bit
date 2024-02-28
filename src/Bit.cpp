#include "Bit.h"

Bit::Bit(const std::vector<int>& arr) {
    size_ = arr.size();
    data_ = new int[size_]();
    underArr_ = arr;

    for (int i = 0; i < size_; i++) {
        increment(i, arr[i]);
    }
}

Bit::Bit(const Bit& other) :
    size_(other.size_), underArr_(other.underArr_) {
    data_ = new int[size_]();

    for (int i = 0; i < size_; i++) {
        increment(i, underArr_[i]);
    }
}

Bit& Bit::operator=(const Bit& other) {
    if (data_ == other.data_) {
        return *this;
    }
    size_ = other.size_;
    underArr_ = other.underArr_;
    delete[] data_;

    data_ = new int[size_]();
    for (int i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
    return *this;
}

void Bit::print() const {
    for (int i = 0; i < size_; i++) {
        std::cout << underArr_[i] << " ";
    }
    std::cout << std::endl;
}

int Bit::f(const int x) const {
    return x & (x + 1);
}

int Bit::g(const int x) const {
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
    if (right >= size_) {
        return getPrefixSum(size_ - 1) - getPrefixSum(left - 1);
    }
    return (getPrefixSum(right) - getPrefixSum(left - 1));
}

void Bit::update(const int pos, const int val) {
    if (pos >= size_) {
        return;
    }
    increment(pos, val - underArr_[pos]);
    underArr_[pos] = val;
}

int Bit::giveUnderlyingArrayAt(const int& pos) const {
    if (pos < size_) {
        return underArr_[pos];
    } else {
        return 0;
    }
}

Bit::~Bit()
{
    delete[] data_;
}
