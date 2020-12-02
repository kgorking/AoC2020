#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

int main() {
	std::ifstream input("../day_01/input.txt");

	using pair = std::pair<int, int>;
	std::unordered_set<int> single_values;
	std::unordered_map<int, pair> double_values;

	int val = 0;
	while (input >> val) {
		if (double_values.contains(2020 - val)) {
			pair p = double_values[2020 - val];
			std::cout << "result found in iteration " << single_values.size() << " : " << val * p.first * p.second << '\n';
			std::cout << val << ' ' << p.first << ' ' << p.second;
			return 0;
		}

		for (int v : single_values) {
			double_values[val + v] = pair{val, v};
		}

		single_values.insert(val);
	}
}
