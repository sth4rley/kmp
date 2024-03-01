#include <bits/stdc++.h>
#include <cstring>

using namespace std;

class KMP {
    string Pattern;        // padrao
    vector<int> backtrack; // tabela de back-tracking

  public:
    // construtor
    KMP(const char *_Pattern) : Pattern(_Pattern) {
        backtrack.assign(Pattern.size() + 1, -1);

        int i = 0;
        int j = -1;

        while (i < Pattern.size()) {
            while (j >= 0 and Pattern[i] != Pattern[j])
                j = backtrack[j];
            backtrack[++i] = ++j;
        }
    }

    // metodo responsavel por encontrar todas as ocorrencias
    // de um padrao em uma string
    vector<int> match(const char *T) {
        vector<int> ans;

        int i = 0;
        int j = 0;
        int n = strlen(T);

        // percorre a string
        while (i < n) {
            while (j >= 0 and T[i] != Pattern[j])
                j = backtrack[j];
            i++;
            j++;

            if (j == Pattern.size()) {
                ans.push_back(i - j);
                j = backtrack[j];
            }
        }

        return ans;
    }
};

int main() {
    KMP kmp("banana");

    const char *text = "banananasadhuashduashduasbananahduahdjkahdkuhbanana";

    vector<int> occurrences = kmp.match(text);

    cout << "Qnt Ocorrencias: " << occurrences.size() << endl;

    for (auto &x : occurrences) {
        cout << x << " ";
    }
    cout << endl;
}
