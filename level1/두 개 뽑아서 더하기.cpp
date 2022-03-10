#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (auto it = numbers.begin(); it != numbers.end(); it++)
    {
        for (auto it2 = numbers.begin(); it2 != numbers.end(); it2++)
        {
            if (it == it2)
                continue;
            int plus = *it + *it2;
            bool findnum = false;
            for (auto num : answer)
            {
                if (num == plus)
                {
                    findnum = true;
                    break;
                }
            }
            if (findnum == false)
                answer.push_back(plus);
        }
    }

    for (auto it = answer.begin(); it != answer.end(); it++)
    {
        for (auto it2 = answer.begin(); it2 != answer.end(); it2++)
        {
            if (it == it2)
                continue;

            if (*it < *it2)
            {
                auto tmp = *it;
                *it = *it2;
                *it2 = tmp;
            }
        }
    }

    return answer;
}
