#include<iostream>
#include<thread>
#include<vector>
#include<string>
#include "threads.h"
#include <map>
#include<chrono>
namespace CPP_Adventures {
	void call_from(int tid) {
		std::cout << "thread from  ::  " << tid << "\n      ";
	}

	void RefreshForecast(std::map<std::string,int> wheaterMap) {
		while (true) {
			for (auto& item : wheaterMap) {
				item.second++;
				std::cout << item.first << " " << item.second << std::endl;
			}
			
			std::this_thread::sleep_for(std::chrono::milliseconds(20000));
		}
	}
	

	void Threads::call_threads(const int no_of_threads) {
		std::vector<std::thread> td;
		for (int i = 0; i < no_of_threads; i++) {
			td.push_back(std::thread(call_from, i));
		}

		// wait for all the threads to join
		for (int i = 0; i < no_of_threads; i++) {
			td[i].join();
		}
	}

	void Threads::MakeForecasts()
	{
		std::map<std::string, int> Forecast = {
			{"Hyderabad",20},
			{"Shimla",-1},
			{"Amalapuram",30},
			{"kakinada",34}
		};
		RefreshForecast(Forecast);
	}

	void DriveBike(std::string biker) {

		/*std::unique_lock<std::mutex> bikeLock(Threads::BikeMutex);
		std::cout << biker << "started Driving" <<std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << biker << "has completed a ride" << std::endl;

		bikeLock.unlock();*/
	}

	void Threads::RunMutex()
	{
		std::thread bike1(DriveBike, "Jagadeesh");
		std::thread bike2(DriveBike, "Arava");
	}

}