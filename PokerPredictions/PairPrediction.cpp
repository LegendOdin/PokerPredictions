#include "Cards.h"
#include <iostream>

bool isPair(const Card& card1, const Card& card2) {
    return card1.getRank() == card2.getRank();
}

double estimatePairProbability(int simulations) {
    int pairCount = 0;

    for (int i = 0; i < simulations; i++) {
        Deck deck;
        deck.shuffle();

        Card card1 = deck.deal();
        Card card2 = deck.deal();

        if (isPair(card1, card2)) {
            pairCount++;
        }
    }

    return static_cast<double>(pairCount) / simulations;
}

//Example of how to use the pair prediction
void runSimluations() {
	const int SIMULATIONS = 25000000;  // Adjust as needed
	double probability = estimatePairProbability(SIMULATIONS);
	std::cout << "Estimated probability of getting a pair in hole cards (after " << SIMULATIONS << " simulations): " << probability << std::endl;
}