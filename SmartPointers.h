#pragma once
#include<memory>
namespace CPP_Adventures{
class SmartPointers
{
	std::unique_ptr<int> unptr1 = std::make_unique<int>(100);
	//throws error
	//std::unique_ptr<int> unptr2 = unptr1;
	// we are moving owenrship of unptr1 to unptr2
	//unptr will become null
	std::unique_ptr<int> unptr2 = std::move(unptr1);
public:
	SmartPointers();
	~SmartPointers();
};}

