#include <iostream>
using namespace std;
int arr[100000];
int result1[100000];
int result2[100000];

void add(int result[], int mid, int l) {
    int p1 = mid - 1, p2 = l - 1;
    int wp = l - 1;
    int carry = 0;
    while (p1 >= 0 || p2 >= mid) {
        if (p1 >= 0 && p2 >= mid) {
            int temp = arr[p1--] + arr[p2--] + carry;
            carry = temp / 10;
            temp %= 10;
            result[wp--] = temp;
        }
        else if (p1 < 0) {
            int temp = arr[p2--] + carry;
            carry = temp / 10;
            temp %= 10;
            result[wp--] = temp;
        }
        else if (p2 < mid) {
            int temp = arr[p1--] + carry;
            carry = temp / 10;
            temp %= 10;
            result[wp--] = temp;
        }
    }
    result[wp] = carry;
}

int cmp(const int arr1[], const int arr2[], int l) {
    for (int i = 0; i < l; i++) {
        if (arr1[i] < arr2[i]) return 1;
        if (arr1[i] > arr2[i]) return -1;
    }
    return 0;
}

int main() {
    int l;
    cin >> l;
    getchar();
    for (int i = 0; i < l; i++) {
        char c = getchar();
        arr[i] = c - '0';
    }
    int mid_l, mid_r;
    if (l & 1) {
        mid_l = l / 2;
        mid_r = l / 2 + 1;
    }
    else {
        mid_l = mid_r = l / 2;
    }
    while (mid_l >= 0 && arr[mid_l] == 0) mid_l--;
    while (mid_r < l && arr[mid_r] == 0) mid_r++;
    add(result1, mid_l, l);
    if (mid_r < l) {
        add(result2, mid_r, l);
    }
    if (mid_r == l || cmp(result1, result2, l) >= 0) {
        int i = 0;
        while (result1[i] == 0) i++;
        for (; i < l; i++) {
            cout << result1[i];
        }
    }
    else {
        int i = 0;
        while (result2[i] == 0) i++;
        for (; i < l; i++) {
            cout << result2[i];
        }
    }
    return 0;
}
