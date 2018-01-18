#ifndef __COMPLETE_SCENE_H__
#define __COMPLETE_SCENE_H__

#include "cocos2d.h"

class CompleteScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene(const float time, const int score);

	bool init(const float time, const int score);
private:
};

#endif //!__COMPLETE_SCENE_H__
