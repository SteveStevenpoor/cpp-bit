#include <Bit.h>
#include <vector>
#include <gtest/gtest.h>


TEST(update, TestingUpdate) {
    Bit b{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}};
    EXPECT_TRUE(b.giveUnderlyingArrayAt(3) == 4);
    b.update(3, 15);
    EXPECT_TRUE(b.giveUnderlyingArrayAt(3) == 15);
    b.update(7, -5);
    EXPECT_TRUE(b.giveUnderlyingArrayAt(7) == -5);
    b.update(2, 1);
    EXPECT_TRUE(b.giveUnderlyingArrayAt(2) == 1);
    b.update(10, 155);
    EXPECT_TRUE(b.giveUnderlyingArrayAt(10) == 0);
    b.update(1, -2134);
    EXPECT_TRUE(b.giveUnderlyingArrayAt(1) == -2134);
}

TEST(sum, TestingSum) {
    Bit b{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}};
    EXPECT_TRUE(b.sum(0,7) == 36);
    EXPECT_TRUE(b.sum(1,7) == 35);
    EXPECT_TRUE(b.sum(2,7) == 33);
    EXPECT_TRUE(b.sum(0,0) == 1);
    EXPECT_TRUE(b.sum(7,7) == 8);
    EXPECT_TRUE(b.sum(2,5) == 18);
    EXPECT_TRUE(b.sum(6,10) == 15);
}

TEST(ctor, CopyCtorTest) {
    Bit b{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}};
    Bit ab = b;
    ab.update(3, 50);
    EXPECT_TRUE(b.sum(0, 7) != ab.sum(0, 7));
}

TEST(cao, CopyAssignmentOperatorTest) {
    Bit b1{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}};
    Bit b2{std::vector<int>{2, 3, 4, 5, 6, 7, 8, 9}};
    Bit b3{std::vector<int>{3, 4, 5, 6, 7, 8, 9, 10}};
    EXPECT_TRUE(b1.sum(0, 7) != b2.sum(0, 7));
    b2 = b1;
    EXPECT_TRUE(b1.sum(0, 7) == b2.sum(0, 7));
    b1 = b2 = b3;
    EXPECT_TRUE(b1.sum(0, 7) == b3.sum(0, 7));
}