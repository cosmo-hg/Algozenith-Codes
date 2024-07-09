#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_map<int, int> countMap;
    unordered_map<int, int>::iterator it;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int X;
            cin >> X;
            minHeap.push(X);
            countMap[X]++;
        } else if (type == 2) {
            int X;
            cin >> X;
            it = countMap.find(X);
            if (it != countMap.end() && it->second > 0) {
                it->second--;
            }
        } else if (type == 3) {
            while (!minHeap.empty() && countMap[minHeap.top()] == 0) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                cout << minHeap.top() << endl;
            }
        }
    }

    return 0;
}