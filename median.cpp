#include <iostream>
#include <fstream>

int SoTrungVi(int[]);
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("median.inp");
	fout.open("median.out");


	int m, n, r, c, i, j, k;
	int x[100][100], y[100];
	int tdX = 1, tdY = 1;

	fin >> m;
	fin >> n;
	fin >> r;
	fin >> c;

	for (j = 1; j <= n; j++)
		for (i = 1; i <= m; i++)
			fin >> x[i][j];

	y[0] = r * c;
	k = 0;
	while (true)
	{
		for (j = tdY; j < tdY + c; j++)
			for (i = tdX; i < tdX + r; i++)
			{
				k++;
				y[k] = x[i][j];
			}
		cout << SoTrungVi(y) << "\n";
		tdX++;
		k = 0;
		if (tdX + r - 1 > m)
		{
			tdY++;
			tdX = 1;
			if (tdY + c > n)
				break;
		}
	}



	system("pause");

	fin.close(); fout.close();
	return 0;
}

int SoTrungVi(int y[])
{
	int a;
	int i, j;
	for (i = 1; i <= y[0]; i++)
		for (j = 1; j <= y[0] - i; j++)
			if (y[j] > y[j + 1])
			{
				a = y[j + 1];
				y[j + 1] = y[j];
				y[j] = a;
			}

	if (y[0] % 2 == 1)
		return y[(int)(y[0] / 2) + 1];
	else
		return y[y[0] / 2];


}