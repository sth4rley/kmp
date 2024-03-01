#include <bits/stdc++.h>

using namespace std;

class KMP {
    string P;      // Padrao
    vector<int> b; // tabela de back-tracking
    int m; 

    public:
    KMP(const char *_P) : P(_P) {
        m = P.size();
        b.assign(m+1, -1);
        for (int i = 0, j=-1; i<m;) {
           while(j>=0  and P[i] != P[j]) j = b[j];
           b[++i] = ++j;
        }
    }

    vector<int> match (const char * T) {
        vector<int> ans;

        for(int i = 0, j = 0, n = strlen(T); i<n;) {
            while( j >= 0 and T[i] != P[j]) j = b[j];
            i++;
            j++;

            if (j==m) {
                ans.push_back(i-j);
                j = b[j];
            }
        }

        return ans;
    }

};

int main () {
    KMP kmp("banana");

  const char *text = "banananasadhuashduashduasbananahduahdjkahdkuhbanana";

    vector<int> occurrences = kmp.match(text);

    cout << "Qnt Ocorrencias: " << occurrences.size() << endl;

    for(auto &x: occurrences) {
        cout << x << " ";
    }
    cout << endl;
}


