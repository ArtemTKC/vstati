#include <iostream>
using namespace std;

void in_2dmas(int mas[][100], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> mas[i][j];
        }
    }
}

void out_2dmas(int mas[][100], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << mas[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    int row, col;
    cin >> row >> col;
    int mas[100][100]; 
    in_2dmas(mas, row, col);
    //swap(mas[0], mas[1]);
    out_2dmas(mas, row, col);
    return 0;
}