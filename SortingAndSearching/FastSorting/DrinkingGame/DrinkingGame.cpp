#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // условие: https://judge.openfmi.net/practice/get_problem_description?contest_id=175&problem_id=537
    
    priority_queue<int> pq;

    char cmd;
    do
    {
        cin >> cmd;
        if (cmd == 'A')
        {
            int num;
            cin >> num;
            pq.push(num);
        }
        else if (cmd == 'R')
        {
            if (pq.size() == 0)
                cout << "Not available\n";
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else if (cmd == 'L')
        {
            pq.size() == 0 ? cout << "Not available\n" : cout << pq.top() << endl;
        }
    } while (cmd != 'Q');

    return 0;
}