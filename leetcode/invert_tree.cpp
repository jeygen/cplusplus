// gpt style

#include <vector>

using namespace std;

void invertBinaryTree(vector<int>& tree) {
    for (int i = 0; i < tree.size(); i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < tree.size() && right < tree.size()) {
            swap(tree[left], tree[right]);
        }
    }
}

