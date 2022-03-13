#include <string>
#include <vector>

using namespace std;

//atoi
int solution(string s) {
    int answer = 0;
    int minus = 1;
    const char * str = s.c_str();
    while (*str)
    {
        while (*str && *str == '-' ||*str == '+')
        {
            if (*str == '-')
                minus = minus * -1;
            str++;
        }
        while (*str && *str >= '0' && *str <= '9')
        {
            answer = answer * 10 + *str - '0';
            str++;
        }
    }
    return answer * minus;
}
