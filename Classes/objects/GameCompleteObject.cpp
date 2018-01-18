#include "GameCompleteObject.h"
#include <Define.h>
#include "scenes/MapScene.h"
#include "scenes/CompleteScene.h"

namespace Tiny
{
	GameCompleteObject* GameCompleteObject::create(const cocos2d::Vec2& position, const cocos2d::Size& size)
	{
		GameCompleteObject *ground = new (std::nothrow) GameCompleteObject();
		if (ground && ground->init(position, size))
		{
			ground->autorelease();
			return ground;
		}
		CC_SAFE_DELETE(ground);
		return nullptr;
	}

	GameCompleteObject::GameCompleteObject()
	{
	}

	GameCompleteObject::~GameCompleteObject()
	{
	}

	bool GameCompleteObject::init(const cocos2d::Vec2& position, const cocos2d::Size& size)
	{
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

			if (a == nullptr || b == nullptr)
			{
				return false;
			}

			if ((a->getTag() == TINY_TAG && b->getTag() == COMPLETE_TAG) || (b->getTag() == TINY_TAG && a->getTag() == COMPLETE_TAG))
			{
				const auto currentScene = static_cast<MapScene*>(this->getParent());
				cocos2d::Director::getInstance()->replaceScene(CompleteScene::createScene(currentScene->getElapsedTime(), currentScene->getScore()));
				return false;
			}
			return true;
		};

		_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

		this->setTag(COMPLETE_TAG);

		this->setPhysicsBody(body);
		body->setContactTestBitmask(0x000001);

		this->setPosition(position);

		return true;
	}
}
