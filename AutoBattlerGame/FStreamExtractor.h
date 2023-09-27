#pragma once
#include <string>
#include <vector>
#include <fstream>

class FStreamExtractor
{
public:

	std::string FStreamFileCardInfo = "CardInfo.txt";

	FStreamExtractor();

	~FStreamExtractor();

	void FStreamCardDataExtraction(std::string FStreamInput, std::vector<std::string>& CardNameVec, std::vector<int>& CardHPVec, std::vector<int>& CardATTVec);


};

