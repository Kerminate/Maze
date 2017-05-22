#include "MazePerson.h"
#include <Windows.h>
#include <iostream>
using namespace std;

MazePerson::MazePerson()						//构造函数，初始化角色已走的步数
{
	m_iSteps = 0;
}

void MazePerson::setPersonChar(char per)		//设置代表游戏角色的字符
{
	m_cPerson = per;
}

void MazePerson::setPersonDire(char dire)		//设置游戏角色的朝向
{
	m_cDire = dire;
}

void MazePerson::setPersonPos(int x, int y)		//设置游戏角色的位置
{
	unsigned long numWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	m_currentPos.X = x;
	m_currentPos.Y = y;
	FillConsoleOutputCharacter(handle, m_cPerson, 1, m_currentPos, &numWritten);
}

void MazePerson::setMap(MazeMap *map)			//设置地图
{
	m_pMap = map;
}

//根据传入的方向使游戏角色移动一步
//这里我们细化下游戏角色移动的过程：首先让游戏角色在当前位置消失，然后让游戏角色在下一个位置出现。
void MazePerson::moveForward(char dire)
{
	unsigned long numWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);						//获取命令行窗口的窗口句柄
	FillConsoleOutputCharacter(handle, ' ', 1, m_currentPos, &numWritten);	//在指定坐标位置填充指定的字符,这里我们在游戏角色的当前位置填充空格，使游戏角色消失
	//根据传入的方向来设置下一个位置的坐标。
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
	FillConsoleOutputCharacter(handle, m_cPerson, 1, m_currentPos, &numWritten);	//游戏角色的坐标已经更新，现在要做的是在新坐标的位置上填出代表游戏角色的字符
	m_cDire = dire;																	//移动完成后更新游戏角色的朝向
}

//向上走一步
//首先判断游戏角色上方的位置是墙还是路，若是路，则调用moveForward进行移动，若是墙，则直接返回false，表示移动失败
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

int MazePerson::getSteps()		//获取步数
{
	return m_iSteps;
}

void MazePerson::start()		//游戏开始函数
{
	while (true)
	{
		m_pMap->drawMap();
		switch (m_cDire)
		{
		case 'U':
			walkRight() || walkUp() || walkLeft() || walkDown();	//游戏角色朝上时，优先向右走，其次向上走，再次向走左，最次向下走（右手原则）
			break;
		case 'R':
			walkDown() || walkRight() || walkUp() || walkLeft();	//同样是右手原则，由于此时游戏角色朝下，所以此时游戏角色的右是电脑屏幕的左，其他方向依次类推
			break;
		case 'D':
			walkLeft() || walkDown() || walkRight() || walkUp();	//还是右手原则，由于此时游戏角色朝右，所以此时游戏角色的右是电脑屏幕的下，其他方向依次类推
			break;
		case 'L':
			walkUp() || walkLeft() || walkDown() || walkRight();	//也是右手原则，由于此时游戏角色朝左，所以此时游戏角色的右是电脑屏幕的上，其他方向依次类推
			break;
		default:
			break;
		}
		m_iSteps++;
		if (m_currentPos.X == m_pMap->getExitPos().X && m_currentPos.Y == m_pMap->getExitPos().Y)	//判断游戏角色的当前位置是否是迷宫出口位置，如果到达出口，游戏结束
			break;
		cout << "已经走了" << m_iSteps << "步" << endl;
		Sleep(500);													//为了使游戏角色的移动过程可见，所以每走一步，要歇息一段时间(Sleep函数传入参数的单位是毫秒)
	}
}