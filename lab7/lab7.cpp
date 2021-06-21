#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main() {

	int m, n;//mԪǮ��n��Ͷ��
	int i, j;//ѭ����������
	int k, tmp_F=0;//tem_m��������i����ĿͶ���Ǯ��  0<=tmp<=j;tmp_F����һ��ѭ���е�Ǯ��
	fin >> m >> n;
	vector< vector<int> > f(n, vector<int>(m + 1));//f[i][x], 0<i<=n,0<=x<=m��
	vector< vector<int> > F(n, vector<int>(m + 1));//F[i][x]����xԪǮͶ�뵽ǰi����Ŀ����������

	for (i = 0; i < n; ++i)
	{
		f[i][0] = 0;//�ڵ�(i+1)����Ŀ��Ͷ��0Ԫ������Ϊ0��ע��i��0��ʼ
	}
	for (i = 0; i < n; ++i)
	{
		for (j = 1; j < m + 1; ++j)
		{//j��1��ʼ��Ҳ���Ǵ�f[0][1]��ʼ
			fin >> f[i][j];
		}
	}
	
	//��F[0][0-m]��ֵ
	for (j = 0; j < m + 1; ++j)
	{
		F[0][j] = f[0][j];//��һ����Ŀ��Ͷ��0-mԪǮ������������f[0][0-m]
	}
	
	for (i = 1; i < n; ++i)
	{//��Ŀѭ������1��ʼ,Ҳ���Ǵ�ǰ2����Ŀ��ʼ�㣬��Ϊ��һ����Ŀ�Ѿ���ֵ
		for (j = 0; j < m + 1; ++j)
		{//Ǯ��ѭ�� ��0��ʼ
			for (k = 0; k <= j; ++k)
			{
				tmp_F = F[i - 1][j - k] + f[i][k];
				if (tmp_F > F[i][j]){
					F[i][j] = tmp_F;
				}
			}
		}
	}
	cout << "the max profit is : " << F[n - 1][m] << endl;
	fout << "the max profit is : " << F[n - 1][m] << endl;
	return 0;
}

