class Solution {
public:
    // furthest-building-you-can-reach/solutions/4739509/why-dp-fails-here-greedy-approach-min-heap
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < h.size() - 1; ++i) {
            int diff = h[i + 1] - h[i];
            if (diff <= 0) continue;
            pq.push(diff);
            if (pq.size() > l) {
                b -= pq.top(); pq.pop();
            }
            if (b < 0) return i;
        }
        return h.size() - 1;
    }
};