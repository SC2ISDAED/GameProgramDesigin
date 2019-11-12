#pragma once
enum class  GameState
{
	Gaming,
	GamePause,
	GameOver,
	GameWin,
	GameInitialize
};
enum class GameStage
{
	Stage1,
	Stage2,
	Stage3,
	Stage4,
	Stage5,
	Boss
};
class GameModeData
{
public:
	bool BisGameOver;
	unsigned int Score;
	unsigned int gameRate;
	unsigned int gameSpeed;
};