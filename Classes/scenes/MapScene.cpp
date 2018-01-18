#include "MapScene.h"
#include "characters/tiny/Tiny.h"
#include <Define.h>
#include "objects/Ground.h"
#include "objects/NextLevelObject.h"
#include "objects/Trap.h"
#include "objects/Platform.h"
#include "objects/Wall.h"
#include "objects/Enemy.h"
#include "objects/GameCompleteObject.h"
#include "objects/Coin.h"

USING_NS_CC;

Scene* MapScene::createScene(const std::string& mapResourceName, const float elapsedTime, const int score)
{
	auto pRet = new(std::nothrow) MapScene(); 
	if (pRet && pRet->init(mapResourceName, elapsedTime, score))
	{ 
		pRet->autorelease(); 
		auto helloWorldScene = createWithPhysics();
		helloWorldScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
		helloWorldScene->getPhysicsWorld()->setGravity(GRAVITY);

		helloWorldScene->addChild(pRet);
		return helloWorldScene;
	}
	delete pRet;
	return nullptr;
}

// on "init" you need to initialize your instance
bool MapScene::init(const std::string& mapResourceName, const float elapsedTime, const int score)
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	_elapsedTime = elapsedTime;
	_score = score;

	const auto map = TMXTiledMap::create(mapResourceName);
	this->addChild(map, 0);

	const auto characters = map->getObjectGroup("PlayerObject");
	auto player = characters->getObject("Player");

	auto spriteTiny = Tiny::Tiny::create(Vec2(player.at("x").asFloat(), player.at("y").asFloat()));
	this->addChild(spriteTiny,1);

	const auto grounds = map->getObjectGroup("GroundObject");
	if(grounds != NULL)
	{
		for (auto ground : grounds->getObjects())
		{
			auto groundValues = ground.asValueMap();

			const auto groundNode = Tiny::Ground::create(Vec2(groundValues.at("x").asFloat() + groundValues.at("width").asFloat() / 2, groundValues.at("y").asFloat() + groundValues.at("height").asFloat() / 2),
				Size(groundValues.at("width").asFloat(), groundValues.at("height").asFloat()));
			this->addChild(groundNode);
		}
	}

	const auto enemys = map->getObjectGroup("FireEnemy");
	if (enemys != NULL)
	{
		for (auto enemy : enemys->getObjects())
		{
			auto enemyValues = enemy.asValueMap();

			const auto enemyNode = Tiny::Enemy::create(Vec2(enemyValues.at("x").asFloat() + enemyValues.at("width").asFloat() / 2, enemyValues.at("y").asFloat() + enemyValues.at("height").asFloat() / 2));
			this->addChild(enemyNode);
		}
	}

	const auto walls = map->getObjectGroup("WallObject");
	if (walls != NULL)
	{
		for (auto wall : walls->getObjects())
		{
			auto wallValues = wall.asValueMap();

			const auto wallNode = Tiny::Wall::create(Vec2(wallValues.at("x").asFloat() + wallValues.at("width").asFloat() / 2, wallValues.at("y").asFloat() + wallValues.at("height").asFloat() / 2),
				Size(wallValues.at("width").asFloat(), wallValues.at("height").asFloat()));
			this->addChild(wallNode);
		}
	}

	const auto coins = map->getObjectGroup("CoinObject");
	if (coins != NULL)
	{
		for (auto coin : coins->getObjects())
		{
			auto wallValues = coin.asValueMap();

			const auto coinNode = Tiny::Coin::create(Vec2(wallValues.at("x").asFloat() + wallValues.at("width").asFloat() / 2, wallValues.at("y").asFloat() + wallValues.at("height").asFloat() / 2));
			this->addChild(coinNode);
		}
	}

	const auto platforms = map->getObjectGroup("PlatformObject");
	if (platforms != NULL)
	{
		for (auto platform : platforms->getObjects())
		{
			auto platformValues = platform.asValueMap();

			const auto platformNode = Tiny::Platform::create(Vec2(platformValues.at("x").asFloat() + platformValues.at("width").asFloat() / 2, platformValues.at("y").asFloat() + platformValues.at("height").asFloat() / 2),
				Size(platformValues.at("width").asFloat(), platformValues.at("height").asFloat()), platformValues.at("min_x").asFloat(), platformValues.at("max_x").asFloat());
			this->addChild(platformNode);
		}
	}

	const auto nextLevels = map->getObjectGroup("NextLevelObject");
	if(nextLevels != NULL)
	{
		for (auto nextLevel : nextLevels->getObjects())
		{
			auto nextLevelValues = nextLevel.asValueMap();

			const auto nextLevelNode = Tiny::NextLevelObject::create(Vec2(nextLevelValues.at("x").asFloat() + nextLevelValues.at("width").asFloat() / 2, nextLevelValues.at("y").asFloat() + nextLevelValues.at("height").asFloat() / 2),
				Size(nextLevelValues.at("width").asFloat(), nextLevelValues.at("height").asFloat()), nextLevelValues.at("NextMapName").asString());
			this->addChild(nextLevelNode);
		}
	}

	const auto gameCompletes = map->getObjectGroup("GameCompleteObject");
	if (gameCompletes != NULL)
	{
		for (auto gameComplete : gameCompletes->getObjects())
		{
			auto gameCompleteValues = gameComplete.asValueMap();

			const auto gameCompleteNode = Tiny::GameCompleteObject::create(Vec2(gameCompleteValues.at("x").asFloat() + gameCompleteValues.at("width").asFloat() / 2, gameCompleteValues.at("y").asFloat() + gameCompleteValues.at("height").asFloat() / 2),
				Size(gameCompleteValues.at("width").asFloat(), gameCompleteValues.at("height").asFloat()));
			this->addChild(gameCompleteNode);
		}
	}

	const auto traps = map->getObjectGroup("TrapObject");
	if (traps != NULL)
	{
		for (auto trap : traps->getObjects())
		{
			auto trapValues = trap.asValueMap();


			const auto trapNode = Tiny::Trap::create(Vec2(trapValues.at("x").asFloat() + trapValues.at("width").asFloat() / 2, trapValues.at("y").asFloat() + trapValues.at("height").asFloat() / 2),
				Size(trapValues.at("width").asFloat(), trapValues.at("height").asFloat()));
			this->addChild(trapNode);
		}
	}

	auto contactListener = cocos2d::EventListenerPhysicsContact::create();
	contactListener->onContactBegin = [=](cocos2d::PhysicsContact& contact)
	{
		auto a = contact.getShapeA()->getBody()->getNode();
		auto b = contact.getShapeB()->getBody()->getNode();
		if(a== NULL || b== NULL)
		{
			return true;
		}
		if (a->getTag() == BULLET_TAG && b->getTag() == COIN_TAG
			|| a->getTag() == COIN_TAG && b->getTag() == BULLET_TAG)
		{
			return false;
		}
		if (a->getTag() == TINY_TAG && b->getTag() == COIN_TAG)
		{
			_score += 1;
			_scoreLabel->setString("Score: " + std::to_string(_score));
			b->removeFromParent();
			return false;
		}

		if(b->getTag() == TINY_TAG && a->getTag() == COIN_TAG)
		{
			_score += 1;
			_scoreLabel->setString("Score: " + std::to_string(_score));
			a->removeFromParent();
			return false;
		}

		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);


	_timeLabel = Label::createWithTTF(std::to_string(_elapsedTime), "fonts/Marker Felt.ttf", 30);
	_timeLabel->setPosition(Director::getInstance()->getVisibleSize().width - 100, Director::getInstance()->getVisibleSize().height - 100);
	_timeLabel->setTextColor(Color4B::RED);

	_scoreLabel = Label::createWithTTF("Score: " + std::to_string(_score), "fonts/Marker Felt.ttf", 30);
	_scoreLabel->setPosition(100, Director::getInstance()->getVisibleSize().height - 100);
	_scoreLabel->setTextColor(Color4B::RED);

	this->addChild(_scoreLabel);
	this->addChild(_timeLabel);

	this->scheduleUpdate();



    return true;
}

void MapScene::update(float dt)
{
	_elapsedTime += dt;
	_timeLabel->setString(std::to_string(_elapsedTime));
}

float MapScene::getElapsedTime() const
{
	return _elapsedTime;
}

int MapScene::getScore() const
{
	return _score;
}
