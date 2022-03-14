#include <string>
#include <vector>

using namespace std;

int ft_strlen(char * str)
{
    int res = 0;
    while( *str)
    {
        str++;
        res++;
    }
    return res;
}

char *ft_sort(char *str)
{
    int num = ft_strlen(str);
    for(int i = 0 ; i <num - 1; i++)
    {
        for (int j = i + 1 ; j < num ;j++)
        {
            if ( str[i] < str[j])
            {
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
    return str;
}
string solution(string s) {
    
    char *answerc = ft_sort((char *)s.c_str());
    string answer = std::string(answerc);
    return answer;
}
