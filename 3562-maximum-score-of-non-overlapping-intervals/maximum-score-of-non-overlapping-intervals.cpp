class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> indices;
    };

    bool betterIndices(const vector<int>& a, const vector<int>& b) {
        return lexicographical_compare(
            a.begin(), a.end(),
            b.begin(), b.end()
        );
    }

    State better(State a, State b) {

        if (a.score != b.score)
            return (a.score > b.score ? a : b);

        // Same score -> lexicographically smaller indices
        if (betterIndices(a.indices, b.indices))
            return a;

        return b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // start, end, weight, original index
        vector<array<long long, 4>> v(n);

        for (int i = 0; i < n; i++) {
            v[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by start
        sort(v.begin(), v.end());

        vector<long long> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = v[i][0];

        // Find next compatible interval
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {

            // Need start > end because touching boundaries overlap
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                v[i][1]
            ) - starts.begin();
        }

        // dp[i][k]
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Skip
                State skip = dp[i + 1][k];

                // Take
                State take = dp[nxt[i]][k - 1];

                take.score += v[i][2];
                take.indices.push_back((int)v[i][3]);

                // IMPORTANT:
                // We compare indices in sorted order.
                sort(take.indices.begin(), take.indices.end());

                dp[i][k] = better(take, skip);
            }
        }

        return dp[0][4].indices;
    }
};