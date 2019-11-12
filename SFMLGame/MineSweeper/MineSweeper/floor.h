#pragma once

#define  GRIDSIZE 25
#define  LVL1_WIDTH 9
#define  LVL1_HEIGHT 9
#define  LVL1_NUM 10
#define  LVL2_WIDTH 16
#define  LVL2_HEIGHT 16
#define  LVL2_NUM 40
#define  LVL3_WIDTH 30
#define  LVL3_HEIGHT 16
#define  LVL3_NUM 99

enum class FloorType
{
	ncNULL,				//空地
	ncUNDOWN,		    //背景方块
	ncMINE,				//地雷
	ncONE,				//数字1
	ncTWO,				//数字2
	ncTHREE,			//数字3
	ncFOUR,				//数字4
	ncFIVE,				//数字5
	ncSIX,				//数字6
	ncSEVEN,			//数字7
	ncEIGHT,			//数字8
	ncFLAG,				//标记
	ncQ,				//问号
	ncX,				//备用
	ncBOMBING,			//爆炸的雷
	ncUNFOUND			//未检测出来的雷

};

class Floor
{
private:
	FloorType m_type;
	FloorType m_AimType;
	bool isPress;
public:

};