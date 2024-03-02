#include <bits/stdc++.h>

using namespace std;

vector<int> ibtt(string p) {
    int n = p.size();
    vector<int> t(n + 1, -1);
    int i = 0, j = -1;
    while (i < n) {
        while (j >= 0 and p[i] != p[j]) j = t[j];
        t[++i] = ++j;
    }
    return t;
}

vector<int> match(string p, string t) {
    vector<int> oc, btt = ibtt(p);
    int i = 0, j = 0;
    while (i < t.size()) {
        while (j >= 0 and t[i] != p[j]) j = btt[j];
        i++; j++;
        if (j == p.size()) oc.push_back(i - j), j = btt[j];
    }
    return oc;
}

int main() {

    string text = "banananasadhuashduashduasbananahduahdjkahdkuhbanana";

    vector<int> occurrences = match("banana", text);

    cout << "Qnt Ocorrencias: " << occurrences.size() << endl;

    for (auto &x : occurrences) {
        cout << x << " ";
    }
    cout << endl;
}
