#include "Canvas.h"

#include "PairPrediction.h"

bool PairPredictions::isPair(const Card& card1, const Card& card2) {
    return card1.getRank() == card2.getRank();
}

double PairPredictions::estimatePairProbability(int simulations) {
    int pairCount = 0;

    for (int i = 0; i < simulations; i++) {
        Deck deck;
        deck.shuffle();

        Card card1 = deck.deal();
        Card card2 = deck.deal();

        if (PairPredictions::isPair(card1, card2)) {
            pairCount++;
        }
    }

    return static_cast<double>(pairCount) / simulations;
}
double PairPredictions::estimateFlushProbability(int simulations) {
	int flushCount = 0;
	for (int i = 0; i < simulations; i++) {
		Deck deck;
		deck.shuffle();
		Card card1 = deck.deal();
		Card card2 = deck.deal();
		if (PairPredictions::isPair(card1, card2)) {
			flushCount++;
		}
	}
	return static_cast<double>(flushCount) / simulations;
}
double PairPredictions::estimateStraightProbability(int simulations) {
	int straightCount = 0;
	for (int i = 0; i < simulations; i++) {
		Deck deck;
		deck.shuffle();
		Card card1 = deck.deal();
		Card card2 = deck.deal();
		if (PairPredictions::isPair(card1, card2)) {
			straightCount++;
		}
	}
	return static_cast<double>(straightCount) / simulations;
}
double PairPredictions::estimateThreeOfAKindProbability(int simulations) {
	int threeOfAKindCount = 0;
	for (int i = 0; i < simulations; i++) {
		Deck deck;
		deck.shuffle();
		Card card1 = deck.deal();
		Card card2 = deck.deal();
		if (PairPredictions::isPair(card1, card2)) {
			threeOfAKindCount++;
		}
	}
	return static_cast<double>(threeOfAKindCount) / simulations;
}
double PairPredictions::estimateTwoPairProbability(int simulations) {
	int twoPairCount = 0;
	for (int i = 0; i < simulations; i++) {
		Deck deck;
		deck.shuffle();
		Card card1 = deck.deal();
		Card card2 = deck.deal();
		if (PairPredictions::isPair(card1, card2)) {
			twoPairCount++;
		}
	}
	return static_cast<double>(twoPairCount) / simulations;
}
double PairPredictions::estimateFullHouseProbability(int simulations) {
	int fullHouseCount = 0;
	for (int i = 0; i < simulations; i++) {
		Deck deck;
		deck.shuffle();
		Card card1 = deck.deal();
		Card card2 = deck.deal();
		if (PairPredictions::isPair(card1, card2)) {
			fullHouseCount++;
		}
	}
	return static_cast<double>(fullHouseCount) / simulations;
}
double PairPredictions::estimateFourOfAKindProbability(int simulations) {
	int fourOfAKindCount = 0;
	for (int i = 0; i < simulations; i++) {
		Deck deck;
		deck.shuffle();
		Card card1 = deck.deal();
		Card card2 = deck.deal();
		if (PairPredictions::isPair(card1, card2)) {
			fourOfAKindCount++;
		}
	}
	return static_cast<double>(fourOfAKindCount) / simulations;
}
double PairPredictions::estimateStraightFlushProbability(int simulations) {
	int straightFlushCount = 0;
	for (int i = 0; i < simulations; i++) {
		Deck deck;
		deck.shuffle();
		Card card1 = deck.deal();
		Card card2 = deck.deal();
		if (PairPredictions::isPair(card1, card2)) {
			straightFlushCount++;
		}
	}
	return static_cast<double>(straightFlushCount) / simulations;
}
double PairPredictions::estimateRoyalFlushProbability(int simulations) {
	int royalFlushCount = 0;
	for (int i = 0; i < simulations; i++) {
		Deck deck;
		deck.shuffle();
		Card card1 = deck.deal();
		Card card2 = deck.deal();
		if (PairPredictions::isPair(card1, card2)) {
			royalFlushCount++;
		}
	}
	return static_cast<double>(royalFlushCount) / simulations;
}
//Example of how to use the pair prediction
void PairPredictions::runSPairimluations() {
    const int SIMULATIONS = 25000000;  // Adjust as needed
    double probability = PairPredictions::estimatePairProbability(SIMULATIONS);
    std::cout << "Estimated probability of getting a pair in hole cards (after " << SIMULATIONS << " simulations): " << probability << std::endl;
}

LPCSTR Drawing::lpWindowName = "Poker Predictions";
ImVec2 Drawing::vWindowSize = { 750, 1000 };
ImGuiWindowFlags Drawing::WindowFlags = 0;
bool Drawing::bDraw = true;

void Drawing::Active()
{
	bDraw = true;
}

bool Drawing::isActive()
{
	return bDraw == true;
}

void Drawing::Draw()
{
	if (isActive())
	{
		ImGui::SetNextWindowSize(vWindowSize, ImGuiCond_Once);
		ImGui::SetNextWindowBgAlpha(1.0f);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{
			ImGui::Text("Poker Predictions");
			ImGui::Separator();
			ImGui::Text("Pair Prediction");
			ImGui::Separator();
			ImGui::Text("Estimated probability of getting a pair in hole cards (after 25,000 simulations): %f", PairPredictions::estimatePairProbability(25000));
			ImGui::Separator();
			ImGui::Text("Flush Prediction");
			ImGui::Separator();
			ImGui::Text("Estimated probability of getting a flush in hole cards (after 25,000 simulations): %f", PairPredictions::estimateFlushProbability(25000));
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		}
		ImGui::End();
	}

#ifdef _WINDLL
	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
#endif
}
