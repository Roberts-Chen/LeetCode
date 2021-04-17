#include <bits/stdc++.h>

using namespace std;

/**
 * 判断某个数是否为素数，这里用到了三种算法，枚举法，挨氏筛，线性筛
 *
 */

/**
 * 枚举法判断素数，如果y是x的因数，那么x/y也是x的因数，那么我们每次选择校验
 * y和x/y两个数中较小的那个，则不难发现较小数一定落在[2, 根号x]的区间内
 * @param x
 * @return 某个数是否为素数
 */
bool isPrime1(int x) {
    if (x > 2 && x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}


class Solution1 {
public:
    /**
     * 挨氏筛法判断素数
     * @param x
     * @return
     */
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ++count;
                if ((long long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return count;
    }
};

class Solution2 {
public:
    /**
     * 线性筛
     * @param n
     * @return
     */
    int countPrimes(int n) {
        vector<int> primes;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
        return (int) primes.size();
    }
};


int main() {
    Solution2 s;
    cout << s.countPrimes(100) << endl;
    return 0;
}
