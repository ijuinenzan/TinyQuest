#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "states/StateMachine.h"
#include "2d/CCSprite.h"

namespace Tiny
{
	class Actor: public cocos2d::Sprite
	{
	protected:
		StateMachine* _stateMachine;
	public:
		static Actor* create();
		static Actor* create(const std::string& filename);
		static Actor* createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame);
		static Actor* createWithSpriteFrameName(const std::string& spriteFrameName);

		void update(float delta) override;

	CC_CONSTRUCTOR_ACCESS:
		Actor();
		virtual ~Actor();

		bool init() override;
		bool initWithFile(const std::string& filename) override;
		bool initWithSpriteFrame(cocos2d::SpriteFrame* spriteFrame) override;
		bool initWithSpriteFrameName(const std::string& spriteFrameName) override;

		
	};
}


#endif //!__ACTOR_H__