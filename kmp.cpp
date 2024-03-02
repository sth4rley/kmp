#include <bits/stdc++.h>

using namespace std;

vector<int> init_backtrack_table(string pattern) {

    vector<int> table(pattern.size() + 1, -1);

    int i = 0, j = -1;

    while (i < pattern.size()) {
        while (j >= 0 and pattern[i] != pattern[j])
            j = table[j];
        table[++i] = ++j;
    }

    return table;
}

vector<int> match(string pattern, string text) {
    vector<int> occurrences, backtrack_table = init_backtrack_table(pattern);

    int i = 0, j = 0;

    while (i < text.size()) {
        while (j >= 0 and text[i] != pattern[j])
            j = backtrack_table[j];
        i++;
        j++;

        if (j == pattern.size()) {
            occurrences.push_back(i - j);
            j = backtrack_table[j];
        }
    }

    return occurrences;
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
