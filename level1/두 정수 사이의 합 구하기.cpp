#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    int plus = 1;
    if ( a < b)
        plus = 1;
    else
        plus = -1;
    for( int i = a; i != b + plus; i = i + plus)
    {
        answer = answer + i;
    }
    
    return answer;
}
