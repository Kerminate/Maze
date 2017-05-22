#include "MazeMap.h"
#include <iostream>
using namespace std;

MazeMap::MazeMap(char wall) :m_cWall(wall)	//�вι��캯�����ô�����ַ���ʼ��ǽ���ÿո��ʼ��·
{
	m_cRoad = ' ';
	m_pMap = NULL;
}

MazeMap::~MazeMap()							//���ڴ洢��ͼ���ݵĶ�ά�����Ƕ�̬������ڴ�ռ䣬����Ҫ�����������н����ͷ�
{
	if (m_pMap)
	{
		for (int i = 0; i < m_iMapRow; i++)
		{
			delete[]m_pMap[i];
			m_pMap[i] = NULL;
		}
		delete[]m_pMap;
		m_pMap = NULL;
		//cout << "~MazeMap()" << endl;
	}
}

void MazeMap::setMazeMap(int *map, int row, int rol)	//���õ�ͼ
{
	m_iMapRow = row;
	m_iMapCol = rol;
	//Ϊ�洢��ͼ���ݵĶ�ά���鶯̬�����ڴ�ռ�
	m_pMap = new int*[m_iMapRow];			//����m_iMapRow���洢int����ָ����ڴ�ռ�
	for (int i = 0; i < m_iMapRow; i++)
	{
		m_pMap[i] = new int[m_iMapCol];		//��ָ�������е�ָ��ָ�򳤶�Ϊm_iMapCol��int����
	}

	//���ô���Ķ�ά�����ʼ����ͼ
	int *p = map;
	for (int i = 0; i < m_iMapRow; i++)
	{
		for (int j = 0; j < m_iMapCol; j++)
		{
			m_pMap[i][j] = *p;
			p++;
		}
	}
}

void MazeMap::setWallChar(char wall)		//���ô���ǽ������
{
	m_cWall = wall;
}

void MazeMap::drawMap()						//��ӡ��ͼ
{
	system("cls");
	for (int i = 0; i < m_iMapRow; i++)
	{
		for (int j = 0; j < m_iMapCol; j++)
		{
			if (m_pMap[i][j])			//����Ԫ����Ϊ1�� ���ӡ����ǽ���ַ�
				cout << m_cWall;
			else                        //����Ԫ����Ϊ0�����ӡ����·���ַ�
				cout << m_cRoad;
		}
		cout << endl;
	}
}

int** MazeMap::getMazeMap()				//���ص�ͼ��ά����ָ��
{
	return m_pMap;
}

void MazeMap::setExitPos(COORD coo)		//���ó���λ��
{
	m_ExitPos = coo;
}

COORD MazeMap::getExitPos()				//��ȡ����λ��
{
	return m_ExitPos;
}