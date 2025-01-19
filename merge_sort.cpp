#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void in_mas(int mas[], int N){
    for (int i = 0; i < N; i++){
        cin >> mas[i];
    }
}

void out_mas(int mas[], int N){
    for (int i = 0; i < N; i++){
        cout << mas[i] << " ";
    }
    cout << '\n';
}

void bubble_sort_mas(int mas[], int N)
{
    for (int i = 0; i < N-1; i++){
        for (int j = 0; j < N-i-1; j++)
        {
            if (mas[j]>mas[j+1])
            {
                swap(mas[j], mas[j+1]);
            }
        }
    }
}

int main()
{
    int N, num=5;
    cin >> N;
    int mas[N]; 
    in_mas(mas, N);
    sort_mas(mas, N);
    out_mas(mas, N);

    //cout << binary_search(mas, 0, N-1, num);
    return 0;
}