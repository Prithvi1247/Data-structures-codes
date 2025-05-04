// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// void solve() {
//     int n;
//     scanf("%d", &n);
//     vector<int> s(n);
//     for(int i = 0; i < n; i++) {
//         scanf("%d", &s[i]);
//     }
    
//     // For each position, find max of all other elements
//     for(int i = 0; i < n; i++) {
//         int max_other = 0;
//         // Check all elements except the current position
//         for(int j = 0; j < n; j++) {
//             if(j != i) {
//                 max_other = max(max_other, s[j]);
//             }
//         }
//         printf("%d ", s[i] - max_other);
//     }
//     printf("\n");
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     scanf("%d", &t);
//     while(t--) {
//         solve();
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> s(n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    
    // Find overall maximum and second maximum
    int max1 = 0, max2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] > max1) {
            max2 = max1;
            max1 = s[i];
        } else if(s[i] > max2) {
            max2 = s[i];
        }
    }
    
    // Print results
    for(int i = 0; i < n; i++) {
        if(s[i] == max1) {
            printf("%d ", s[i] - max2);
        } else {
            printf("%d ", s[i] - max1);
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
}
