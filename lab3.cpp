#include <iostream>
#include<Windows.h>
#include<string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i = 0, k;
    char ABC[] =
    {
                "абвгдеёжзийклмнопрстуфхцчшщъыьэюяабвгдеёжзийклмнопрстуфхцчшщъыьэюя"
    };
    char msg[150];
    cout << "Введите сообщение на русском языке строчными буквами, которое будет закодировано шифром Цезаря: " << endl;
    cin.getline(msg, 150);
    cout << "\nВведите сдвиг :" << endl;
    cin >> k;
    if (k > 33)
    {
        k = k % 33;
    }
    cout << endl;
    char* begin = ABC;
    char* end = ABC + sizeof(ABC);
    for (; msg[i]; ++i)
    {
        char* ch = find(begin, end, msg[i]);
        if (ch != end) msg[i] = *(begin + (ch - begin + k) % sizeof(ABC));
    }
    cout << "Полученное сообщение, скрытое от лишних умов :" << endl;
    cout << msg << endl;
    return 0;
}
