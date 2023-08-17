#pragma once

#include <algorithm>
#include <math.h>
#include <vector>

namespace NashEquilibrium {
	struct Hand {
		int rank1;
		int rank2;
		bool suited;
		bool operator==(const Hand& other) const {
			return rank1 == other.rank1 && rank2 == other.rank2 && suited == other.suited;
		}
	};
	struct HandRange {
		std::vector<Hand> hands;
		bool operator==(const HandRange& other) const {
			return hands == other.hands;
		}
	};
	struct Action {
		double raise;
		double call;
		double fold;
		bool operator==(const Action& other) const {
			return raise == other.raise && call == other.call && fold == other.fold;
		}
	};
	struct Node {
		Action action;
		bool terminal;
		bool operator==(const Node& other) const {
			return action == other.action && terminal == other.terminal;
		}
	};
	struct InformationSet {
		std::vector<Node> nodes;
		bool operator==(const InformationSet& other) const {
			return nodes == other.nodes;
		}
	};
	struct Game {
		std::vector<InformationSet> informationSets;
		bool operator==(const Game& other) const {
			return informationSets == other.informationSets;
		}
	};
	struct Strategy {
		std::vector<double> probabilities;
		bool operator==(const Strategy& other) const {
			return probabilities == other.probabilities;
		}
	};
	struct Result {
		double ev;
		double sd;
		bool operator==(const Result& other) const {
			return ev == other.ev && sd == other.sd;
		}
	};
	struct ResultWithHand {
		Hand hand;
		Result result;
		bool operator==(const ResultWithHand& other) const {
			return hand == other.hand && result == other.result;
		}
	};
	struct ResultWithHandRange {
		HandRange handRange;
		Result result;
		bool operator==(const ResultWithHandRange& other) const {
			return handRange == other.handRange && result == other.result;
		}
	};
	struct ResultWithHandRangeAndAction {
		HandRange handRange;
		Action action;
		Result result;
		bool operator==(const ResultWithHandRangeAndAction& other) const {
			return handRange == other.handRange && action == other.action && result == other.result;
		}
	};
	struct ResultWithHandAndAction {};
}