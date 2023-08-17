#include "Cards.h"
#include <iostream>
#include <string>
namespace MonteCarlo {
    //Monte Carlo Prediction of Poker Hands//Needs to be optimized for speed and higher count of simulations Single Hand
    bool isSpecificCards(const Card& card1, const Card& card2, const Rank& rank1, const Rank& rank2) {
        return ((card1.getRank() == rank1 && card2.getRank() == rank2) ||
            (card1.getRank() == rank2 && card2.getRank() == rank1));
    }

    //2 Hands
    bool isTwoHandSpecifiedCards(const Card& card1, const Card& card2, const Card& card3, const Card& card4, const Rank& rank1, const Rank& rank2, const Rank& rank3, const Rank& rank4) {
        return ((card1.getRank() == rank1 && card2.getRank() == rank2) ||
            (card1.getRank() == rank2 && card2.getRank() == rank1)) &&
            ((card3.getRank() == rank3 && card4.getRank() == rank4) ||
                (card3.getRank() == rank4 && card4.getRank() == rank3));
    }

    Rank getRankFromInput(const std::string& input) {
        if (input == "2" || input == "two") return Rank::TWO;
        if (input == "3" || input == "three") return Rank::THREE;
        if (input == "4" || input == "four") return Rank::FOUR;
        if (input == "5" || input == "five") return Rank::FIVE;
        if (input == "6" || input == "six") return Rank::SIX;
        if (input == "7" || input == "seven") return Rank::SEVEN;
        if (input == "8" || input == "eight") return Rank::EIGHT;
        if (input == "9" || input == "nine") return Rank::NINE;
        if (input == "10" || input == "ten") return Rank::TEN;
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
    //Example of how to use the Monte Carlo Simulation
    void runSimluations() {
        const int SIMULATIONS = 25000000;  // Adjust as needed
        std::string card1Input, card2Input;
        std::cout << "Enter your first hole card (e.g., A, K, Q, J, 10, ... 2): ";
        std::cin >> card1Input;
        std::cout << "Enter your second hole card (e.g., A, K, Q, J, 10, ... 2): ";
        std::cin >> card2Input;

        Rank rank1 = getRankFromInput(card1Input);
        Rank rank2 = getRankFromInput(card2Input);

        double probability = estimateSpecificCardsProbability(SIMULATIONS, rank1, rank2);
        std::cout << "Estimated probability of getting [" << card1Input << ", " << card2Input << "] in hole cards (after " << SIMULATIONS << " simulations): " << probability << std::endl;
    }
}