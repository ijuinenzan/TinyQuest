#ifndef __MAP_SCENE_H__
#define __MAP_SCENE_H__

#include "cocos2d.h"

class MapScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene(const std::string& mapResourceName, const float elapsedTime, const int score);

	bool init(const std::string& mapResourceName, const float elapsedTime, const int score);

	void update(float dt);

	float getElapsedTime() const;
	int getScore() const;
private:
	float _elapsedTime;
	int _score;

	cocos2d::Label* _timeLabel;

	cocos2d::Label* _scoreLabel;
};

#endif //!__MAP_SCENE_H__
