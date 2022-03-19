#include <string>
#include <vector>
#include <iostream>

using namespace std;

int			arr[1000][1000];

vector<int> solution(int n) {
	vector<int>	answer;
	int			finval = 0;
	int			x = 0;
	int			y = 0;
	int			dir = 0;// 0이면 아래로, 1이면 오른쪽으로, 2이면 왼쪽대각선 위로
	int			currnum = 1;

	for (int yy = 0; yy < n; yy++)// 배열 0으로 초기화
	{
		for (int xx = 0; xx < n; xx++)
		{
			arr[yy][xx] = 0;
		}
	}

	for (int i = 0; i < n; i++)// 마지막 수 구하기
	{
		finval += i + 1;
	}

	while (currnum <= finval)
	{
		arr[y][x] = currnum;
		switch (dir)
		{
		case 0://아래일 경우
			if (arr[y + 1][x] == 0 && y + 1 < n)
			{
				y++;
			}
			else
			{
				x++;
				dir = 1;
			}
			break;
		case 1://오른쪽일 경우
			if (arr[y][x + 1] == 0 && x + 1 < n)
			{
				x++;
			}
			else
			{
				y--; x--;
				dir = 2;
			}
			break;
		case 2://대각선 위로 올라갈 경우
			if (arr[y - 1][x - 1] == 0)
			{
				y--;
				x--;
			}
			else
			{
				y++;
				dir = 0;
			}
			break;
		default:
			break;
		}
		/*for (int yy = 0; yy < n; yy++)
		{
			for (int xx = 0; xx < n; xx++)
			{
				cout << arr[yy][xx] << "  ";
			}
			cout << endl;
		}*/
		currnum++;
	}

	//0을 제외한 수를 벡터에 담아서 출력
	int curr = 0;
	for (int yy = 0; yy < n; yy++)
	{
		for (int xx = 0; xx < n; xx++)
		{
			if (arr[yy][xx] != 0 && curr <= finval)
			{
				answer.push_back(arr[yy][xx]);
				curr++;
			}
		}
	}

    return answer;
}
/*
int main(void)
{
	vector<int> ans = solution(6);

	for (auto& e : ans)
		cout << e << " ";
	cout << endl;
	return	0;
}
*/
