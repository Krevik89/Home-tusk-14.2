#include <iostream>
#include <conio.h>


using namespace std;

    //задание 1
    
//Функция распределения динамической памяти.
void func(int*arr)
{
    int* ar = new int[3];
    int* p = new int;
    delete p;
    delete[]ar;
}

//Функция инициализации динамического массива.
void Inicial(int* arr) {
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i * 3;
    } 
}

//Функция печати динамического массива.
void print(int* arr) {
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}

//Функция удаления динамического массива.
void deletearr(int* arr) {
    delete[]arr;
}

//Функция добавления элемента в конец массива.
void inputLast(int*arr,int n) {
    for (int i = 0; i < 10; i++)
    {
        arr[10 - 1] = n;
    }
}

//Функция вставки элемента по указанному индексу.
void inputIndex(int* arr, int n, int el) {
    for (int i = 0; i < 10; i++)
    {
        arr[n] = el;
    }
}

//Функция удаления элемента по указанному индексу.
void delIndex(int* arr,int n) {
    int size = 0;
    int* arr2 = new int[size];
    if (n > 10) exit(0);
    else {
        for (int i = 0, j = 0; i < 10; i++, j++) {
            if (i != n) {
                size++;
                arr2[j] = arr[i];
            }
            else
                j--;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << " ";
    }
}

//задание 2
/*Написать функцию, которая получает указатель на динамический массив и его размер. Функция
должна удалить из массива все простые числа и вернуть
указатель на новый динамический массив.*/
int* selectPrimeNumbers(int* startArray, int arraySize)
{
    int* bufferArray = new int[arraySize];
    int newSize = 0;
    int divisorsCount = 0;

    for (int i = 0; i < arraySize; i++){
        divisorsCount = 0;
        for (int j = 1; j < startArray[i]; j++){
        if (startArray[i] % j == 0) { divisorsCount++; }
        }
        if (divisorsCount <= 1){
            bufferArray[newSize] = startArray[i];
            newSize++;
        }
    }
    int* resultArray = new int[newSize];
    cout << "Result array: ";
    for (int i = 0; i < newSize; i++){
        resultArray[i] = bufferArray[i];
        cout << resultArray[i] << " ";
    }
    cout << endl;
    delete[] bufferArray;
    return resultArray;
}

 //Задание 3
/*Написать функцию, которая получает указатель
на статический массив и его размер. Функция распределяет положительные, отрицательные и нулевые элементы
в отдельные динамические массивы.*/
void staticArr(int* px,int size) {
    for (int i = 0; i < size; i++)
    {
        px[i] = rand() % 10 - rand() % 10;
    }
    for (int i = 0; i < size; i++)
    {
        cout<< px[i] << " ";
    }
    cout << endl;
    int Spoz = 0;
    int Sneg = 0;
    int S = 0;
    int* pozitiv = new int[Spoz];
    int* neg = new int[Sneg];
    int* nul = new int[S];
    for (int i = 0,j=0,k=0,l=0; i < size; i++)
    {
        if (px[i] < 0) {
            Sneg++;
            neg[j] = px[i];
            j++;
        }
        else if (px[i] == 0) {
            S++;
            nul[k] = px[i];
            k++;
        }
        else {
            Spoz++;
            pozitiv[l] = px[i];
            l++;
        }
            
    }
    cout << "Массив с положительными числами \n";
    for (int i = 0; i < Spoz; i++)
    {
        cout << pozitiv[i] << " ";
    }
    cout << endl;
    cout << "Массив с отрицательными числами \n";
    for (int i = 0; i < Sneg; i++)
    {
        cout << neg[i] << " ";
    }
    cout << endl;
    cout << "Массив с нулями \n";
    for (int i = 0; i < S; i++)
    {
        cout << nul[i] << " ";
    }

}


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    const int size=10;
    int arr[size];
    int* px = arr;
   
    int arraySize = 20;
    int* startArray = new int[arraySize];
    int* newArray;
    for (int i = 0; i < arraySize; i++){
        startArray[i] = i + 1;
    }
    cout << "Start massiv: ";
    for (int i = 0; i < arraySize; i++){
        cout << startArray[i] << " ";
    }
    cout << endl;
    
    newArray = selectPrimeNumbers(startArray, arraySize);
    delete[] startArray;
    delete[] newArray;
   
}

