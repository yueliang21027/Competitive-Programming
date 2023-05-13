#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // Overall Time Complexity:
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // File IO
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    
    // Contains Road Segments: ([begin, end], speed_limit)
    vector<pair<pair<int, int>, int>> road;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        pair<pair<int, int>, int> segment;
        int prev_ending;
        if (road.size() == 0)
            prev_ending = 0;
        else
            prev_ending = road[road.size() - 1].first.second;
        
        segment = make_pair(make_pair(prev_ending, prev_ending + a), b);
        road.push_back(segment);
    }
    
    
    int max_speeding = 0;
    
    int curr_position = 0;
    int curr_ptr = 0;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        curr_position += a;

        pair<pair<int, int>, int> interval = {{curr_position, 0}, 0};
        int new_ptr = lower_bound(road.begin(), road.end(), interval) - road.begin();
        for (int p = curr_ptr; p < new_ptr; p++)
            max_speeding = max(max_speeding, b - road[p].second);
        
        curr_ptr = new_ptr - 1;

    }

    cout << max_speeding << endl;
    
    return 0;
}
