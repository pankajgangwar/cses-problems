#include <string>
#include <bits/stdc++.h>
using namespace std;

//https://en.wikipedia.org/wiki/Lexicographically_minimal_string_rotation
int leastRotation(string S) {
    string concatenated = S + S;
    vector<int> f(concatenated.size(), -1);
    int k = 0;
    
    for (int j = 1; j < concatenated.size(); ++j) {
        char sj = concatenated[j];
        int i = f[j - k - 1];
        while (i != -1 && sj != concatenated[k + i + 1]) {
            if (sj < concatenated[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if (sj != concatenated[k + i + 1]) {
            if (sj < concatenated[k]) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    return k;
}

int main(){
    string s;
    cin >> s;

    int pos = leastRotation(s);
    int n = s.size();
    cout  << s.substr(pos) + s.substr(0, pos) << endl;
}
