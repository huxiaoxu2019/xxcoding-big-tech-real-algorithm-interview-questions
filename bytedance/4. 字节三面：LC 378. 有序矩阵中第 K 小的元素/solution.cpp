class Solution {
public:
    struct Ele {
        int v, r, c;
        Ele(int v, int r, int c): v(v), r(r), c(c) {};
        bool operator < (const Ele &other) const {
            return v > other.v;
        };
    };

    int solve_by_sc_on(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<Ele, vector<Ele>, less<Ele>> pq;

        for (int i=0;i<matrix.size();++i) {
            pq.push(Ele(matrix[i][0], i, 0));
        }

        while (--k) {
            auto e = pq.top();
            pq.pop();
            if (e.c + 1 < matrix.size()) pq.push(Ele(matrix[e.r][e.c+1], e.r, e.c+1));
        }
        return pq.top().v;
    };
    bool check(vector<vector<int>>& matrix, int target, int middle) {
        int n = matrix.size();
        int tot = n * n;
        int r = n - 1, c = 0;

        while (r >= 0) {
            if (matrix[r][c] <= middle) {
                if (c + 1 < n) ++c;
                else --r;
            } else {
                --r;
                tot -= (n-c);
            }
        }
        return tot >= target;
    }
    int solve_by_sc_o1(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l = matrix[0][0], h = matrix[n-1][n-1], m;
        while (l<h) {
            m = l + (h - l) / 2;
            if (check(matrix, k, m)) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //return solve_by_sc_on(matrix, k);
        return solve_by_sc_o1(matrix, k);
    }
};


//[[1,5,9],
//[10,11,13],
//[12,13,15]], k = 8 -> 13

// SC: O(n), TC: O(klogn)
// n = matrix.length() = matrix[0].length()
// priority_queue SP: O(n)
// pop() + push() -> O(lgn) -> O(klgn)

// SC: O(1), TC: O(nlogM), M = matrix[R-1][C-1] - matrix[0][0]
// ans [matrix[0][0], matrix[R-1][C-1]]
// middle -> 10
// if cur <= middle, move to the right side
// if cur > middle, move to the up side, tot -= the count of the right side
