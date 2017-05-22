#include "MazeMap.h"
#include <iostream>
using namespace std;

MazeMap::MazeMap(char wall) :m_cWall(wall)	//有参构造函数，用传入的字符初始化墙，用空格初始化路
{
	m_cRoad = ' ';
	m_pMap = NULL;
}

MazeMap::~MazeMap()							//由于存储地图数据的二维数组是动态申请的内存空间，所以要在析构函数中进行释放
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

void MazeMap::setMazeMap(int *map, int row, int rol)	//设置地图
{
	m_iMapRow = row;
	m_iMapCol = rol;
	//为存储地图数据的二维数组动态分配内存空间
	m_pMap = new int*[m_iMapRow];			//分配m_iMapRow个存储int类型指针的内存空间
	for (int i = 0; i < m_iMapRow; i++)
	{
		m_pMap[i] = new int[m_iMapCol];		//将指针数组中的指针指向长度为m_iMapCol的int数组
	}

	//利用传入的二维数组初始化地图
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

void MazeMap::setWallChar(char wall)		//设置代表墙的数组
{
	m_cWall = wall;
}

void MazeMap::drawMap()						//打印地图
{
	system("cls");
	for (int i = 0; i < m_iMapRow; i++)
	{
		for (int j = 0; j < m_iMapCol; j++)
		{
			if (m_pMap[i][j])			//数组元素若为1， 则打印代表墙的字符
				cout << m_cWall;
			else                        //数组元素若为0，则打印代表路的字符
				cout << m_cRoad;
		}
		cout << endl;
	}
}

int** MazeMap::getMazeMap()				//返回地图二维数组指针
{
	return m_pMap;
}

void MazeMap::setExitPos(COORD coo)		//设置出口位置
{
	m_ExitPos = coo;
}

COORD MazeMap::getExitPos()				//获取出口位置
{
	return m_ExitPos;
}