class Solution {
public:
    struct Ele {
        int v, r, c;
        Ele(int v, int r, int c): v(v), r(r), c(c) {};
        bool operator > (const Ele &other) const {
            return v > other.v;
        }
    };
    int solve_by_sc_on(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<Ele, vector<Ele>, greater<Ele>> pq;

        for (int i=0;i<n;++i) {
            pq.push(Ele(matrix[i][0], i, 0));
        }

        while (--k) {
            auto e = pq.top();
            pq.pop();
            if (e.c + 1< matrix[0].size()) pq.push(Ele(matrix[e.r][e.c+1], e.r, e.c+1));
        }

        return pq.top().v;
    }

    bool check(vector<vector<int>>& matrix, int target, int cur) {
        int R=matrix.size(), C=matrix[0].size();
        int tot = R * C;
        int r=R-1, c=0;
        while (r >= 0) {
            if (matrix[r][c] <= cur) {
                if (c + 1 < C) ++c;
                else --r;
            } else {
                --r;
                tot -= (C-c);
            }
        }

        return tot >= target;
    }

    int solve_by_sc_o1(vector<vector<int>>& matrix, int k) {
        int R=matrix.size(), C=matrix[0].size();
        int l = matrix[0][0], h = matrix[R-1][C-1], m;
        while (l<h) {
            m=l+(h-l)/2;
            if (check(matrix, k, m)) { // current k >= k
                h=m;
            } else {
                l=m+1;
            }
        }
        return l;
    };
        
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //return solve_by_sc_on(matrix, k);
        return solve_by_sc_o1(matrix, k);
    }
};


// SC O(n), TC O(klogn)
//[[1,5,9],
//[10,11,13],
//[12,13,15]], k = 8

// SC O(1), TC O(?)
// binary search
// cur <= target, ->
// cur > target, up, remove all the elemented on the right side (current included)
