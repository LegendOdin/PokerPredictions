#include "Cards.h"
#include <iostream>
#include <string>


bool isSpecificCards(const Card& card1, const Card& card2, const Rank& rank1, const Rank& rank2) {
    return ((card1.getRank() == rank1 && card2.getRank() == rank2) ||
        (card1.getRank() == rank2 && card2.getRank() == rank1));
}

Rank getRankFromInput(const std::string& input) {
    if (input == "2") return Rank::TWO;
    if (input == "3") return Rank::THREE;
    if (input == "4") return Rank::FOUR;
    if (input == "5") return Rank::FIVE;
    if (input == "6") return Rank::SIX;
    if (input == "7") return Rank::SEVEN;
    if (input == "8") return Rank::EIGHT;
    if (input == "9") return Rank::NINE;
    if (input == "10") return Rank::TEN;
    if (input == "J" || input == "j") return Rank::JACK;
    if (input == "Q" || input == "q") return Rank::QUEEN;
    if (input == "K" || input == "k") return Rank::KING;
    if (input == "A" || input == "a") return Rank::ACE;
    throw std::runtime_error("Invalid card input");
}

double estimateSpecificCardsProbability(int simulations, const Rank& rank1, const Rank& rank2) {
    int specificCardsCount = 0;

    for (int i = 0; i < simulations; i++) {
        Deck deck;
        deck.shuffle();

        Card card1 = deck.deal();
        Card card2 = deck.deal();

        if (isSpecificCards(card1, card2, rank1, rank2)) {
            specificCardsCount++;
        }
    }

    return static_cast<double>(specificCardsCount) / simulations;
}