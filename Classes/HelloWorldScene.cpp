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

	const auto testMap = TMXTiledMap::create("Maps/Level1.tmx");
	this->addChild(testMap, 0);

	const auto characters = testMap->getObjectGroup("PlayerObject");
	auto player = characters->getObject("Player");

	auto spriteTiny = Tiny::Tiny::create();
	spriteTiny->setPosition(player.at("x").asFloat(), player.at("y").asFloat());
	this->addChild(spriteTiny,1);

	const auto grounds = testMap->getObjectGroup("GroundObject");

	for(auto ground: grounds->getObjects())
	{
		auto groundNode = Node::create();

		auto groundValues = ground.asValueMap();

		auto bodyGround = PhysicsBody::createBox(Size(groundValues.at("width").asFloat(), groundValues.at("height").asFloat()), PHYSICSBODY_MATERIAL_DEFAULT);

		bodyGround->getShape(0)->setRestitution(0.0f);
		bodyGround->getShape(0)->setFriction(0.0f);
		bodyGround->getShape(0)->setDensity(1.0f);
		bodyGround->setRotationEnable(false);
		bodyGround->setDynamic(false);

		groundNode->setPhysicsBody(bodyGround);
		bodyGround->setContactTestBitmask(0x000001);
		groundNode->setPosition(groundValues.at("x").asFloat() + groundValues.at("width").asFloat() / 2, groundValues.at("y").asFloat() + groundValues.at("height").asFloat() / 2);
		this->addChild(groundNode);
	}

    return true;
}
