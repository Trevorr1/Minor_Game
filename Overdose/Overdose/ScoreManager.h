#pragma once
class ScoreManager
{
public:
	virtual ~ScoreManager();
	static ScoreManager &getInstance();
private:
	ScoreManager();
};

