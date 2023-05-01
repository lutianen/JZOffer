/**
 * @file Union-Find 并查集
 * @brief
 *
 * @author Lux
 */

#include <vector>

namespace Lux {
    class UnionFind {
    private:
        // 连通分量的个数
        int count;
        // 存储每个节点的父节点
        std::vector<int> parent;

    public:
        // n 为图中节点的个数
        // 时间复杂度：O(n)
        UnionFind(int n) : count(n), parent(count) {
            for (int i = 0; i < count; ++i) {
                parent[i] = i;
            }
        }

        // 将节点 p 和 q 连通
        void Union(int p, int q) {
            int rootp = Find(p);
            int rootq = Find(q);
            if (rootp == rootq) return;

            parent[rootq] = rootp;
            count--;
        }

        // 进行路径压缩，保证树的高度保持在常数，使得各个 API 时间复杂度为O(1)
        int Find(int x) {
            if (parent[x] != x) parent[x] = Find(parent[x]);
            return parent[x];
        }

        // 当前图中的连通域数量
        int Count() const { return count; }

        // 判断节点 p、q 是否连通
        bool Connected(int p, int q) { return Find(q) == Find(p); }
    };
}  // namespace Lux
