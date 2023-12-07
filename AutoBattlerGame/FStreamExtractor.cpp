#include "FStreamExtractor.h"

FStreamExtractor::FStreamExtractor()
{

}

FStreamExtractor::~FStreamExtractor()
{

}

void FStreamExtractor::FStreamCardDataExtraction(std::string FStreamInput, std::vector<std::string>& CardNameVec, std::vector<int>& CardHPVec, std::vector<int>& CardATTVec, std::vector<std::string>& CardTypeVec)
{
	std::string CardName;
	int CardHP;
	int CardATT;
	std::string CardType;

	std::ifstream in_file;
	in_file.open(FStreamInput);
	if (!in_file)
	{
		return;
	}
	else
	{
		while (in_file >> CardName >> CardHP >> CardATT >> CardType)
		{
			CardNameVec.push_back(CardName);
			CardHPVec.push_back(CardHP);
			CardATTVec.push_back(CardATT);
			CardTypeVec.push_back(CardType);
		}
	}

	in_file.close();

}

