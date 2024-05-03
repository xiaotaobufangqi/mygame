#pragma once
#include <graphics.h>
#include <vector>
#include "Block.h"
using namespace std;

class Tetris
{
public:
	Tetris(int rows, int cols, int left, int top, int blockSize);
	void init(); //初始化
	void play();  //开始游戏

private:
	void keyEvent();
	void updateWindow();
	int getDelay(); //返回距离上次调用该函数，间隔了多少时间(ms)
	void drop();
	void clearLine();
	void moveLeftRight(int offset);
	void rotate();  //旋转
	void drawScore();  //绘制当前的分数
	void checkOver();  //检查游戏是否结束
	void saveScore();  //保存最高分
	void displayOver(); //绘制游戏结束画面

private:
	int delay;
	bool update; //是否更新
	
	/*int map[20][10];*/
	//0:空白，没有方块
	//5：第5种方块
	vector<vector<int>> map;
	int rows;
	int cols;
	int leftMargin;
	int topMargin;
	int blockSize;
	IMAGE imgBg;

	Block* curBlock;
	Block* nextBlock;  //预告方块
	Block bakBlock;  //当前方块降落过程中，用来备份上一个合法位置

	int score; //当前的分数
	int highestScore; //最高分
	int level; //当前关卡
	int lineCount; //当前已经消除了多少行
	bool gameOver; //游戏是否已经结束

	IMAGE imgOver;
	IMAGE imgWin;
};

