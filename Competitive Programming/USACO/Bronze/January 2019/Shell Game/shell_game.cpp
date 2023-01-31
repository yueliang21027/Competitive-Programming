#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // File IO
//    freopen("shell.in", "r", stdin);
//    freopen("shell.out", "w", stdout);
    
    vector<int> shells = {1, 2, 3}; // Stores Shells
    map<int, int> visits; // Stores Visits
    
    // Read Input
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        // Read Input
        int a, b, g;
        cin >> a >> b >> g;
        
        // Swap Shells
        // Find Positions To Swap
        int a_col = find(shells.begin(), shells.end(), a) - shells.begin();
        int b_col = find(shells.begin(), shells.end(), b) - shells.begin();
        swap(shells[a_col], shells[b_col]);
        
        // Find Column Of Guess
        int col = find(shells.begin(), shells.end(), g) - shells.begin();
        // Increment Visit
        visits[++col]++;
    }
   
    
    int max_visits = 0;
    // Find Max Number Of Visits
    for (pair<int, int> visit : visits) {
        max_visits = max(max_visits, visit.second);
    }
        
    
    // Output
    cout << max_visits << endl;
    
    
    return 0;
}
