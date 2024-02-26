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
        Bit(std::vector<int> arr);
        ~Bit();
        void print() const;
        int sum(const int left, const int right) const;
        void update(const int pos, const int val);

    protected:

    private:
        int f(int x) const;
        int g(int x) const;
        int getPrefixSum(const int pos) const;
        void increment(const int pos, const int val);

};

#endif // BIT_H
