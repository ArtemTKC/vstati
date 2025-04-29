#include <iostream>
#include <string>
using namespace std;

const int Nmax=10000;

struct long_num
{
    char sign;
    int len; 
    int num[Nmax+1];
};

int len_long(long_num& num1) {
    int len=0, blank_cells=0; 
    num1.num[Nmax]= -1; //в числа цифра не може == -1

    while (num1.num[blank_cells]==0) blank_cells++;
    if (blank_cells==Nmax) len=1;//це означає що num1==0
    else len=Nmax-blank_cells;
    return len;
}

void read_long(long_num& num1) {
    int i;
    string txt;
    getline(cin, txt);
    for (int i = 0; i <= Nmax; i++) num1.num[i] = 0; //заповнюємо нулями

    if(txt[0]=='-'){
        num1.sign='-';
        txt.erase(0, 1);
    }
    else {
        if(txt[0]=='+') txt.erase(0, 1);
        num1.sign='+';
    }

    num1.len=txt.length();
    for(int i=0; i<num1.len; i++){
        num1.num[Nmax-num1.len+i]=txt[i]-'0';
    }
}

void out_long(long_num& res) {
    int i, blank_cells=0;
    if(res.sign == '-'){
        cout << '-';
    }

    for (int i = Nmax - res.len; i < Nmax; i++) {
        cout << res.num[i];
    }
    cout << '\n';
}

int long_comp_abs(long_num& num1, long_num& num2) {
    if (num1.len > num2.len) return 1;
    if (num1.len < num2.len) return -1;
    for (int i = Nmax - num1.len; i < Nmax; i++) {
        if (num1.num[i] > num2.num[i]) return 1;
        if (num1.num[i] < num2.num[i]) return -1;
    }
    return 0;
}

int long_comp(long_num& num1, long_num& num2) {
    int i=0;
    if((num1.sign=='+') and (num2.sign=='-'))return 1;
    if((num1.sign=='-') and (num2.sign=='+'))return -1;

    //якщо функція дійшла до цього моменту це означає що знаки однакові
    num1.num[Nmax]= -1; //це необхідно аби термінатори точно були різні
    num2.num[Nmax]= -2;

    while (num1.num[i]==num2.num[i]) i++;
    if(i==Nmax) return 0; //числа рівні

    if(num1.sign=='+'){
        if(num1.num[i]>num2.num[i]) return 1; //num1>num2
        else return -1; //num1<num2
    }
    else{
        if(num1.num[i]>num2.num[i]) return -1; //num1<num2
        else return 1; //num1>num2
    }
}

long_num long_sum_abs(long_num& num1, long_num& num2){
    int i=0, blank_cells=0, sum;
    long_num res={};
    res.sign='+';

    while((num1.num[blank_cells]==0) and (num2.num[blank_cells]==0)) blank_cells++;

    for(int i=blank_cells; i<Nmax; i++){
        sum=num1.num[i]+num2.num[i];
        if(sum>=10){
            res.num[i]=sum-10;
            res.num[i-1]++;
        }
        else res.num[i]=sum;
    }

    res.len=len_long(res);
    return res;
}

long_num long_subtraction_abs(long_num& num1, long_num& num2) {
    long_num res = {};
    res.sign = '+';
    int cmp = long_comp_abs(num1, num2), temp=0;

    long_num a = num1;
    long_num b = num2;

    if (cmp == 0) {
        res.num[Nmax - 1] = 0;
        res.len = 1;
        return res;
    }

    if (cmp == -1) {
        a = num2;
        b = num1;
        res.sign = '-';
    }

    int borrow = 0;
    for (int i = Nmax - 1; i >= 0; i--) {
        temp = a.num[i] - b.num[i] - borrow;
        if (temp < 0) {
            temp += 10;
            borrow = 1;
        } 
        else {
            borrow = 0;
        }
        res.num[i] = temp;
    }

    res.len = len_long(res); 
    return res;
}

//треба множення


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long_num num1 = {};
    long_num num2 = {};
    long_num res_12 = {};
    read_long(num1);
    read_long(num2);

    //cout << long_comp(num1, num2) << '\n';
    res_12=long_sum_abs(num1, num2);
    out_long(res_12);
    return 0;
}