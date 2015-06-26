#include <cstdio>
#include <chrono>
#include <random>
#include <cmath>
#include <functional>
#include <cards.h>

namespace cards
{
	void CCardDeck::Init()
	{
		std::puts("Initializing default sorted deck...");
		
		CardRefs cardRefs;
		
		deck.clear();
		
		for(int i = SPADES_A; i != EMPTY_DECK; i++)
		{
			deck.push_back(static_cast<CardRefs>(i));
		}
		
		std::printf("Deck size: %lu\n", deck.size());
		
		// Set up strings for card enums.
		cardString[SPADES_A] = "SPADES_A";
		cardString[SPADES2] = "SPADES2";
		cardString[SPADES3] = "SPADES3";
		cardString[SPADES4] = "SPADES4";
		cardString[SPADES5] = "SPADES5";
		cardString[SPADES6] = "SPADES6";
		cardString[SPADES7] = "SPADES7";
		cardString[SPADES8] = "SPADES8";
		cardString[SPADES9] = "SPADES9";
		cardString[SPADES10] = "SPADES10";
		cardString[SPADES_J] = "SPADES_J";
		cardString[SPADES_Q] = "SPADES_Q";
		cardString[SPADES_K] = "SPADES_K";
		cardString[CLUBS_A] = "CLUBS_A";
		cardString[CLUBS2] = "CLUBS2";
		cardString[CLUBS3] = "CLUBS3";
		cardString[CLUBS4] = "CLUBS4";
		cardString[CLUBS5] = "CLUBS5";
		cardString[CLUBS6] = "CLUBS6";
		cardString[CLUBS7] = "CLUBS7";
		cardString[CLUBS8] = "CLUBS8";
		cardString[CLUBS9] = "CLUBS9";
		cardString[CLUBS10] = "CLUBS10";
		cardString[CLUBS_J] = "CLUBS_J";
		cardString[CLUBS_Q] = "CLUBS_Q";
		cardString[CLUBS_K] = "CLUBS_K";
		cardString[HEARTS_A] = "HEARTS_A";
		cardString[HEARTS2] = "HEARTS2";
		cardString[HEARTS3] = "HEARTS3";
		cardString[HEARTS4] = "HEARTS4";
		cardString[HEARTS5] = "HEARTS5";
		cardString[HEARTS6] = "HEARTS6";
		cardString[HEARTS7] = "HEARTS7";
		cardString[HEARTS8] = "HEARTS8";
		cardString[HEARTS9] = "HEARTS9";
		cardString[HEARTS10] = "HEARTS10";
		cardString[HEARTS_J] = "HEARTS_J";
		cardString[HEARTS_Q] = "HEARTS_Q";
		cardString[HEARTS_K] = "HEARTS_K";
		cardString[DIAMONDS_A] = "DIAMONDS_A";
		cardString[DIAMONDS2] = "DIAMONDS2";
		cardString[DIAMONDS3] = "DIAMONDS3";
		cardString[DIAMONDS4] = "DIAMONDS4";
		cardString[DIAMONDS5] = "DIAMONDS5";
		cardString[DIAMONDS6] = "DIAMONDS6";
		cardString[DIAMONDS7] = "DIAMONDS7";
		cardString[DIAMONDS8] = "DIAMONDS8";
		cardString[DIAMONDS9] = "DIAMONDS9";
		cardString[DIAMONDS10] = "DIAMONDS10";
		cardString[DIAMONDS_J] = "DIAMONDS_J";
		cardString[DIAMONDS_Q] = "DIAMONDS_Q";
		cardString[DIAMONDS_K] = "DIAMONDS_K";		
	}
	
	int CCardDeck::_GetRandomCardPos()
	{
		std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
		std::chrono::system_clock::duration periods = tp.time_since_epoch();			
		
		// Seed 64-bit Mersenne Twister
		std::mt19937_64::result_type seed = periods.count();
		
		// Generate rand.
		auto deckPos = std::bind(std::uniform_int_distribution<int>(0, deck.size() - 1), std::mt19937_64(seed));
		
		return deckPos();		
	}
	
	void CCardDeck::Shuffle()
	{
		std::puts("Shuffling deck...");
		
		CardRefs cardValA, cardValB;
				
		auto randIterations = std::pow(deck.size(), 3);	
		
		for(int j = 0; j < randIterations; j++)
		{
			int posA = _GetRandomCardPos();
			cardValA = deck[posA];
			
			int posB = _GetRandomCardPos();
			cardValB = deck[posB];
			
			// Swap values
			deck[posA] = cardValB;
			deck[posB] = cardValA;
		}
		
		for(int i = SPADES_A; i != EMPTY_DECK; i++)
		{
			std::printf("%s\n", CardToStr(deck[i]).c_str());
		}
		
		std::printf("Shuffled deck size: %lu\n", deck.size());		
	}
	
	CardRefs CCardDeck::Draw()
	{
		if(deck.empty())
		{
			std::puts("Attempted to deal but deck is empty.");
			return EMPTY_DECK;
		}
		
		std::puts("Dealing card...");
		CardRefs currentCard = deck[0];
		
		// Remove top card from deck.
		deck.pop_front();
		
		return currentCard;
	}
	
	std::string CCardDeck::CardToStr(const CardRefs card) const
	{
		auto strCard = cardString.find(card);
		
		if(strCard == cardString.end())
			return "<INVALID CARD IN DECK>";
		else
			return strCard->second;
	}
	
	int CCardDeck::CardValue(const CardRefs card) const
	{
		// Example scoring. Could also be changed to read from an XML file too maybe.
		// That is on my todo list.
		switch(card)
		{
			case SPADES_A:
			case CLUBS_A:
			case HEARTS_A:
			case DIAMONDS_A:
				return 21;
			case SPADES2:
			case CLUBS2:
			case HEARTS2:
			case DIAMONDS2:
				return 2;
			case SPADES3:
			case CLUBS3:
			case HEARTS3:
			case DIAMONDS3:
				return 3;
			case SPADES4:
			case CLUBS4:
			case HEARTS4:
			case DIAMONDS4:
				return 4;
			case SPADES5:
			case CLUBS5:
			case HEARTS5:
			case DIAMONDS5:
				return 5;
			case SPADES6:
			case CLUBS6:
			case HEARTS6:
			case DIAMONDS6:
				return 6;
			case SPADES7:
			case CLUBS7:
			case HEARTS7:
			case DIAMONDS7:
				return 7;
			case SPADES8:
			case CLUBS8:
			case HEARTS8:
			case DIAMONDS8:
				return 8;
			case SPADES9:
			case CLUBS9:
			case HEARTS9:
			case DIAMONDS9:
				return 9;
			case SPADES10:
			case CLUBS10:
			case HEARTS10:
			case DIAMONDS10:
				return 10;
			case SPADES_J:
			case CLUBS_J:
			case HEARTS_J:
			case DIAMONDS_J:
				return 11;
			case SPADES_Q:
			case CLUBS_Q:
			case HEARTS_Q:
			case DIAMONDS_Q:
				return 12;
			case SPADES_K:
			case CLUBS_K:
			case HEARTS_K:
			case DIAMONDS_K:
				return 13;
			case EMPTY_DECK:
				return 0;
			default:
				return 0;
		}		
		
	}
}