#ifndef MAZEPERSON_H
#define MAZEPERSON_H

#include "MazeMap.h"
#include <Windows.h>

class MazePerson
{
public:
	MazePerson();
	bool walkUp();						//向上走动一步，若成功，则返回true，若失败（上面是墙），则返回false
	bool walkDown();					//向下走动一步，若成功，则返回true，若失败（下面是墙），则返回false
	bool walkLeft();					//向左走动一步，若成功，则返回true，若失败（左面是墙），则返回false
	bool walkRight();					//向右走动一步，若成功，则返回true，若失败（右面是墙），则返回false
	void setPersonPos(int x, int y);	//设置游戏角色的位置
	//void setPersonSpeed(int _speed);
	void setPersonChar(char per);		//设置代表游戏角色的字符
	void setPersonDire(char dire);		//设置游戏角色的朝向，这个很重要，因为右手原则里的'右'是游戏角色的'右'，并不是电脑屏幕的'右'
	void moveForward(char dire);		//根据传入的方向使游戏角色移动一步
	void setMap(MazeMap *map);			//设置地图对象
	void start();						//游戏开始函数
	int getSteps();						//获取步数
private:
	char m_cPerson;						//代表游戏角色的字符
	char m_cDire;						//游戏角色的朝向
	COORD m_currentPos;					//游戏角色的当前位置
	//int m_ispeed;
	MazeMap *m_pMap;					//地图对象
	int m_iSteps;						//记录游戏角色走了多少步
};

#endif