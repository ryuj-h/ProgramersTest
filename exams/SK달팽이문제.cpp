#include <string>
#include <vector>
#include <iostream>

using namespace std;
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <Windows.h>
// n x n 배열을 할당해주는 보조함수입니다.
int** emptysquare(int size) {
    int** result = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) result[i] = (int*)calloc(size, sizeof(int));
    return result;
}

int** solution(int n, bool clockwise) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int** answer = emptysquare(n);

    enum { RIGHT, DOWN, LEFT, UP };

    int plus = 1;

    if (clockwise)
        plus = 1;
    else
        plus = -1;

    int cnt = 1;
    int dir[4];

    if (clockwise)
    {
        dir[0] = RIGHT;
        dir[1] = DOWN;
        dir[2] = LEFT;
        dir[3] = UP;
    }
    else
    {
        dir[0] = DOWN;
        dir[1] = LEFT;
        dir[2] = UP;
        dir[3] = RIGHT;
    }
    int xx[4];
    int yy[4];

    xx[0] = 0, yy[0] = 0;
    xx[1] = n - 1, yy[1] = 0;
    xx[2] = n - 1, yy[2] = n - 1;
    xx[3] = 0, yy[3] = n - 1;

    while (cnt <= n * n / 4 + n * n % 4)
    {
        for (int i = 0; i < 4; i++)
            answer[yy[i]][xx[i]] = cnt;

        for (int i = 0; i < 4; i++)
        {
            switch (dir[i])
            {
            case RIGHT:
                if (answer[yy[i]][xx[i] + 1] == 0)
                    xx[i] = xx[i] + 1;
                else
                {
                    if(clockwise)
                        dir[i] = DOWN;
                    else
                        dir[i] = UP;
                    yy[i] = yy[i] + plus;
                }
                break;
            case DOWN:
                if (answer[yy[i] + 1][xx[i]] == 0)
                    yy[i] = yy[i] + 1;
                else
                {
                    if (clockwise)
                        dir[i] = LEFT;
                    else
                        dir[i] = RIGHT;

                    xx[i] = xx[i] - plus;
                }
                break;
            case LEFT:
                if (answer[yy[i]][xx[i] - 1] == 0)
                    xx[i] = xx[i] - 1;
                else
                {
                    if (clockwise)
                        dir[i] = UP;
                    else
                        dir[i] = DOWN;
                    yy[i] = yy[i] - plus;
                }
                break;
            case UP:
                if (answer[yy[i] - 1][xx[i]] == 0)
                    yy[i] = yy[i] - 1;
                else
                {
                    if (clockwise)
                        dir[i] = RIGHT;
                    else
                        dir[i] = LEFT;
                    xx[i] = xx[i] + plus;
                }
                break;
            }
        }
        cnt++;
    }
    return answer;
}

int main()
{
    int n = 15;
    auto arr = solution(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;


}
