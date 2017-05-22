#ifndef MAZEMAP_H
#define MAZEMAP_H

#include <Windows.h>

class MazeMap
{
public:
	MazeMap(char wall);
	~MazeMap();
	void setWallChar(char wall);	//���ô���ǽ���ַ�
	void setMazeMap(int *map, int row, int col);	//����ָ���ͼ��ά�����ָ��
	int** getMazeMap();				//��ȡ��ͼ��ά�����ָ��
	void drawMap();					//��ӡ��ͼ
	void setExitPos(COORD coo);		//���ó���λ��
	COORD getExitPos();				//��ȡ����λ��
private:
	int **m_pMap;					//ָ���ͼ��ά�����ָ��
	char m_cWall;					//����ǽ���ַ�
	char m_cRoad;					//����·���ַ�
	int m_iMapRow;					//��ά���������
	int m_iMapCol;					//��ά���������
	COORD m_ExitPos;				//�Թ����ڵ�����
};

#endif // !MAZEMAP_H


