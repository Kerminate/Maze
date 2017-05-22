#include "MazeMap.h"
#include "MazePerson.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	int map[8][9] = {
		{1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1}
	};

	MazeMap *mm = new MazeMap('*');
	COORD exitpos;
	exitpos.X = 7;
	exitpos.Y = 0;
	mm->setExitPos(exitpos);
	mm->setMazeMap(&map[0][0], 8, 9);
	mm->drawMap();

	//string emptySpace(5, '\n');
	//cout << emptySpace;

	MazePerson *mazer = new MazePerson();
	mazer->setPersonPos(1, 7);
	mazer->setPersonChar('T');
	mazer->setPersonDire('U');
	mazer->setMap(mm);
	mazer->start();
	cout << "总共走了" << mazer->getSteps() << "步" << endl;

	delete mm;
	mm = NULL;

	delete mazer;
	mazer = NULL;

	system("pause");
	return 0;
}
