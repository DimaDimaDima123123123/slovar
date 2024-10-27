#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void saveToFile(const map<string, string>& dict, const string& filename)
{
    ofstream file(filename);
    if (file.is_open()) 
    {
        for (const auto& entry : dict) 
        {
            file << entry.first << " - " << entry.second << endl;
        }
        file.close();
        cout << "Словарь сохранен в файл: " << filename << endl;
    } else 
    {
        cout << "Ошибка при сохранении в файл!\n";
    }
}

void printDict(const map<string, string>& dict)
{
    for (const auto& entry : dict)
    {
        cout << entry.first << " - " << entry.second << endl;
    }
}

int main() 
{
    setlocale(LC_ALL, "ru");
    map<string, string> dict =
    {
        {"dog", "собака"},
        {"deer", "олень"},
        {"parrot", "попугай"}
    };

    int choice;
    string word, transl, filename = "Dictionary.txt";

    do
    {
        cout << "Выберите действие:\n";
        cout << "1. Добавить слово\n";
        cout << "2. Удалить слово\n";
        cout << "3. Найти перевод\n";
        cout << "4. Сохранить в файл\n";
        cout << "5. Вывести словарь\n";
        cout << "0. Выйти\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Введите слово на английском: ";
                cin >> word;
                cout << "Введите перевод: ";
                cin >> transl;

                if (!word.empty() && !transl.empty()) 
                {
                    dict[word] = transl;
                    cout << "Слово добавлено!\n";
                } 

                else 
                {
                    cout << "Ошибка: ввод пустой.\n";
                }
                break;

            case 2:
                cout << "Введите слово для удаления: ";
                cin >> word;

                if (dict.erase(word)) 
                {
                    cout << "Слово удалено!\n";
                } 

                else 
                {
                    cout << "Слово не найдено.\n";
                }
                break;

            case 3:
                cout << "Введите слово, которое хотите найти: ";
                cin >> word;

                {
                    auto it = dict.find(word);
                    if (it != dict.end()) 
                    {
                        system("cls");
                        system("color 0B");
                        cout << "Перевод: " << it->second << endl;
                    }

                    else 
                    {
                        system("cls");
                        system("color 0C");
                        cout << "Слово не найдено.\n";
                    }
                }
                break;

            case 4:
                saveToFile(dict, filename);

                break;

            case 5:
                printDict(dict);

                break;

            case 0:
                cout << "выход..\n";

                break;

            default:

                cout << "Неправильный выбор.\n";
        }
    } 
    while (choice != 0);

    return 0;
}
