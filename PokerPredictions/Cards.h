#ifndef TEXAS_HOLDEM_DECK_H
#define TEXAS_HOLDEM_DECK_H


#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <stdexcept>

enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum class Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

class Card {
private:
    Suit suit;
    Rank rank;

public:
    __forceinline Card(Suit s, Rank r) : suit(s), rank(r) {}

    __forceinline Suit getSuit() const { return suit; }
    __forceinline Rank getRank() const { return rank; }
};

class Deck {
private:
    std::vector<Card> cards;

public:
    __forceinline Deck() {
        for (int s = static_cast<int>(Suit::HEARTS); s <= static_cast<int>(Suit::SPADES); s++) {
            for (int r = static_cast<int>(Rank::TWO); r <= static_cast<int>(Rank::ACE); r++) {
                cards.push_back(Card(static_cast<Suit>(s), static_cast<Rank>(r)));
            }
        }
    }

    __forceinline void shuffle() {
        static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        std::shuffle(cards.begin(), cards.end(), rng);
    }

    __forceinline Card deal() {
        if (cards.empty()) {
            throw std::runtime_error("Deck is empty!");
        }
        Card topCard = cards.back();
        cards.pop_back();
        return topCard;
    }

    __forceinline int size() const {
        return cards.size();
    }
};

#endif // TEXAS_HOLDEM_DECK_H