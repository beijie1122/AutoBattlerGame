#pragma once
class Broadcaster
{

public:

	int CardsDefeatedAmt;

	int DamageDealtAmt; 

	int WinGameAmt;

	Broadcaster();

	void ResetAllValues();

	void IncrementCardsDefeatedAmt();

	void IncrementDamageDeltAmt(int Damage);

	void IncrementWinGameAmt();

	~Broadcaster();
};

