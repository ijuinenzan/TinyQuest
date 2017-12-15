//#ifndef __MESSENGER_H__
//#define __MESSENGER_H__
//
//#include "../arguments/BaseArgument.h"
//
//#include <string>
//#include <functional>
//#include <unordered_map>
//
//namespace Tiny
//{
//		class Messenger
//		{
//		public:
//			Messenger();
//			~Messenger();
//
//			void broadcast(const std::string& messageId, BaseArgument* argument);
//			long subscribe(const std::string& messageId, const std::function<void(BaseArgument*)>&callback);
//			void unsubscribe(const std::string& messageId, const long token);
//		private:
//			std::unordered_map<std::string, std::unordered_map<long, std::function<void(BaseArgument*)>>> _callbacks;
//
//			long _tokenCounter;
//		};
//}
//
//#endif //!__MESSENGER_H__