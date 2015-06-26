#include <cstdio>
#include <memory>
#include <cards.h>

int main()
{
	std::unique_ptr<cards::CCardDeck> cardDeck(new cards::CCardDeck);
	cards::CardRefs card;
	
	cardDeck->Init();
	cardDeck->Shuffle();
	
	card = cardDeck->Draw();
	std::printf("Dealed card: %s\n", cardDeck->CardToStr(card).c_str());
	std::printf("With value: %d\n", cardDeck->CardValue(card));
	
	card = cardDeck->Draw();
	std::printf("Dealing second card: %s\n", cardDeck->CardToStr(card).c_str());
	std::printf("With value: %d\n", cardDeck->CardValue(card));
	
	cardDeck->Shuffle();
	
	card = cardDeck->Draw();
	std::printf("Dealed card after reshuffle: %s\n", cardDeck->CardToStr(card).c_str());
	std::printf("With value: %d\n", cardDeck->CardValue(card));
	card = cardDeck->Draw();
	std::printf("Dealing second card after reshuffle: %s\n", cardDeck->CardToStr(card).c_str());
	std::printf("With value: %d\n", cardDeck->CardValue(card));
	
	// Deal the rest to the end of the deck.
	while(card != cards::EMPTY_DECK)
	{
		card = cardDeck->Draw();
		
		std::printf("Dealing: %s\n", cardDeck->CardToStr(card).c_str());
		std::printf("With value: %d\n", cardDeck->CardValue(card));
	}
	
	return 0;
}