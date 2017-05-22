#include "MazePerson.h"
#include <Windows.h>
#include <iostream>
using namespace std;

MazePerson::MazePerson()						//���캯������ʼ����ɫ���ߵĲ���
{
	m_iSteps = 0;
}

void MazePerson::setPersonChar(char per)		//���ô�����Ϸ��ɫ���ַ�
{
	m_cPerson = per;
}

void MazePerson::setPersonDire(char dire)		//������Ϸ��ɫ�ĳ���
{
	m_cDire = dire;
}

void MazePerson::setPersonPos(int x, int y)		//������Ϸ��ɫ��λ��
{
	unsigned long numWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	m_currentPos.X = x;
	m_currentPos.Y = y;
	FillConsoleOutputCharacter(handle, m_cPerson, 1, m_currentPos, &numWritten);
}

void MazePerson::setMap(MazeMap *map)			//���õ�ͼ
{
	m_pMap = map;
}

//���ݴ���ķ���ʹ��Ϸ��ɫ�ƶ�һ��
//��������ϸ������Ϸ��ɫ�ƶ��Ĺ��̣���������Ϸ��ɫ�ڵ�ǰλ����ʧ��Ȼ������Ϸ��ɫ����һ��λ�ó��֡�
void MazePerson::moveForward(char dire)
{
	unsigned long numWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);						//��ȡ�����д��ڵĴ��ھ��
	FillConsoleOutputCharacter(handle, ' ', 1, m_currentPos, &numWritten);	//��ָ������λ�����ָ�����ַ�,������������Ϸ��ɫ�ĵ�ǰλ�����ո�ʹ��Ϸ��ɫ��ʧ
	//���ݴ���ķ�����������һ��λ�õ����ꡣ
	switch (dire)
	{
	case 'U':
		m_currentPos.Y -= 1;
		break;
	case 'R':
		m_currentPos.X += 1;
		break;
	case 'L':
		m_currentPos.X -= 1;
		break;
	case 'D':
		m_currentPos.Y += 1;
		break;
	default:
		break;
	}
	FillConsoleOutputCharacter(handle, m_cPerson, 1, m_currentPos, &numWritten);	//��Ϸ��ɫ�������Ѿ����£�����Ҫ���������������λ�������������Ϸ��ɫ���ַ�
	m_cDire = dire;																	//�ƶ���ɺ������Ϸ��ɫ�ĳ���
}

//������һ��
//�����ж���Ϸ��ɫ�Ϸ���λ����ǽ����·������·�������moveForward�����ƶ�������ǽ����ֱ�ӷ���false����ʾ�ƶ�ʧ��
bool MazePerson::walkUp()
{
	if (m_pMap->getMazeMap()[m_currentPos.Y - 1][m_currentPos.X])
		return false;
	else
	{
		moveForward('U');
		return true;
	}
}

bool MazePerson::walkDown()
{
	if (m_pMap->getMazeMap()[m_currentPos.Y + 1][m_currentPos.X])
		return false;
	else
	{
		moveForward('D');
		return true;
	}
}

bool MazePerson::walkLeft()
{
	if (m_pMap->getMazeMap()[m_currentPos.Y][m_currentPos.X - 1])
		return false;
	else
	{
		moveForward('L');
		return true;
	}
}

bool MazePerson::walkRight()
{
	if (m_pMap->getMazeMap()[m_currentPos.Y][m_currentPos.X + 1])
		return false;
	else
	{
		moveForward('R');
		return true;
	}
}

int MazePerson::getSteps()		//��ȡ����
{
	return m_iSteps;
}

void MazePerson::start()		//��Ϸ��ʼ����
{
	while (true)
	{
		m_pMap->drawMap();
		switch (m_cDire)
		{
		case 'U':
			walkRight() || walkUp() || walkLeft() || walkDown();	//��Ϸ��ɫ����ʱ�����������ߣ���������ߣ��ٴ���������������ߣ�����ԭ��
			break;
		case 'R':
			walkDown() || walkRight() || walkUp() || walkLeft();	//ͬ��������ԭ�����ڴ�ʱ��Ϸ��ɫ���£����Դ�ʱ��Ϸ��ɫ�����ǵ�����Ļ��������������������
			break;
		case 'D':
			walkLeft() || walkDown() || walkRight() || walkUp();	//��������ԭ�����ڴ�ʱ��Ϸ��ɫ���ң����Դ�ʱ��Ϸ��ɫ�����ǵ�����Ļ���£�����������������
			break;
		case 'L':
			walkUp() || walkLeft() || walkDown() || walkRight();	//Ҳ������ԭ�����ڴ�ʱ��Ϸ��ɫ�������Դ�ʱ��Ϸ��ɫ�����ǵ�����Ļ���ϣ�����������������
			break;
		default:
			break;
		}
		m_iSteps++;
		if (m_currentPos.X == m_pMap->getExitPos().X && m_currentPos.Y == m_pMap->getExitPos().Y)	//�ж���Ϸ��ɫ�ĵ�ǰλ���Ƿ����Թ�����λ�ã����������ڣ���Ϸ����
			break;
		cout << "�Ѿ�����" << m_iSteps << "��" << endl;
		Sleep(500);													//Ϊ��ʹ��Ϸ��ɫ���ƶ����̿ɼ�������ÿ��һ����ҪЪϢһ��ʱ��(Sleep������������ĵ�λ�Ǻ���)
	}
}