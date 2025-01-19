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

/*
void sort_mas(int mas[], int N){
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            if (mas[i]>mas[j]) swap(mas[i], mas[j]);
        }
    }
}*/

//sort(first, last, comp);

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

int binary_search(int mas[], int start, int end, int num)
{
    if (start>end) return -1;//немає

    int middle = floor((start+end)/2);
    if (mas[middle] == num) return middle;

    if (num < mas[middle]){
        return binary_search(mas, start, middle-1, num);
    }
    
    if (num > mas[middle]){
        return binary_search(mas, middle+1, end, num);
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