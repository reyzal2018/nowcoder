//编程题1
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <queue>
#include <functional>
using namespace std;

int rows, cols;
vector<string> mat;
bool visited[50][50][50][50];

struct Step
{
	int manx, many;
	int boxx, boxy;
	int times;

	bool checkman()
	{
		return manx >= 0 && manx < cols && many >= 0 && many < rows && mat[many][manx] == '.';
	}

	bool checkbox()
	{
		return boxx >= 0 && boxx < cols && boxy >= 0 && boxy < rows && mat[boxy][boxx] == '.';
	}
	bool checkvisit()
	{
		if (visited[manx][many][boxx][boxy])
			return true;
		visited[manx][many][boxx][boxy] = true;
		return false;
	}
};

int main(int argc, char** argv) {
	cin >> rows >> cols;
	mat.resize(rows);
	int expectx, expecty;
	Step InitStep;
	for (size_t i = 0; i < rows; i++)
	{
		cin >> mat[i];
		for (size_t j = 0; j < cols; j++)
		{
			if (mat[i][j] == 'S') {
				InitStep.manx = j;
				InitStep.many = i;
				mat[i][j] = '.';
			}
			if (mat[i][j] == '0') {
				InitStep.boxx = j;
				InitStep.boxy = i;
				mat[i][j] = '.';
			}
			if (mat[i][j] == 'E') {
				expectx = j;
				expecty = i;
				mat[i][j] = '.';
			}
		}
	}
	InitStep.times = 0;
	int dirs[4][2] = {
		{ -1,0 },
		{ 0,1 },
		{ 1,0 },
		{ 0,-1 }
	};
	memset(visited, 0, 50 * 50 * 50 * 50);
	queue<Step> q;
	q.push(InitStep);
	int result = -1;
	while (result == -1 && !q.empty())
	{
		Step front = q.front();
		q.pop();
		for (size_t dir = 0; dir < 4; dir++)
		{
			//方向 左下右上
			Step nextStep = front;
			nextStep.times++;
			nextStep.manx += dirs[dir][0];
			nextStep.many += dirs[dir][1];
			if (!nextStep.checkman())
				continue;
			if (nextStep.manx == nextStep.boxx &&
				nextStep.many == nextStep.boxy) {
				nextStep.boxx += dirs[dir][0];
				nextStep.boxy += dirs[dir][1];
				if (!nextStep.checkbox())
					continue;
			}
			if (nextStep.checkvisit())
				continue;
			if (nextStep.boxx == expectx &&
				nextStep.boxy == expecty)
			{
				//cout << "找到"<<nextStep.times << endl;
				result = nextStep.times;
				break;
			}
			q.push(nextStep);
		}
	}
	cout << result << endl;
    return 0;
}