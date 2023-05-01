#include <iostream>

#include "UnionFind.h"

#define EXPECT_EQ(x, y) \
    std::cout << ((x != y) ? "Failed." : "Success") << std::endl;

int main() {
    // Test initialization
    Lux::UnionFind uf(10);

    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(uf.Find(i), i);
        EXPECT_EQ(uf.Count(), 10);
    }

    // Test union
    uf.Union(0, 1);
    uf.Union(2, 3);
    uf.Union(4, 5);
    uf.Union(6, 7);
    uf.Union(8, 9);
    uf.Union(0, 2);
    uf.Union(4, 6);
    uf.Union(0, 4);

    // Test find and size after union
    EXPECT_EQ(uf.Find(0), 0);
    EXPECT_EQ(uf.Find(1), 0);
    EXPECT_EQ(uf.Find(2), 0);
    EXPECT_EQ(uf.Find(3), 0);
    EXPECT_EQ(uf.Find(4), 0);
    EXPECT_EQ(uf.Find(5), 0);
    EXPECT_EQ(uf.Find(6), 0);
    EXPECT_EQ(uf.Find(7), 0);
    EXPECT_EQ(uf.Find(8), 8);
    EXPECT_EQ(uf.Find(9), 8);

    EXPECT_EQ(uf.Count(), 2);
    EXPECT_EQ(uf.Connected(0, 1), true);
}