// Лабораторная работа 1. Шифр Цезаря. Сабитова Кристина ИТ-41
#include <iostream> 
#include <string>
#include <locale.h>
#include <ctime>

using namespace std;

const int AlphSize = 26; //Размер алфавита

const char eng[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }; //английский алфавит


string encryption(string& s, const int key) //функция для шифрования входного сообщения
{
    setlocale(LC_ALL, "Russian");
    bool Bool; //Булевая переменная для определения является ли символ буквой алфавита
    string result(""); //Зашифрованная строка
    for (unsigned i = 0; i < s.length(); i++)
    {
        Bool = false; 
        for (int j = 0; j < AlphSize; j++)
        { //Перебираем все буквы алфавита на поиск совпадения
            if (isupper(s[i]))
            {
                s[i] = tolower(s[i]);
            }
            else if (s[i] == eng[j]) //Если символ оказался буквой алфавита
            {
                j += key; //Сдвигаем букву по алфавиту на значение ключа
                while (j >= AlphSize) j -= AlphSize; 
                while (j < 0) j += AlphSize; 
                result += eng[j]; //Добавляем полученный символ в конец строки
                Bool = true; //Символ был зашифрован
                break; 
            }
            
        }
        if (!Bool) result += s[i]; //Если символ не входит в алфавит, то оставляем его без изменений
    }
    return result; 
}
string decryption(string& s, const int key) //функция для дешифрования входного сообщения
{ 
    setlocale(LC_ALL, "Russian");
    bool Bool; 
    string result(""); 
    for (unsigned i = 0; i < s.length(); i++)
    { 
        Bool = false; 
        for (int j = 0; j < AlphSize; j++)
        { 
            if (isupper(s[i]))
            {
                s[i] = tolower(s[i]);
            }
            else if (s[i] == eng[j]) 
            {
                j -= key; 
                while (j >= AlphSize) j -= AlphSize; 
                while (j < 0) j += AlphSize; 
                result += eng[j]; 
                Bool = true; 
                break; 
            }

        }
        if (!Bool) result += s[i]; 
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string s; //Шифруемая строка
    string d;//Дешифруемая строка
    int key; //Ключ(сдвиг)
       
                cout << "Введите значение ключа: ";
                cin >> key;
                cout << "Введите сообщение для шифрования: ";
                while (cin >> s) //Шифруем по одному слову
                {
                    cout << encryption(s, key) << ' ';
                    if (cin.get() == '\n') break; 
                }
                cout << endl;
                
                cout << "Введите сообщение для дешифрования: ";
                while (cin >> d) 
                {
                    cout << decryption(d, key) << ' ';
                    if (cin.get() == '\n') break; 
                }
                cout << endl;
                system("pause");
                return 0;
}