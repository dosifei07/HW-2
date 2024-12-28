#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int call_count = 0;

void TestFunction() {
    call_count++;

    if (call_count <= 3) {
        cout << "Виклик №" << call_count << ": Функція виконана успішно." << endl;
    }
    else {
        cout << "Перевищено ліміт викликів!" << endl;
    }
}



void ResetCallCounter() {
    call_count = 0;
    cout << "Лічильник скинуто." << endl;
}




int FindMaxInArray(int arr[], int size) {
    int max_value = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    return max_value;
}



int FindMaxIn2DArray(int arr[3][10], int rows, int cols) {
    int max_value = arr[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max_value) {
                max_value = arr[i][j];
            }
        }
    }

    return max_value;
}



int FindMax(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}



int FindMax(int a, int b, int c) {
    int max_value = a;

    if (b > max_value)
        max_value = b;

    if (c > max_value)
        max_value = c;

    return max_value;
}



int FindMinSequence(int arr[], int size, int sequence_length) {
    int min_sum = 1000000; 
    int min_position = 0;
    for (int i = 0; i <= size - sequence_length; i++) {
        int current_sum = 0;

        for (int j = 0; j < sequence_length; j++) {
            current_sum += arr[i + j];
        }
        if (current_sum < min_sum) {
            min_sum = current_sum;
            min_position = i;
        }
    }
    return min_position;
}


void PrintArray(int arr[], int size) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i * 10 + j] << "\t";
        }
        cout << endl;
    }
}


void CombineArrays(int* arr1, int size1, int* arr2, int size2, int* result) {
    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }
}


int main() {
    cout << "Тест функції з лімітом 3:" << endl;


    TestFunction();
    TestFunction();
    TestFunction();
    TestFunction();
    ResetCallCounter();


    int numbers[] = { 5, 2, 9, 1, 7 };
    int max_number = FindMaxInArray(numbers, 5);
    cout << "Максимальне число в 1Д масиві: " << max_number << endl;

    int array_2d[3][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30}
    };

    int max_2d = FindMaxIn2DArray(array_2d, 3, 10);
    cout << "Максимальне число в 2Д масиві: " << max_2d << endl;
    cout << "Максимум (2 числа): " << FindMax(5, 10) << endl;
    cout << "Максимум (3 числа): " << FindMax(5, 10, 3) << endl;
    int random_array[100];
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        random_array[i] = rand() % 100;
    }
    cout << "Масив 10х10:" << endl;
    PrintArray(random_array, 100);
    int min_sequence_pos = FindMinSequence(random_array, 100, 10);
    cout << "Позиція послідовності з мінімальною сумою: " << min_sequence_pos << endl;
    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 4, 5, 6 };
    int combined_array[6];

    CombineArrays(arr1, 3, arr2, 3, combined_array);

    cout << "Об'єднаний масив: ";
    for (int i = 0; i < 6; i++) {
        cout << combined_array[i] << " ";
    }
    cout << endl;

    return 0;
}