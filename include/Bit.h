#ifndef BIT_H
#define BIT_H

#include <iostream>
#include <vector>

class Bit
{
    int* data_;
    std::vector<int> underArr_;
    int size_;

    public:
        Bit(const std::vector<int>& arr);
        Bit(const Bit& other);
        Bit& operator=(const Bit& other);
        ~Bit();
        void print() const;
        void update(const int pos, const int val);
        int sum(const int left, const int right) const;
        int giveUnderlyingArrayAt(const int& pos) const;

    protected:

    private:
        int f(const int x) const;
        int g(const int x) const;
        int getPrefixSum(const int pos) const;
        void increment(const int pos, const int val);

};

#endif // BIT_H
