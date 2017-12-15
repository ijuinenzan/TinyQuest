//#include "Messenger.h"
//
//namespace Tiny
//{
//	Messenger::Messenger()
//		:_tokenCounter(0)
//	{
//	}
//
//	Messenger::~Messenger()
//	{
//	}
//
//	void Messenger::broadcast(const std::string& messageId, BaseArgument* argument)
//	{
//		for (const auto callback : _callbacks[messageId]) 
//		{
//			callback.second(argument);
//		}
//
//		// release args
//		if (argument) 
//		{
//			delete argument;
//		}
//	}
//
//	long Messenger::subscribe(const std::string& messageId, const std::function<void(BaseArgument*)>& callback)
//	{
//		++_tokenCounter;
//		_callbacks[messageId].emplace(_tokenCounter, callback);
//		return _tokenCounter;
//	}
//
//	void Messenger::unsubscribe(const std::string& messageId, const long token)
//	{
//		_callbacks[messageId].erase(token);
//	}
//}
