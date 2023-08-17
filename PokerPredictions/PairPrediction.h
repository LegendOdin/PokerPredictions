#include "Cards.h"
#include <iostream>
namespace PairPredictions {

    bool isPair(const Card& card1, const Card& card2);
    double estimatePairProbability(int simulations);
    double estimateFlushProbability(int simulations);
    double estimateStraightProbability(int simulations);
    double estimateThreeOfAKindProbability(int simulations);
    double estimateTwoPairProbability(int simulations);
    double estimateFullHouseProbability(int simulations);
    double estimateFourOfAKindProbability(int simulations);
    double estimateStraightFlushProbability(int simulations);
    double estimateRoyalFlushProbability(int simulations);

    void runSPairimluations();
}