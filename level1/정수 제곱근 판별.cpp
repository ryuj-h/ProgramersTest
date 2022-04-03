#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    
    for (long long i = 1 ; i <= n / i; i++)// 오버플로우를 방지하기 위해서 i * i <= n 대신 i <= n / i 로 계산하였습니다.
    {
        if (i * i == n)
        {
            answer = (i + 1) * (i + 1);
            break;
        }
    }
    
    return answer;
}
