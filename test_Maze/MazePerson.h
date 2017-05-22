#ifndef MAZEPERSON_H
#define MAZEPERSON_H

#include "MazeMap.h"
#include <Windows.h>

class MazePerson
{
public:
	MazePerson();
	bool walkUp();						//�����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
	bool walkDown();					//�����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
	bool walkLeft();					//�����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
	bool walkRight();					//�����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
	void setPersonPos(int x, int y);	//������Ϸ��ɫ��λ��
	//void setPersonSpeed(int _speed);
	void setPersonChar(char per);		//���ô�����Ϸ��ɫ���ַ�
	void setPersonDire(char dire);		//������Ϸ��ɫ�ĳ����������Ҫ����Ϊ����ԭ�����'��'����Ϸ��ɫ��'��'�������ǵ�����Ļ��'��'
	void moveForward(char dire);		//���ݴ���ķ���ʹ��Ϸ��ɫ�ƶ�һ��
	void setMap(MazeMap *map);			//���õ�ͼ����
	void start();						//��Ϸ��ʼ����
	int getSteps();						//��ȡ����
private:
	char m_cPerson;						//������Ϸ��ɫ���ַ�
	char m_cDire;						//��Ϸ��ɫ�ĳ���
	COORD m_currentPos;					//��Ϸ��ɫ�ĵ�ǰλ��
	//int m_ispeed;
	MazeMap *m_pMap;					//��ͼ����
	int m_iSteps;						//��¼��Ϸ��ɫ���˶��ٲ�
};

#endif