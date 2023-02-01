#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    // Overall Time Complexity: O(1)
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
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
        int start = i % 3, end = (i % 3) + 1;
        if (end == 3) {
            start = 1;
            --end;
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
        
        cout << i << ": " << start << " " << end << "--> " << buckets[0].first << " " << buckets[1].first << " " << buckets[2].first << endl;
    }
    
    // Output
//    cout << buckets[0].first << " " << buckets[1].first << " " << buckets[2].first << endl;
    
    
    return 0;
}
