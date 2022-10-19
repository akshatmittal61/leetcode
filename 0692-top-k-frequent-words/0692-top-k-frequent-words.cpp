class Solution
{
    public:
        vector<string> topKFrequent(vector<string> &words, int k)
        {
            unordered_map<string, int> mp;
            for (auto &word: words)
                ++mp[word];

            using PIS = pair<int, string> ;
            auto cmp =[](const PIS &lhs, const PIS &rhs)
            {
                if (lhs.first == rhs.first)
                    return lhs.second < rhs.second;

                return lhs.first > rhs.first;
            };
            priority_queue<PIS, vector < PIS>, decltype(cmp) > min_heap(cmp);

            for (auto &[word, cnt]: mp)
            {
                min_heap.push({ cnt,
                    word });

                if (min_heap.size() > k)
                    min_heap.pop();
            }

            vector<string> ans;
            while (!min_heap.empty())
            {
                ans.push_back(min_heap.top().second);
                min_heap.pop();
            }

            reverse(ans.begin(), ans.end());

            return ans;
        }
};