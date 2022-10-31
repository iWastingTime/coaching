#include <iostream>
#define NOMINMAX
#include <windows.h>
#include <stdlib.h>


using namespace std;
int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int start, tho, hun, doz, uni, temp, sum = 0, flip = 0, oper = 1; // Объявляем переменные.
    char another; // Объявляем ещё одну переменную.
    for (;;) { // Цикл для использования программы без закрытий в случае ошибок ввода и повторного использования без перезапуска.
        SetConsoleTextAttribute(hConsole, 14); // Для красоты =)
        cout << "- --- ---- ----- [ START OF OPERATION #" << oper << " ] ----- ---- --- -"; // Для красоты =)
        cout << "\n";
        cout << "\n";
        SetConsoleTextAttribute(hConsole, 11);
        cout << "[ Enter 4 digits number ] >> ";
        cin >> start;
        if (cin.fail()) { // Проверка на число.
            cin.clear(); // Чистим ошибку.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем ввод.
            SetConsoleTextAttribute(hConsole, 12);
            cout << "[ ERROR ] << Not a number." << endl;
            cout << "\n";
            cout << "- -- --- ---- [ OPERATION #" << oper << " END WITH ERROR ] ---- --- -- -";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            oper += 1; // Прибавляем единичку к количеству проведенных операций.
            continue; // Отправляемся обратно.
        }
        if ((start < 1000) || (start > 9999)) { // Проверяем область допустимых значений.
            cin.clear(); // Чистим.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем.
            SetConsoleTextAttribute(hConsole, 12);
            cout << "[ ERROR ] << Only 4 digits number." << endl;
            cout << "\n";
            cout << "- -- --- ---- [ OPERATION #" << oper << " END WITH ERROR ] ---- --- -- -";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            oper += 1; // Прибавляем единичку к количеству проведенных операций.
            continue;
        }
        tho = start / 1000; // Считаем тысячи.
        temp = start / 10; // Считаем сотни 1/3.
        temp = temp / 10; // Считаем сотни 2/3.
        hun = temp % 10; // Считаем сотни 3/3.
        temp = start / 10; // Считаем десятки 1/2.
        doz = temp % 10; // Считаем десятки 2/2.
        uni = start % 10; // Считаем единицы.
        temp = start; // Готовим работягу к следующей операции.
        while (temp) { // Собственно говоря переворот.
            flip = flip * 10 + temp % 10;
            temp /= 10;
        }
        temp = start; // Готовим работягу к следующей операции.
        while (temp != 0) { // Сумма чисел. Да, у меня есть все цифры в переменных, и я мог бы просто сделать [ tho + hun + doz + uni ], но разве это интересно?)
            sum += temp % 10;
            temp /= 10;
        }
        cout <<"\n"; // Для красоты =)
        SetConsoleTextAttribute(hConsole, 10);
        cout << "- -- --- ---- ----- [ RESULT FOR " << start << " ] ----- ---- --- -- -\n"; // Выводим результаты.
        cout << "\n";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "[ Flip ] << [" << flip << "] <-> [" << start << "]\n";
        cout << "[ Sum ] << [" << sum << "] << [" << tho << "+" << hun << "+" << doz << "+" << uni << "]\n";
        cout << "[ Thousands ] << [" << tho << "] 0---\n";
        cout << "[ Hundreds ] << [" << hun << "] -0--\n";
        cout << "[ Dozens ] << [" << doz << "] --0-\n";
        cout << "[ Units ] << [" << uni << "] ---0\n";
        cout << "\n";
        SetConsoleTextAttribute(hConsole, 10);
        cout << "- -- --- ---- ----- ------------------- ----- ---- --- -- -";
        cout << "\n";
        cout <<endl;
        SetConsoleTextAttribute(hConsole, 11);
        do { // Спрашиваем чего хочет юзер. Используем [ do/while ], чтобы получить ответ только [ n ] или [ c ] или [ e ].
            cout << "[ Whats next? ] - [ n(ew) / c(lear) / e(xit) ] >> ";
            cin >> another;
            cout << "\n";
        } 
        while (!cin.fail() && another != 'n' && another != 'e' && another != 'c');
        if (another == 'n') { // Если ответ [ n ], то отправляемся обратно в самое начало.
            start = 0; // Обнуляем переменные для корректной работы с следующим запросом.
            flip = 0;
            sum = 0;
            SetConsoleTextAttribute(hConsole, 14);
            cout << "-- --- ---- ----- [ END OF OPERATION #"<< oper <<" ] ----- ---- --- --"; // Для красоты =)
            cout << "\n";
            cout << "\n";
            cout << "\n";
            oper += 1; // Прибавляем единичку к количеству проведенных операций.
            continue; // Возвращаемся на старт.
        }
        if (another == 'e') { // Если ответ [ e ], то завершаем работу с программой.
            SetConsoleTextAttribute(hConsole, 13);
            cout << "- --- ---- ----- [ EXIT ] ----- ---- --- -";
            break; // Пока!
        }
        if (another == 'c') {
            system("CLS"); // Чистим консоль.
            do { // Спрашиваем хочет ли юзер вбить ещё число или выйти. Используем [ do/while ], чтобы получить ответ только [ n ] или [ e ].
                cout << "[ Whats next? ] - [ n(ew) / e(xit)] >> ";
                    cin >> another;
                    cout << "\n";
            }
            while (!cin.fail() && another != 'n' && another != 'e');
            if (another == 'n') { // Если ответ [ n ], то отправляемся обратно в самое начало.
                start = 0; // Обнуляем переменные для корректной работы с следующим запросом.
                flip = 0;
                sum = 0;
                SetConsoleTextAttribute(hConsole, 10);
                cout << "\n";
                oper += 1; // Прибавляем единичку к количеству проведенных операций.
                continue; // Возвращаемся на старт.
                }
            if (another == 'e') { // Если ответ [ e ], то завершаем работу с программой.
                SetConsoleTextAttribute(hConsole, 13);
                cout << "- --- ---- ----- [ EXIT ] ----- ---- --- -";
                break; // Пока!
            }
        }
    }
}
