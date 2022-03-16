#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    bool numarr[10] = {false,};
    for(auto nb:numbers)
    {
        numarr[nb] = true;
    }
    for(int i = 0; i< 10;i++)
    {
        if(numarr[i] == false)
        {
            if(answer == -1)
                answer = i;
            else
                answer = answer + i;
        }
    }
    
    return answer;
}
