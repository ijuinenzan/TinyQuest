#include "MapScene.h"
#include "characters/tiny/Tiny.h"

USING_NS_CC;

Scene* MapScene::createScene(const std::string& mapResourceName)
{
	auto pRet = new(std::nothrow) MapScene(); 
	if (pRet && pRet->init(mapResourceName))
	{ 
		pRet->autorelease(); 
		auto helloWorldScene = createWithPhysics();
		helloWorldScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
		helloWorldScene->getPhysicsWorld()->setGravity(Vect(0.f, -10.f));

		helloWorldScene->addChild(pRet);
		return helloWorldScene;
	}
	delete pRet;
	return nullptr;
}

// on "init" you need to initialize your instance
bool MapScene::init(const std::string& mapResourceName)
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	const auto map = TMXTiledMap::create(mapResourceName);
	this->addChild(map, 0);

	const auto characters = map->getObjectGroup("PlayerObject");
	auto player = characters->getObject("Player");

	auto spriteTiny = Tiny::Tiny::create();
	spriteTiny->setPosition(player.at("x").asFloat(), player.at("y").asFloat());
	this->addChild(spriteTiny,1);

	const auto grounds = map->getObjectGroup("GroundObject");

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
