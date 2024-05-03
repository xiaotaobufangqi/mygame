#pragma once
#include <graphics.h>  //easyx图形库
#include <vector>
using namespace std;

struct Point
{
	int row;
	int col;
};

class Block
{
public:
	Block();
	void drop();
	void moveLeftRight(int offset);
	void rotate(); //旋转
	void draw(int ledtMargin, int topMargin);
	static IMAGE** getImages();
	Block& operator=(const Block& other);

	bool blockInMap(const vector<vector<int>>&map);
	void solidify(vector<vector<int>>& map);
	int getBlockType();

private:
	int blockType;  //方块的类型
	Point smallBlocks[4];  //每种方块类型的四个方块的行列
	IMAGE *img;

private:
	static int size;
	static IMAGE* imgs[7]; //存七个方块图片
};

