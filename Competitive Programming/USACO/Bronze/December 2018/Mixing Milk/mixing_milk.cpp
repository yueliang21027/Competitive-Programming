#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    // Overall Time Complexity: O(1)
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // File IO
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    
    // Vector of Pairs Containing <milk, capacity>
    vector<pair<int, int>> buckets(3);
    
    // Read Input
    for (int i = 0; i < 3; i++) {
        int c, m;
        cin >> c >> m;
        buckets[i] = make_pair(m, c);
    }
    
    // Perform Pour Operations
    for (int i = 0; i < 100; i++) {
        
        // Operate on Indexes Start, End
        int start, end;
        if (i % 3 == 0) {
            start = 0;
            end = 1;
        } else if (i % 3 == 1) {
            start = 1;
            end = 2;
        } else if (i % 3 == 2) {
            start = 2;
            end = 0;
        }
        
        // If Bucket A Becomes Empty Before Bucket B Becomes Full
        if (buckets[start].first + buckets[end].first <= buckets[end].second) {
            buckets[end].first += buckets[start].first;
            buckets[start].first = 0;
        }

        // If Bucket B Becomes Full Before Bucket A Becomes Empty
        else if (buckets[start].first + buckets[end].first > buckets[end].second) {
            buckets[start].first -= (buckets[end].second - buckets[end].first);
            buckets[end].first = buckets[end].second;
        }
        
    }
    
    // Output
    cout << buckets[0].first << endl << buckets[1].first << endl << buckets[2].first << endl;
    
    
    return 0;
}
