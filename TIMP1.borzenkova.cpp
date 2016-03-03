
#include "stdlib.h"
#include "stdio.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int i = 0, m = 0, l = 0, z = 0, j = 0, d1 = 0, d2 = 0, q = 0;
    int *p1 = new int[1024];
    int *p2 = new int[1024];
    string rez1[1024];
    string rez2[1024];
    string str1[1024];
    string str2[1024];
    ifstream file1, file2;
    file1.open("f1.txt");
    file2.open("f2.txt");
    if ((!file1.is_open()) || (!file2.is_open()))
    {
        cout << "Ошибка открытия файла!" << endl;

        if (file1.is_open()) file1.close();
        if (file2.is_open()) file2.close();
        return 0;

    }
    while (getline(file1, str1[i])){
        if (!(str1[i].find("\n"))) str1[i] += "\n";
        i++;
    }
    while (getline(file2, str2[m])){
        m++;
        if (!(str2[m].find("\n"))) str2[m] += "\n";
    }
    for (j = 0; j < i; j++)                 // проверяем строчки на совпадающие 
    {
        for (z = 0; z < m; z++)
            if (str1[j] == str2[z]) l = 1;  // если они совпали, то контрольному значению приравниваем единицу 
        if (l != 1)                         // если не единица, значит строчки различны, тогда заполняем массив для вывода
        {
            rez1[d1] = str1[j];
            p1[d1] = j;                     // номер строки, в которой различны
            d1++;
        }
        l = 0;
    }

    for (j = 0; j < i; j++)                // аналогично для сравнения, относительно другой строки
    {
        for (z = 0; z < m; z++)
            if (str2[j] == str1[z]) l = 1;
        if (l != 1)
        {
            rez2[d2] = str2[j];
            p2[d2] = j;
            d2++;
        }
        l = 0;
    }

    cout << "file1:" << endl;              // вывод результата для сравнения строк относительно первого файла
    for (i = 0; i < d1; i++)
    {
        cout << rez1[i] << " " << p1[i] << endl;
    }
    cout << endl <<"file2:" << endl;      // вывод результата для сравнения строк относительно второго файла
    for (i = 0; i < d2; i++)
    {
        cout << rez2[i] << " " << p2[i] << endl;
    }
    file1.close();
    file2.close();

}