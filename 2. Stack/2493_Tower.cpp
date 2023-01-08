/*
백준 2493번
https://www.acmicpc.net/problem/2493
*/

//algorithm: Stack

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n;
stack<pair<int, int>> s;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        while (!s.empty()) {
            if (s.top().second > temp) {
                cout << s.top().first << ' ';
                break;
            }
            s.pop();
        }
        if (s.empty()) {
            cout << "0 ";
        }
        s.push({ i, temp });
    }
    return 0;
}
