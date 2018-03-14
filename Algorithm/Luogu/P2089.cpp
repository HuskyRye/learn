#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int i[10];
    ostringstream os;
    int solution = 0;
    for (i[0] = 1; i[0] < 4; ++(i[0]))
        for (i[1] = 1; i[1] < 4; ++(i[1]))
            for (i[2] = 1; i[2] < 4; ++(i[2]))
                for (i[3] = 1; i[3] < 4; ++(i[3]))
                    for (i[4] = 1; i[4] < 4; ++(i[4]))
                        for (i[5] = 1; i[5] < 4; ++(i[5]))
                            for (i[6] = 1; i[6] < 4; ++(i[6]))
                                for (i[7] = 1; i[7] < 4; ++(i[7]))
                                    for (i[8] = 1; i[8] < 4; ++(i[8]))
                                        for (i[9] = 1; i[9] < 4; ++(i[9]))
                                            if (i[0]+i[1]+i[2]+i[3]+i[4]+i[5]+i[6]+i[7]+i[8]+i[9] == n) {
                                                for (int j = 0; j < 10; ++j)
                                                    os << i[j] << ' ';
                                                os << '\n';
                                                ++solution;
                                            }

    cout << solution << '\n';
    cout << os.str();
    return 0;
}