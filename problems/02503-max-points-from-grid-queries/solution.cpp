class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            vector<int> answers(queries.size());
            map<int, int> answers_cache;
            vector<vector<bool>> explored(grid.size(), vector<bool>(grid[0].size()));
    
            vector<int> sorted_queries(queries);
            sort(sorted_queries.begin(), sorted_queries.end());
    
            set<tuple<int, int, int>> start_points, deadends;
            start_points.insert(make_tuple(0,0,0));
            int answer = 0;
            unsigned min_deadend = 0;
            for (int k=0; k<sorted_queries.size(); k++) {
                if (sorted_queries[k]>min_deadend) {
                    deadends.clear();
                    auto sp = start_points.begin();
                    while (sp!=start_points.end() && get<0>(*sp)<sorted_queries[k]) {
                        auto[weight, i, j] = *sp;
                        answer += explore(grid, explored, i, j, sorted_queries[k], deadends);
                        ++sp;
                    }
                    start_points = deadends;
    
                    if (deadends.size()>0)
                        min_deadend = get<0>(*(deadends.begin()));
                    else
                        min_deadend = -1;
                }
                answers_cache.insert({sorted_queries[k], answer});
            }
    
            // for (auto[key, value]: answers_cache) {
            //     cout << key << " : " << value << "\n";
            // }
    
            for (int k=0; k<queries.size(); k++) {
                answers[k] = answers_cache[queries[k]];
            }
            return answers;
        }
    
        int explore(vector<vector<int>>& grid, vector<vector<bool>>& explored, int i, int j, int query, set<tuple<int, int, int>>& deadends) {
            // cout << "i: " << i << ", j: " << j << "\n";
            if (explored[i][j]) {
                // cout << "explored\n";
                return 0;
            }
            if (query<=grid[i][j]) {
                // cout << "too small\n";
                auto deadend = make_tuple(grid[i][j], i, j);
                auto position = lower_bound(deadends.begin(), deadends.end(), deadend);
                deadends.insert(position, deadend);
                return 0;
            }
            int result = 1;
            explored[i][j] = true;
            // cout << "i: " << i << ", j: " << j << "\n";
            if (i<grid.size()-1)
                result += explore(grid, explored, i+1, j, query, deadends);
            if (i>0)
                result += explore(grid, explored, i-1, j, query, deadends);
            if (j<grid[0].size()-1)
                result += explore(grid, explored, i, j+1, query, deadends);
            if (j>0)
                result += explore(grid, explored, i, j-1, query, deadends);
            return result;
        }
    };