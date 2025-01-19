/*#include <iostream>
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

    return 0;
}*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comparator(int a, int b) {
    // Порівняння за зменшенням
    return a > b;
}

void mergeSort(int array[], int size) {
    if (size <= 1) return; // базовий випадок

    int middle = size / 2;
    int leftArray[middle];
    int rightArray[size - middle];

    // Заповнення лівого та правого масивів
    for (int i = 0; i < middle; i++) {
        leftArray[i] = array[i];
    }
    for (int i = middle; i < size; i++) {
        rightArray[i - middle] = array[i];
    }

    mergeSort(leftArray, middle);
    mergeSort(rightArray, size - middle);
    merge(leftArray, rightArray, array, middle, size - middle);
}

void merge(int leftArray[], int rightArray[], int array[], int leftSize, int rightSize) {
    int i = 0, l = 0, r = 0; // індекси для заповнення масиву

    // Злиття масивів за компаратором
    while (l < leftSize && r < rightSize) {
        if (comparator(leftArray[l], rightArray[r])) {
            array[i] = leftArray[l];
            l++;
        } else {
            array[i] = rightArray[r];
            r++;
        }
        i++;
    }

    // Додавання залишків з лівого масиву
    while (l < leftSize) {
        array[i] = leftArray[l];
        l++;
        i++;
    }

    // Додавання залишків з правого масиву
    while (r < rightSize) {
        array[i] = rightArray[r];
        r++;
        i++;
    }
}

int mas[100000];
int main() {
    int N;
    cin >> N;
    int mas[N]; 
    in_mas(mas, N);
    mergeSort(array, N);
    out_mas(mas, N);
    return 0;
}