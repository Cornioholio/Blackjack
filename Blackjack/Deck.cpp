#include "Deck.h"
Deck::Deck(int noDecks) : numberOfDecks_(noDecks)
{
	deck_.reserve(cardsInDeck_ * numberOfDecks_);
	PopulateDeck();
}
Deck::~Deck() 
{
	
}

// O(n) Population of deck with suits and values. Could be O(1) but there can be multiple decks.
void Deck::PopulateDeck() 
{
	// Declare all suits and value - face pairs.
	static const std::array<std::string, 4> suits = { "Spades", "Hearts", "Clubs", "Diamonds" };
	static const std::array<std::pair<std::string, int>, 13> faceValues = { std::make_pair("Two", 2), std::make_pair("Three", 3), std::make_pair("Four", 4), std::make_pair("Five", 5), std::make_pair("Six", 6), std::make_pair("Seven", 7), std::make_pair("Eight", 8), std::make_pair("Nine", 9), std::make_pair("Ten", 10), std::make_pair("King", 10), std::make_pair("Queen", 10), std::make_pair("Jack", 10), std::make_pair("Ace", 11) };
	
	// Iterate over 4 suits and 13 face values per deck and push back to deck vector.
	for(int d = 0; d < numberOfDecks_; d++) 
	{
		for (const std::string& s : suits)
		{
			for (const auto& v : faceValues)
			{
				deck_.push_back({ s, v.first, v.second });
			}
		}
	}
}
void Deck::ShuffleDeck()
{
	if (deck_.empty()) return;

	std::random_device rd;
	std::mt19937 rng(rd());
	std::shuffle(deck_.begin(), deck_.end(), rng);
}
// O(n) again. Iterates deck vector and displays each cards suit and value
void Deck::DisplayDeck()
{
	std::cout << "!! Deck contains: " << std::endl;
	for(const auto& card : deck_) 
	{
		card.DisplayCard();
	}
}
Card Deck::DrawCard()
{
	if (deck_.empty()) return Card();

	Card drawnCard = deck_.back();
	deck_.pop_back();
	return drawnCard;
}