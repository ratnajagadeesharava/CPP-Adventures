#pragma once

#include <mutex>
namespace CPP_Adventures {

	class Threads {
		public:
			static std::mutex BikeMutex;
		static void call_threads(const int no_of_threads);
		static void MakeForecasts();

		static void RunMutex();
	};
}
