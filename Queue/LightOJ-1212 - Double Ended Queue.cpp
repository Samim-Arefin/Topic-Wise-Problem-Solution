#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++)
    {
        cout << "Case " << i << ":" << endl;
        deque<int> de;
        string str;
        int num, limit, t;
        cin >> limit >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> str;
            if (str == "pushLeft" || str == "pushRight")
            {
                cin >> t;
                if (de.size() == limit)
                {
                    cout << "The queue is full" << endl;
                }
                else
                {

                    if (str == "pushLeft")
                    {
                        de.push_front(t);
                        cout << "Pushed in left: " << de.front() << endl;
                    }
                    else if (str == "pushRight")
                    {
                        de.push_back(t);
                        cout << "Pushed in right: " << de.back() << endl;
                    }
                }
            }
            else if (str == "popLeft" || str == "popRight")
            {

                if (de.size() == 0)
                {
                    cout << "The queue is empty" << endl;
                }
                else
                {
                    if (str == "popRight")
                    {
                        cout << "Popped from right: " << de.back() << endl;
                        de.pop_back();
                    }
                    else if (str == "popLeft")
                    {
                        cout << "Popped from left: " << de.front() << endl;
                        de.pop_front();
                    }
                }
            }
        }
    }
}
