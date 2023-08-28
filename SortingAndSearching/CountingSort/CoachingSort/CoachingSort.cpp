#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

char arr[10000000];

int main()
{
    // условие: https://judge.openfmi.net/practice/get_problem_description?contest_id=175&problem_id=542

    int occurs[63] = { 0, };
    int size;

    scanf_s("%d", &size);
    scanf_s("%s", arr);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
            occurs[(arr[i] - '0') + 1]++;
        else if (arr[i] >= 'a' && arr[i] <= 'z')
            occurs[(arr[i] - 'a') + 11]++;
        else if (arr[i] >= 'A' && arr[i] <= 'Z')
            occurs[(arr[i] - 'A') + 37]++;
    }

    int ind = 0;
    for (int i = 0; i < 63; i++)
    {
        while (occurs[i] > 0)
        {
            if (i >= 1 && i <= 10)
                arr[ind++] = i + '0' - 1;
            else if (i >= 11 && i <= 36)
                arr[ind++] = i + 'a' - 11;
            else if (i >= 37 && i <= 62)
                arr[ind++] = i + 'A' - 37;

            occurs[i]--;
        }
    }

    printf("%s\n", arr);

    return 0;
}