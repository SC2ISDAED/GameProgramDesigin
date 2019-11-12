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
	ncNULL,				//�յ�
	ncUNDOWN,		    //��������
	ncMINE,				//����
	ncONE,				//����1
	ncTWO,				//����2
	ncTHREE,			//����3
	ncFOUR,				//����4
	ncFIVE,				//����5
	ncSIX,				//����6
	ncSEVEN,			//����7
	ncEIGHT,			//����8
	ncFLAG,				//���
	ncQ,				//�ʺ�
	ncX,				//����
	ncBOMBING,			//��ը����
	ncUNFOUND			//δ����������

};

class Floor
{
private:
	FloorType m_type;
	FloorType m_AimType;
	bool isPress;
public:

};