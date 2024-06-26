#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// 1 - инфа, 2 - физика, 3 - математика, 4 - русский

static void print_Subject(const short int num) {
    switch (num)
    {
    case 1:
        cout << "Занятие информатикой...\n";
        break;
    case 2:
        cout << "Занятие физикой...\n";
        break;
    case 3:
        cout << "Занятие математикой...\n";
        break;
    case 4:
        cout << "Занятие русским...\n";
        break;

    default:
        break;
    }
}

void to_h() {

}

string f_ifstream() {
    ifstream fin("A:\\Desktop\\TimerPro\\TotalSecond.txt");
    if (!fin.is_open()) {
        cout << "ошибка!\n";
        return "";
    }
    string buf = ""; size_t sec;
    fin >> sec;
    buf += "Информатика общее время: " + to_string(sec / 3600) + ":" + to_string(sec % 3600 / 60) + ":" + to_string(sec % 3600 % 60) + (char)10;
    fin >> sec;
    buf += "Физика общее время: " + to_string(sec / 3600) + ":" + to_string(sec % 3600 / 60) + ":" + to_string(sec % 3600 % 60) + (char)10;
    fin >> sec;
    buf += "Математика общее время: " + to_string(sec / 3600) + ":" + to_string(sec % 3600 / 60) + ":" + to_string(sec % 3600 % 60) + (char)10;
    fin >> sec;
    buf += "Русский общее время: " + to_string(sec / 3600) + ":" + to_string(sec % 3600 / 60) + ":" + to_string(sec % 3600 % 60) + (char)10;
    return buf;
}

static void f_ofstream(const size_t sec, const short int num) {
    string result = ""; short a;
    ifstream fin("A:\\Desktop\\TimerPro\\TotalSecond.txt");
    for (size_t i = 0; i < 4; ++i) {
        fin >> a;
        if (i == num-1) {
            result += to_string(a + sec) + " ";
        }
        else {
            result += to_string(a) + " ";
        }
    }
    fin.close();
    ofstream fout("A:\\Desktop\\TimerPro\\TotalSecond.txt");
    if (!fout.is_open()) {
        return;
        cout << "ошибка(\n";
    }
    fout << result;
    fout.close();
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    size_t time0 = time(0);
    size_t total = 0;
    short subject = 0; 

    while (subject != -1) {
        system("Cls");
        total = 0;
        cout << "-1 - выход, 0 - вывод всего на экран, 1 - инфа, 2 - физика, 3 - математика, 4 - русский\n";
        cin >> subject;
        if (subject == 0) {
            cout << "\n" << f_ifstream() << "\n";
            system("Pause");
            continue;
        }
        else if (subject == -1) {
            system("Pause");
            break;
        } 
        system("Pause");
        system("Cls");
        if (!(subject == 1 || subject == 2 || subject == 3 || subject == 4)) {
            cout << "Ошибка!\n";
            system("Pause");
            continue;
        }
        print_Subject(subject);
        do {
            cout << "\r" << total;
            ++total;
            Sleep(989);
        } while (!GetAsyncKeyState(0xC0));//0xC0 это ~
        f_ofstream(total-1, subject);
        cout << "\nФинальное время: " << total / 3600 << ":" << (total - (total / 3600) * 3600) / 60 << ":" << total - (total / 3600 * 3600) - (total - total / 3600 * 3600) / 60 * 60 << "\n";
        system("Pause");
    }
    return (0);
}