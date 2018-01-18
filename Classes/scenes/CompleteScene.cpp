#include "CompleteScene.h"

USING_NS_CC;

Scene* CompleteScene::createScene(const float time, const int score)
{
	auto pRet = new(std::nothrow) CompleteScene();
	if (pRet && pRet->init(time, score))
	{
		pRet->autorelease();
		return pRet;
	}
	delete pRet;
	return nullptr;
}

// on "init" you need to initialize your instance
bool CompleteScene::init(const float time, const int score)
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	const auto gameCompleteLabel = Label::createWithTTF("Game complete!", "fonts/Marker Felt.ttf", 50);
	gameCompleteLabel->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2 + 100);
	this->addChild(gameCompleteLabel);

	const auto timeLabel = Label::createWithTTF("Total time: " + std::to_string(time), "fonts/Marker Felt.ttf", 50);
	timeLabel->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	this->addChild(timeLabel);

	const auto scoreLabel = Label::createWithTTF("Total score: " + std::to_string(score), "fonts/Marker Felt.ttf", 50);
	scoreLabel->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2 - 100);
	this->addChild(scoreLabel);

	return true;
}
