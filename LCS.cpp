#include <bits/stdc++.h>
using namespace std;

int main()
{

    string name1 = "president";

    string name2 = "providence";

    int m = name1.length();
    int n = name2.length();

    int container[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            container[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (name1[i - 1] == name2[j - 1])
            {
                container[i][j] = container[i - 1][j - 1] + 1;
            }
            else
            {
                container[i][j] = max(container[i - 1][j], container[i][j - 1]);
            }
        }
    }

    int length = container[m][n];

    cout << "the length of the string is " << length << endl;

    string lcs="";
    int i = m;
    int j = n;
    while (i > 0 && j > 0)
    {
        if(name1[i-1]==name2[j-1])
        {
            lcs = name1[i-1]+lcs;
            i--;
            j--;
        }
        else if(container[i-1][j]>container[i][j-1])
        {
            i--;
        }
        else{
            j--;
        }
    }

    cout<<"The string is "<<lcs<<endl;

    return 0;
}