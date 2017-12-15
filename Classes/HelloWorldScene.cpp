#include "HelloWorldScene.h"
#include "characters/tiny/Tiny.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto helloWorldScene = Scene::createWithPhysics();
	helloWorldScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	helloWorldScene->getPhysicsWorld()->setGravity(Vect(0.f, -10.f));

	const auto layer = HelloWorld::create();
	helloWorldScene->addChild(layer);

    return helloWorldScene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	auto testMap = TMXTiledMap::create("Maps/Test/Map0.tmx");
	this->addChild(testMap, 0);

	auto characters = testMap->getObjectGroup("CharacterLayer");
	auto player = characters->getObject("Player");

	auto spriteTiny = Tiny::Tiny::create();
	spriteTiny->setPosition(player.at("x").asFloat(), player.at("y").asFloat());
	this->addChild(spriteTiny,1);

	const auto grounds = testMap->getObjectGroup("GroundLayer");
	auto ground = grounds->getObject("Ground0");
	auto bodyGround = cocos2d::PhysicsBody::createBox(cocos2d::Size(158, 509), cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

	bodyGround->getShape(0)->setRestitution(1.0f);
	bodyGround->getShape(0)->setFriction(0.0f);
	bodyGround->getShape(0)->setDensity(1.0f);
	bodyGround->setDynamic(false);

	auto groundNode = Node::create();
	groundNode->setPhysicsBody(bodyGround);
	groundNode->setPosition(1 + 158/2, 499 - 509/2);

	this->addChild(groundNode);

    return true;
}
