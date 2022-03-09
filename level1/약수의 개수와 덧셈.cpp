#include <string>
#include <vector>

using namespace std;

int getYaksunum(int num)
{
    int result = 0;
    for( int i = 1 ; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            if (num / i != i)
                result = result + 2;
            else
                result = result + 1;
        }
    }
    return (result);
}

int solution(int left, int right) {
    int answer = 0;
    int plus = 1;
    
    if (left < right)
        plus = 1;
    else
        plus = -1;
    for (int i = left; i != right + plus; i = i + plus)
    {
        int yaknum = getYaksunum(i);
        if (yaknum % 2 == 0)
            answer = answer + i;
        else
            answer = answer - i;
    }
    return (answer);
}
