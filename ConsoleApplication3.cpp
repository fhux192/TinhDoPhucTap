#include <iostream>
#include <chrono> //thư viện chrono để đo thời gian chạy của hàm

using namespace std;

// Hàm tính tổng các phần tử trong mảng
int sum(int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    return s;
}

/*int giaithua(int n) {
    if (n <= 2) 
        return n;
    else return n * giaithua(n - 1);
} test */

int main()
{
    // Tạo mảng có 100000 phần tử
    //const int n = 15; test
    const int m = 100000;
    int arr[m];

    for (int i = 0; i < m; i++)
    {
        arr[i] = i;
    }   

    // Đo thời gian chạy hàm sum()
    auto start = chrono::steady_clock::now();
    int s = sum(arr,m);
    //int s = giaithua(n); test
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // In ra tổng và thời gian chạy
    cout << "O(n):" << s << endl;
    cout << "Thoi gian: " << duration << " us" << endl;

    return 0;
}

