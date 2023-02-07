#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // Overall Time Complexity:
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // File IO
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    
    // Read Input
    int m, n, k;
    cin >> m >> n >> k;
    
    // Go Through Each Line
    for (int i = 0; i < m; i++) {
        // Read Line
        string s;
        cin >> s;
        
        // Height
        for (int h = 0; h < k; h++) {
            // Print curr_count * K characters
            int curr_count = 1;
            for (int j = 1; j < n; j++) {
                // If Character Has Changed
                if (s[j] != s[j-1]) {
                    for (int q = 0; q < k*curr_count; q++) {
                        cout << s[j-1];
                    }
                    // Reset curr_count
                    curr_count = 1;
                } else
                    curr_count++;
            }
            
            for (int j = 0; j < k*curr_count; j++)
                cout << s[n - 1];
                
            cout << endl;
        }

    }
    
    
    return 0;
}
