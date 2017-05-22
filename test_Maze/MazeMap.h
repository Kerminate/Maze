#ifndef MAZEMAP_H
#define MAZEMAP_H

#include <Windows.h>

class MazeMap
{
public:
	MazeMap(char wall);
	~MazeMap();
	void setWallChar(char wall);	//设置代表墙的字符
	void setMazeMap(int *map, int row, int col);	//设置指向地图二维数组的指针
	int** getMazeMap();				//获取地图二维数组的指针
	void drawMap();					//打印地图
	void setExitPos(COORD coo);		//设置出口位置
	COORD getExitPos();				//获取出口位置
private:
	int **m_pMap;					//指向地图二维数组的指针
	char m_cWall;					//代表墙的字符
	char m_cRoad;					//代表路的字符
	int m_iMapRow;					//二维数组的行数
	int m_iMapCol;					//二维数组的列数
	COORD m_ExitPos;				//迷宫出口的坐标
};

#endif // !MAZEMAP_H


