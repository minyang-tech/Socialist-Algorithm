#include <bits/stdc++.h>
using namespace std;

const int INSERTION_THRESHOLD = 32;
const int BUCKET_LIMIT = 256;

// insertion sort
void insertion_sort(vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// counting sort
void counting_sort(vector<int>& a, int mn, int mx) {
    vector<int> freq(mx - mn + 1, 0);
    for (int x : a) freq[x - mn]++;

    int idx = 0;
    for (int i = 0; i < (int)freq.size(); i++) {
        while (freq[i]--) {
            a[idx++] = i + mn;
        }
    }
}

void socialist_sort(vector<int>& a) {
    int n = a.size();
    if (n <= 1) return;

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    counting sort
    if ((long long)mx - mn <= n) {
        counting_sort(a, mn, mx);
        return;
    }

    if (n <= INSERTION_THRESHOLD) {
        insertion_sort(a);
        return;
    }

    vector<int> sample;
    int step = max(1, n / 100);
    for (int i = 0; i < n; i += step) {
        sample.push_back(a[i]);
    }
    sort(sample.begin(), sample.end());

    int bucket_count = min(BUCKET_LIMIT, (int)sample.size());
    vector<int> boundaries;

    for (int i = 1; i < bucket_count; i++) {
        boundaries.push_back(sample[i * sample.size() / bucket_count]);
    }

    vector<vector<int>> buckets(boundaries.size() + 1);

    for (int x : a) {
        int idx = upper_bound(boundaries.begin(), boundaries.end(), x) - boundaries.begin();
        buckets[idx].push_back(x);
    }

    int pos = 0;
    for (auto& b : buckets) {
        if (b.empty()) continue;

        if ((int)b.size() > INSERTION_THRESHOLD) {
            socialist_sort(b);
        } else {
            insertion_sort(b);
        }

        for (int x : b) {
            a[pos++] = x;
        }
    }
}