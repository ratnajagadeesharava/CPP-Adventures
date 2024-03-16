#pragma once
#include<string>
namespace CPP_Adventures {
	enum EventType {
		MOUSE_CLICK,
		MOUSE_RELEASE,
		MOUSE_SCROLL,
		MOUSE_MOVE,
		KEY_PRESS,
		KEY_RELEASE
	};
	template<typename T>
	class Event
	{
	public:
		EventType eventType;
		std::string name;
		T message;
	};

	template<typename T>
	class EventListener {
	public:
		void addEventListener(std::string name, void (*call_back)(Event<T>));
	private:
		Event<T> event;
	};

	class EventPublisher
	{
		public:
			template<typename T>
			Event<T> createEvent(EventType eventType,std::string name,T message);
			void publishEvent();
	};
}