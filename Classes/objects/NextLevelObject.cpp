#include "NextLevelObject.h"
#include <Define.h>
#include "scenes/MapScene.h"

namespace Tiny
{
	NextLevelObject* NextLevelObject::create(const cocos2d::Vec2& position, const cocos2d::Size& size, const std::string &nextMapName)
	{
		NextLevelObject *ground = new (std::nothrow) NextLevelObject();
		if (ground && ground->init(position, size, nextMapName))
		{
			ground->autorelease();
			return ground;
		}
		CC_SAFE_DELETE(ground);
		return nullptr;
	}

	NextLevelObject::NextLevelObject()
	{
	}

	NextLevelObject::~NextLevelObject()
	{
	}

	bool NextLevelObject::init(const cocos2d::Vec2& position, const cocos2d::Size& size, const std::string &nextMapName)
	{
		_nextMapName = nextMapName;
		auto body = cocos2d::PhysicsBody::createBox(size, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

		body->getShape(0)->setRestitution(0.0f);
		body->getShape(0)->setFriction(0.0f);
		body->getShape(0)->setDensity(1.0f);
		body->setRotationEnable(false);
		body->setDynamic(false);
		
		auto contactListener = cocos2d::EventListenerPhysicsContact::create();

		contactListener->onContactBegin = [=](cocos2d::PhysicsContact& contact) {
			auto a = contact.getShapeA()->getBody()->getNode();
			auto b = contact.getShapeB()->getBody()->getNode();

			if(a == nullptr || b == nullptr)
			{
				return false;
			}
			
			if((a->getTag() == TINY_TAG && b->getTag() == CHECKPOINT_TAG) || (b->getTag() == TINY_TAG && a->getTag() == CHECKPOINT_TAG))
			{
				const auto currentScene = static_cast<MapScene*>(this->getParent());
				cocos2d::Director::getInstance()->replaceScene(MapScene::createScene(_nextMapName, currentScene->getElapsedTime(), currentScene->getScore()));
				return false;
			}
			return true;
		};

		_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

		this->setTag(CHECKPOINT_TAG);

		this->setPhysicsBody(body);
		body->setContactTestBitmask(0x000001);

		this->setPosition(position);

		return true;
	}
}
