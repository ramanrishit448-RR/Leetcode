class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rowCounts;
        
        for (int i = 0; i < mat.size(); ++i) {
            int count = 0;
            for (int val : mat[i]) {
                if (val == 1) count++;
                else break;
            }
            rowCounts.push_back({count, i});
        }
        
        sort(rowCounts.begin(), rowCounts.end());
        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(rowCounts[i].second);
        }
        
        return result;
    }
};