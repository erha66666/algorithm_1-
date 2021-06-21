#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using  namespace std;

const int Maxvertex = 10;// ��ඥ����
const int MaxEdge = 100;// ������

struct EdgeType
{
    int from, to;// ����������������
    int weight;// �ߵ�Ȩֵ
};

template<class T>
struct EdgeGraph
{
    T vertex[Maxvertex];// ��Ŷ�����Ϣ
    vector<EdgeType> edge;// ��űߵ�����(��vector��������)
    int vertexNum, edgeNum;//�������ͱ���
};
int FindRoot(int parent[], int v)// �󶥵��˫�׽��
{
    int t = v;
    while(parent[t]> -1)
        t = parent[t];
    return t;
}
void Kruskal(EdgeGraph<int> G)
{
    int parent[Maxvertex];
    for (int i = 0; i < G.vertexNum; i++)
        parent[i] = -1;// ��ʾ����iû��˫�׽��
    for (int num = 0, i = 0; i < G.edgeNum; i++) {
        int vex1 = FindRoot(parent, G.edge[i].from);
        int vex2 = FindRoot(parent, G.edge[i].to);
        if (vex1 != vex2) {
            cout << G.edge[i].from << G.edge[i].to << endl;
            parent[vex2] = vex1;// �ϲ�������
            num++;
            if (num == G.vertexNum - 1)
                return;
        }
    }
}
bool sort_by_weight(EdgeType&k1, EdgeType&k2)
{
    return k1.weight < k2.weight;
}
int main()
{
    EdgeGraph<int> Edgraph;// ���ͼ����Ϣ
    //����ͼG
    cin >> Edgraph.vertexNum >> Edgraph.edgeNum;
    for (int k = 0; k <Edgraph.edgeNum; k++)
    {
        EdgeType temp;
        cin >> temp.from >> temp.to >> temp.weight;
        Edgraph.edge.push_back(temp);
    }
    // ���߰���Ȩֵ����
    sort(Edgraph.edge.begin(), Edgraph.edge.end(), sort_by_weight);
    Kruskal(Edgraph);
    return 0;
}