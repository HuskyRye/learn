#include <ctime> // time
#include <iomanip> // setw
#include <iostream>
#include <stdlib.h> // rand
#include <string.h> // memset
#include <windows.h> // sleep

using namespace std;

bool cells[20][20];

void help();
void print();
void develop(); // this is really fun!

int main()
{
    system("color f0");
    cout << "Welcome \"the cells of ice1000\"\n";
    cout << "made by ******\n";
    cout << "THIS GAME WONT SHUT YOUR COMPUTER!\n";
    cout << "you have 20x20 cells here\n";
    help();
    cout << "what's next? ";

    srand(time(NULL));

    char ch;
    bool create = false;
    while (cin >> ch) {
        switch (ch) {
        case 'c':
            cout << "input a pair of points to lay a cell\n";
            cout << "format: x y ( x and y must be smaller than 20)\n";
            int x, y;
            cin >> x >> y;
            if (x > 20 || y > 20) {
                cerr << "x or y out of range!\n";
                break;
            }
            cells[y - 1][x - 1] = true;
            break;
        case 'q':
            cells[1][2] = true;
            cells[2][3] = true;
            cells[3][1] = true;
            cells[3][2] = true;
            cells[3][3] = true;
            cout << "preinstall complete\n";
            break;
        case 'v':
            memset(cells, false, 400);
            cout << "clear complete\n";
            print();
            break;
        case 'b':
            print();
            break;
        case 's':
            cout << "细胞是否生存取决于周围8个槽中的细胞数量\n";
            cout << "当前细胞为存活状态时，当周围低于2个（不包含2个）存活细胞时， 该细胞变成死亡状态\n";
            cout << "当前细胞为存活状态时，当周围有2个或3个存活细胞时， 该细胞保持原样\n";
            cout << "当前细胞为存活状态时，当周围有3个以上的存活细胞时，该细胞变成死亡状态\n";
            cout << "当前细胞为死亡状态时，当周围有3个存活细胞时，该细胞变成存活状态\n";
            break;
        case 'z':
            break;
        case 'w':
            cells[rand() % 20][rand() % 20] = true;
            cout << "create complete\n";
            break;
        case 'e':
            system("cls");
            develop();
            system("cls");
            cout << "您只有5秒免费预览，若想知道后续，请充值心悦VIP\n";
            cout << "Thanks for playing this game, ヾ(￣▽￣)Bye~Bye~\n";
            getchar();
            return 0;
            break;
        default:
            cout << "this is not a valid command\n";
            break;
        }
        cout << "what's next? ";
    }
    return 0;
}

void help()
{
    cout << "_____________________________\n";
    cout << " c: lay a cell\n"; //
    cout << " q: preinstall some cells\n"; //
    cout << " v: clear all the cells\n"; //
    cout << " b: view the cells\n"; //
    cout << " s: rules of the cells\n"; //
    cout << " z: help of this game\n"; //
    cout << " w: create a cell randomly\n"; //
    cout << " e: develop\n";
    cout << "_____________________________\n";
}

void print()
{
    cout << "  ";
    for (int i = 1; i <= 20; ++i) {
        cout << ' ' << setw(2) << left << i;
    }
    cout << '\n';
    for (int i = 0; i < 20; ++i) {
        cout << setw(2) << left << i + 1 << ' ';
        for (int j = 0; j < 20; ++j)
            cout << setw(2) << static_cast<char>((cells[i][j]) ? 4 : ' ') << ' ';
        cout << '\n';
    }
}

bool change(int i, int j);

void develop()
{
    for (int t = 0; t < 30; ++t) {

        bool temp[20][20] = { false };
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j) {
                temp[i][j] = change(i, j);
            }
        memcpy(cells, temp, 400);
        print();
        Sleep(1000 / 15);

        // system("cls");
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos{ 0, 0 };
        SetConsoleCursorPosition(handle, pos);
    }
}

bool change(int x, int y) // the most important part
{
    int count = 0;
    // edge
    if (x == 0 && y == 0) { // left-up
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                if (cells[i][j])
                    ++count;
    } else if (x == 0 && y == 19) { // right-up
        for (int i = 0; i < 2; ++i)
            for (int j = 18; j < 20; ++j)
                if (cells[i][j])
                    ++count;
    } else if (x == 19 && y == 0) { // left-down
        for (int i = 18; i < 20; ++i)
            for (int j = 0; j < 2; ++j)
                if (cells[i][j])
                    ++count;
    } else if (x == 19 && y == 19) { // right-down
        for (int i = 18; i < 20; ++i)
            for (int j = 18; j < 20; ++j)
                if (cells[i][j])
                    ++count;
    } else if (y == 0) { // left
        for (int i = x - 1; i < x + 2; ++i)
            for (int j = 0; j < 2; ++j)
                if (cells[i][j])
                    ++count;
    } else if (x == 0) { // up
        for (int i = 0; i < 2; ++i)
            for (int j = y - 1; j < y + 2; ++j)
                if (cells[i][j])
                    ++count;
    } else if (x == 19) { // down
        for (int i = 18; i < 20; ++i)
            for (int j = y - 1; j < y + 2; ++j)
                if (cells[i][j])
                    ++count;
    } else if (y == 19) { // right
        for (int i = x - 1; i < x + 2; ++i)
            for (int j = 18; j < 20; ++j)
                if (cells[i][j])
                    ++count;
    } else { // others
        for (int i = x - 1; i < x + 2; ++i)
            for (int j = y - 1; j < y + 2; ++j)
                if (cells[i][j])
                    ++count;
    }

    if (cells[x][y]) {
        --count;
        if (count < 2 || count > 3)
            return false;
        else
            return true;
    } else {
        if (count == 3)
            return true;
        else
            return false;
    }
}
