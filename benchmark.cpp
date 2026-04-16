#include <bits/stdc++.h>
using namespace std;

// external sort function
void socialist_sort(vector<int>& a);

// measure execution time in microseconds
long long measure(function<void(vector<int>&)> sort_func, vector<int> arr) {
    auto start = chrono::high_resolution_clock::now();
    sort_func(arr);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

// check if array is sorted
bool is_sorted_correct(const vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i-1] > a[i]) return false;
    }
    return true;
}

// generate random data
vector<int> gen_random(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = rand();
    return a;
}

// generate sorted data
vector<int> gen_sorted(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;
    return a;
}

// generate reverse sorted data
vector<int> gen_reverse(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = n - i;
    return a;
}

// generate data with few unique values
vector<int> gen_few_unique(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = rand() % 10;
    return a;
}

// run benchmark for a dataset
void run_test(string name, vector<int> data) {
    cout << "==== " << name << " ====\n";

    auto t1 = measure([](vector<int> v){ sort(v.begin(), v.end()); }, data);
    auto t2 = measure([](vector<int> v){ socialist_sort(v); }, data);

    cout << "std::sort: " << t1 << " us\n";
    cout << "socialist_sort: " << t2 << " us\n";

    vector<int> check = data;
    socialist_sort(check);
    cout << "correct: " << (is_sorted_correct(check) ? "OK" : "FAIL") << "\n\n";
}

int main() {
    srand(time(NULL));

    int n = 100000;

    run_test("Random", gen_random(n));
    run_test("Sorted", gen_sorted(n));
    run_test("Reverse", gen_reverse(n));
    run_test("Few Unique", gen_few_unique(n));

    return 0;
}