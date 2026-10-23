#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string Merge(string nums[], int len)
{
    string Check = "";

    for (int i = 0; i < len; i++)
    {
        Check += nums[i];
    }

    return Check;
}

int RandomNumer(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

string Mixer(string nums, int len)
{
    for (int i = 0; i < len; i++)
    {
        int randomIndex = RandomNumer(0, len - 1);
        swap(nums[i], nums[randomIndex]);
    }

    return nums;
}

void PrintArray(string arr[], int TailOfArray)
{
    for (int i = 0; i < TailOfArray; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    srand(time(NULL));

    string nums[100] = {"01", "100", "1010", "100001", "10011001"};

    int len = 5;

    string merged = Merge(nums, len);
    cout << "Merged: " << merged << endl;
    cout << "\n===========\n";
    string mixed = Mixer(merged, merged.length());
    cout << "\n===========\n";
    cout << "Mixed: " << mixed << endl;

    PrintArray(nums, len);

    return 0;
}