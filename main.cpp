#include <iostream>
#include <Bit.h>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    Bit b{v};
    b.print();
    b.update(0, 10);
    b.update(0, 1);
    b.update(7, 10);
    b.update(7, 2);
    std::cout << b.sum(6, 7);
    return 0;
}
