#include <iostream>

using namespace std;

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    while (n != 1 && n != 4) {
        n = sumOfSquares(n);
    }
    return n == 1;
}

int main() {
    for (int i = 1; i <= 100; ++i) {
        if (isHappy(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
