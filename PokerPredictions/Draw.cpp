#include "Canvas.h"

#include "PairPrediction.h"

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
void runSPairimluations() {
    const int SIMULATIONS = 25000000;  // Adjust as needed
    double probability = estimatePairProbability(SIMULATIONS);
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
			ImGui::Text("Estimated probability of getting a pair in hole cards (after 25,000 simulations): %f", estimatePairProbability(25000));

			ImGui::Separator();

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		}
		ImGui::End();
	}

#ifdef _WINDLL
	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
#endif
}
