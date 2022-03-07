#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    if(n != 0)
    for(int i = 1 ; i * i <= n; i++ )
    {
        if (n % i == 0 )
        {
            answer = answer + i;
            if (i != (n / i)) // 제곱수가 있는 경우 두번 더해지면 안되기 때문에 if문 추가
                answer = answer + (n / i);
        }
    }
    return answer;
}
