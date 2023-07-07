#include <bits/stdc++.h>

using namespace std;

pair<double, int> eval(const string &s, int idx)
{
    if (s[idx] == '(')
    {
        pair<double, int> probability = eval(s, idx + 1);
        pair<double, int> e1 = eval(s, probability.second);
        pair<double, int> e2 = eval(s, e1.second);
        return make_pair(probability.first * (e1.first + e2.first) + (1 - probability.first) * (e1.first - e2.first), e2.second + 1);
    }
    else if (s[idx] == ' ')
    {
        return eval(s, idx + 1);
    }
    else
    {
        int start_idx = idx;
        idx++;
        while (idx < s.size() && ((s[idx] >= '0' && s[idx] <= '9') || s[idx] == '.' || s[idx] == '-'))
        {
            idx++;
        }

        return make_pair(stod(s.substr(start_idx, idx - start_idx)), idx);
    }
}

int main(void)
{
    string input;

    while (getline(cin, input))
    {
        if (input == "()")
        {
            break;
        }
        printf("%.2f\n", eval(input, 0).first);
    }

    return 0;
}