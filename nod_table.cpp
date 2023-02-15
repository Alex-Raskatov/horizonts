#include <iostream>

int nod(int a, int b) {

    //Считает НОД двух подаваемых чисел
    
    if (b > a) {
        auto tmp = a;
        a = b;
        b = tmp;
    }

    int r;

    while (a % b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return b;
}

int size(int a) {

    //возращает разрядость числа

    int size = 1;

    while (a >= 10){
        a /= 10;
        ++size;
    }
    
    return size;
}

int degree(int a, int b){
    //возводит a в степень b
    int result = 1;
    for (int i = 0; i < b; ++i) result *= a;
    return result;
}

void print_without_null(int max_size, int a) {

    //вывод в консоль числа с пробелами таким образом, чтобы  оно занимало нужноеколичество символов 

    for (int i = 0; i < max_size - size(a); ++i){
        std::cout << ' ';
    }

    for (int i = 1; i <= size(a); ++i){
        std::cout << (a / degree(10, size(a) - i)) % 10;
    }

    std::cout << ' ';
}

void print_size_space(int size) {
    //выводит в консоль нужное количество пробелов
    for (int i = 0; i < size; ++i) std::cout << ' ';
}

int main() {

    int n, m;

    std::cout << "Данная программа выводит НОД всех числел, меньших n и m, вводимых пользователем, в виде таблицы.\nВведите n и m: ";

    std::cin >> n >> m;

    ++n;
    ++m;

    const int N = n, M = m;

    int arr[N][M];

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            arr[i][j] = nod(i,j);
        }
    }

    int max = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (arr[i][j] > max) max = arr[i][j];
        }
    }

    int max_size = size(max);

   /* const int N_size = size*(n+1), M_size = size*(m+1), Size = size;

    int arr_out[N][M][Size];

    for (int i = 1; i < n; ++i){
        for (int j = 1; j < m; ++j){
            for (int k = size-1; k >= 0; --k){
                if (arr[i][j] != 0){
                    arr_out[i][j][k] = arr[i][j] % 10;
                    arr[i][j] /= 10;
                }
                else {
                    arr_out[i][j][k] = 0;
                }
            }
        }
    }

    
    for (int i = 1; i < n; ++i){
        for (int j = 1; j < m; ++j){
            for (int k = 0; k < size; ++k){
                if (arr_out[i][j][k] != 0) std::cout << arr_out[i][j][k];
                else std::cout << ' ';
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    */

    print_size_space(max_size);
    std::cout << "  ";
    for (int i = 1; i < m; ++i) print_without_null(max_size, i);
    std::cout << '\n';
    std::cout << "  ";
    print_size_space(max_size);
    for (int i = 0; i < (max_size+1)*m - max_size - 2; ++i) std::cout << '-';
    std::cout << '\n';


    for (int i = 1; i < n; ++i) {
        print_without_null(max_size, i);
        std::cout << '|';
        for (int j = 1; j < m; ++j) {
            print_without_null(max_size, arr[i][j]);
        }
        std::cout << '\n';
    }

    return 0;
}