/*
 * created by Danil Kireev, PFUR NFI-201, 4.12.18, 09:00
 */
#include <iostream>
#include <ctime>

using namespace std;

/*
 *  №5
 *  Дан массив с числами integer.
 *  Вам нужно написать функцию, которая на входе получает исходны массив,
 *  а на выходе вернёт массив, в котором каждое значение получено путём произведения всех
 *  значений исходного массива  с отличным от текущего инлексом
 */

void apply_rule(long long int *a, long long int n);

int main() {
    srand(time(nullptr));
    int  choice;
    long long int n, *a, tmp_int;
    cout << "Программа обрабатывает масив по указаному правилу: каждому зачению массива присваивается " <<
            "произведение значений с отличным от него индексом" << endl;
    cout << "введите размер массива: ";
    cin >> n;
    while(n <= 0) {
        cout << "введите размер списка не меньше 1: ";
        cin >> n;
    }
    a = new long long int[n];
    cout << "Выберите тип ввода:\n- *0:заполнение случайными числами*\n-  1:заполнение вручную" << endl;
    cin >> choice;
    switch(choice) {
        case 0: {
            for (int i = 0; i < n; ++i) {
                tmp_int = rand()%100;
                cout << "значение " << i+1 << "-го элемента: " << tmp_int << endl;
                a[i] = tmp_int;
            }
            break;
        }
        case 1: {
            for (int i = 0; i < n; ++i) {
                cout << "значение " << i+1 << "-го элемента: ";
                cin >> a[i];
            }
            break;
        }
        default:break;
    }
    cout << "полученый список: " << endl;
    for (long long int i = 0; i < n; ++i) cout << "значение " << i+1 << "-го элемента: " << a[i] << endl;
    apply_rule(a, n);
    cout << "обработанный список: " << endl;
    for (long long int i = 0; i < n; ++i) cout << "значение " << i+1 << "-го элемента: " << a[i] << endl;
    return 0;
}

void apply_rule(long long int *a, long long int n) {
    long long int m=1, mm=1, *b;
    b = new long long int[n];
    for (int i = 0; i < n; ++i) m *= a[i];
    for (int i = 0; i < n; ++i) b[i] = a[i];
    for (int i = 0; i < n; ++i) {
        if(a[i] != 0) a[i] = m / a[i];
        else {
            mm = 1;
            for (int j = 0; j < i; ++j) mm *= b[j];
            for (int j = i+1; j < n; ++j) mm *= b[j];
            a[i] = mm;
        }
    }
    
}