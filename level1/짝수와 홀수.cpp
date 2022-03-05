#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int num) {
    // 리턴할 값은 메모리를 동적 할당해주세요
    
    int size = 0;
    if (num % 2 == 0)
        size = 4;
    else
        size = 5;
    
    char* answer = (char*)malloc(size);
    if (size == 4)
        strcpy(answer,"Even");
    else
        strcpy(answer,"Odd");
    return answer;
}
