#include <iostream>
using namespace std;
const int MaxN = 1e6 + 500;
long long int arr[MaxN], Source[MaxN];
int main() {
    ios::sync_with_stdio(false);
    int i, n, k, front = 0, rear = -1;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        if (front <= rear && i - k + 1 > Source[front]) ++front;    // 如果滑动窗口滑出了当前的最小值。
        while (front <= rear && arr[Source[rear]] > arr[i]) --rear; // 从队尾删除。
        Source[++rear] = i;
        if (i > k - 2) cout << arr[Source[front]] << " ";
    }
    front = 0, rear = -1;
    cout << '\n';
    for (int i = 0; i < n; i++) {
        if (front <= rear && i - k + 1 > Source[front]) front++;
        while (front <= rear && arr[Source[rear]] < arr[i]) rear--;
        Source[++rear] = i;
        if (i > k - 2) cout << arr[Source[front]] << " ";
    }
    return 0;
}