//#include "Ground.h"
//
//namespace Tiny
//{
//	Ground* Ground::create()
//	{
//		Ground *ground = new (std::nothrow) Ground();
//		if (tiny && tiny->init())
//		{
//			tiny->autorelease();
//			return tiny;
//		}
//		CC_SAFE_DELETE(tiny);
//		return nullptr;
//	}
//}