#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(std::string a, std::string b)
{
    return ((a + b) <  (b + a));
}

string solution(vector<int> numbers) {
    string answer = "";
    std::vector<string> numstrs;
    int zero_count = 1;
    
    for (int i = 0; i < numbers.size(); i++)    
        if (numbers[i] != 0)
            zero_count = 0;
    if (zero_count == 1)
        return ("0");
    for (auto &num : numbers)
        numstrs.push_back(to_string(num));
    sort(numstrs.begin(), numstrs.end(),compare);
    for (int i = numstrs.size() -1; i >= 0; --i)
        answer = answer + numstrs[i];
    return (answer);
}
