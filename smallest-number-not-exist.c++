#include <iostream>
using namespace std;

int ReadNumber(string message)
{
    int N;
    cout << message << endl;
    cin >> N;
    return N;
}

int CheckSmalles(int nums[], int len)
{
    int min = nums[0];
    int i = 1;

    while (i < len)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }
        i++;
    }
    return min;
}

int main()
{
    int nums[100] = {1, 2, 3, 4, 5, 77, 9, -2, 22, 3, 0, 99, 30, 0, -4, 6, 6, 2, 10, -100};
    int length = 20;

    int min = CheckSmalles(nums, length);

    printf("the number smalles from all the numbers in nums array is: %d\n", min - 1);

    return 0;
}