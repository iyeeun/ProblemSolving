#include <string>
#include <vector>
// #include <iostream>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    for (int i = 0; i < new_id.length(); i++)
    {
        char c = new_id[i];
        if (c >= 'A' && c <= 'Z')
        {
            new_id[i] = 'a' + (c - 'A');
        }
    }
    for (int i = 0; i < new_id.length(); i++)
    {
        char c = new_id[i];
        if (!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '-') || (c == '_') || (c == '.')))
        {
            new_id.replace(i, 1, "");
            i--;
        }
    }

    for (int i = 0; i < new_id.length(); i++)
    {
        char c = new_id[i];
        if (i != new_id.length() - 1 && (c == '.' && new_id[i + 1] == '.'))
        {
            new_id.replace(i, 1, "");
            i--;
        }
    }

    if (new_id[0] == '.')
    {
        new_id.replace(0, 1, "");
    }
    if (new_id[new_id.length() - 1] == '.')
    {
        new_id.replace(new_id.length() - 1, 1, "");
    }

    if (new_id.empty())
    {
        new_id = 'a';
    }

    if (new_id.length() >= 16)
    {
        new_id.replace(15, new_id.length() - 15, "");
        if (new_id[14] == '.')
            new_id.replace(14, 1, "");
    }

    if (new_id.length() <= 2)
    {
        while (new_id.length() < 3)
        {
            new_id += new_id[new_id.length() - 1];
        }
    }

    answer = new_id;

    return answer;
}