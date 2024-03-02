#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KMP {
    string Pattern;        // padrão
    vector<int> backtrack; // tabela de back-tracking

  public:
    // construtor
    KMP(const string &pattern) : Pattern(pattern) {
        backtrack.assign(Pattern.size() + 1, -1);

        int i = 0;
        int j = -1;

        while (i < Pattern.size()) {
            while (j >= 0 && Pattern[i] != Pattern[j])
                j = backtrack[j];
            backtrack[++i] = ++j;
        }
    }

    // método responsável por encontrar todas as ocorrências
    // de um padrão em uma string
    vector<int> match(const string &text) {
        vector<int> ans;

        int i = 0;
        int j = 0;
        int n = text.size();

        // percorre a string
        while (i < n) {
            while (j >= 0 && text[i] != Pattern[j])
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

    string text = "banananasadhuashduashduasbananahduahdjkahdkuhbanana";

    vector<int> occurrences = kmp.match(text);

    cout << "Quantidade de Ocorrências: " << occurrences.size() << endl;

    for (auto &x : occurrences) {
        cout << x << " ";
    }
    cout << endl;
}
