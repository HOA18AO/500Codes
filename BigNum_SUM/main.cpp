#include<bits/stdc++.h>
using namespace std;

string IntToString(int x)
{
    string s = "";
    while(x > 0)
    {
        s = char(x%10 + 48) + s;
        x /= 10;
    }
    return s;
}

int BigNumCompare(string a, string b) // 0: a==b; -1:a<b; 1:a>b
{
    if(a.size() != b.size())
        if(a.size() > b.size())
            return 1;
        else
            return -1;
    else
        for(int i=0 ; i<a.size(); i++)
        {
            if(a[i] > b[i])
                return 1;
            if(a[i] < b[i])
                return -1;
            if(i == a.size()-1)
                return 0;
        }
}

int StringToInt(string s)
{
    int x;

}

bool operator>(string a, string b)
{
    if(BigNumCompare(a,b) == 1)
        return true;
    else
        return false;
}

bool operator<(string a, string b)
{
    if(BigNumCompare(a,b) == -1)
        return true;
    else
        return false;
}

bool operator==(string a, string b)
{
    if(BigNumCompare(a,b) == 0)
        return true;
    else
        return false;
}

string SUM(string a, string b)
{
    while(a.size() < b.size())
        a = "0" + a;
    while(a.size() > b.size())
        b = "0" + b;
    int c = 0;
    int i = a.size()-1;
    string ans = "";
    while(i>=0)
    {
        c = int(a[i])-48 + int(b[i])-48 + c;
        ans = char(c%10 + 48) + ans;
        c /= 10;
        i--;
    }
    return ans;
}

string SUB(string a, string b)
{
    bool neg;
    string ans = "";
    if(a == b)
        return "0";
    else
        if(a > b)
            neg = false;
        else
        {
            neg = true;
            swap(a, b);
        }
    while(b.size() < a.size())
        b = "0" + b;
    //cout << a << " " << b << "\n";
    int i = a.size()-1;
    int c = 0;
    while(i >= 0)
    {
        c = (int(a[i])-48) - (int(b[i])-48) - c;
        //cout << c;
        if(c < 0)
        {
            ans = char(c+10 + 48) + ans;
            c = 1;
        }
        else
        {
            ans = char(c + 48) + ans;
            c = 0;
        }
        i--;
    }
    if(neg == true)
        ans = "-" + ans;
    return ans;
}

int main()
{
    string a,b;
    cin >> a >> b;
    cout << a << " - " << b << "\n";
    cout << SUB(a,b);
}
