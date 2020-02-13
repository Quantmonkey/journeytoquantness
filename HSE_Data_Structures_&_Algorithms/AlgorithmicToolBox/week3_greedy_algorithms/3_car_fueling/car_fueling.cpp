#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int numRefills = 0; // Contain number of refills we have already made
    int currentRefills = 0; // Current position

    stops.insert(stops.begin(), 0); // Adds the beginning of the journey, 0
    stops.push_back(dist);

    while (currentRefills <= stops.size() - 1) { // While have not yet visited all the stops, index in the array is at most n (the last stop)

        // We want to try to go as far as possible
        int lastRefill = currentRefills; // Saving our position of last refill in current refill: We made our last refill at the position current refill

        // We want to get to either our destination or get to the right most gas station and refill there
        while ((currentRefills <= stops.size() - 1) && // While there is still a gas station to go to and we haven't yet reached our destination (stops.size())
               (tank >= (stops[currentRefills + 1] - stops[lastRefill]))) { // And our tank and go as far as possible without refilling
            currentRefills = currentRefills + 1; // Shows how many stops we can go pass without refueling
        }
        // After exiting this while loop, we're either at our journey end or the farthest reachable gas station

        // If the farthest reachable gas station is the gas station we started
        if (currentRefills == lastRefill) { // It means there was no stop we could have gotten to to refill
            return -1;
        }

        // If we are at a different gas station and not yet at the destination
        if (currentRefills <= stops.size() - 1) {
            numRefills = numRefills + 1; // It means we can refill at this furthest gas station and continue travelling until we have visited all the stops
        }
    }

    return numRefills;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
