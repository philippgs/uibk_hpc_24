#include <chrono>
#include <iostream>
#include <string>
#include <vector>

constexpr std::size_t output_resolution = 128;

using Datatype = double;
using Domain = std::vector<Datatype>;

void printTemperature(const Domain &domain);

int verifyTemperature(const Domain &domain);

int main(int argc, char **argv) {

	std::size_t size_domain = 2048;
	std::size_t timesteps = 50000;
	if(argc > 1) {
		size_domain = std::stoul(argv[1]);
		if(argc > 2) {
			timesteps = std::stoul(argv[2]);
		}
	}

	std::cout << "Computing heat-distribution for room size N=" << size_domain << " for T=" << timesteps << std::endl;

	Domain domain_a = Domain(size_domain, 273.0);
	const std::size_t source_x = size_domain / 2;

	std::cout << "Heat Source is at " << source_x << std::endl;
	domain_a[source_x] = 273 + 60;

	std::cout << "Initial:\t";
	printTemperature(domain_a);
	std::cout << std::endl;

	Domain domain_b = Domain(size_domain, 273.0);

	std::chrono::time_point<std::chrono::system_clock> time_start, time_end;

	time_start = std::chrono::system_clock::now();

	for (std::size_t t = 0; t < timesteps; t++) {

		for (std::size_t x = 1; x < size_domain - 1; x++) {
			if (x == source_x) {
				domain_b[x] = domain_a[x];
				continue;
			}

			Datatype value_left = domain_a[x - 1];
			Datatype value_center = domain_a[x];
			Datatype value_right = domain_a[x + 1];

			domain_b[x] = value_center + 0.2 * (value_left + value_right + (-2.0 * value_center));
		}

		std::swap(domain_a, domain_b);

		if ((t % 10000) == 0) {
			std::cout << "Step t=" << t << "\t";
			printTemperature(domain_a);
			std::cout << std::endl;
		}
	}

	time_end = std::chrono::system_clock::now();
	const std::chrono::duration<double> elapsed_seconds = time_end - time_start;

	std::cout << "\t\t";
	printTemperature(domain_a);
	std::cout << std::endl;
	int verification_result = EXIT_SUCCESS;
	verification_result = verifyTemperature(domain_a);
	std::cout << "Computation took " << elapsed_seconds.count() << " seconds" << std::endl;

	return verification_result;
}

void printTemperature(const Domain &domain) {
	const std::string colors = " .-:=+*^X#%@";

	constexpr Datatype max = 273 + 30;
	constexpr Datatype min = 273 + 0;

	// step size in each dimension
	const std::size_t step_size = domain.size() / output_resolution;

	// left border
	std::cout << "X";

	for (std::size_t i = 0; i < output_resolution; i++) {

		// get max temperature in this tile
		Datatype cur_max = 0;
		for (std::size_t x = step_size * i; x < step_size * i + step_size; x++) {
			cur_max = (cur_max < domain[x]) ? domain[x] : cur_max;
		}
		Datatype temp = cur_max;

		// pick the 'color'
		int c = ((temp - min) / (max - min)) * colors.length();
		c = (c >= static_cast<int>(colors.length())) ? colors.length() - 1 : ((c < 0) ? 0 : c);

		// print the average temperature
		std::cout << colors[c];
	}

	// right border
	std::cout << "X";
}

int verifyTemperature(const Domain &domain) {
	for (std::size_t x = 0; x < domain.size(); x++) {
		if (domain[x] < 273.0 || domain[x] > 273.0 + 60) {
			std::cout << "Verification failed, grid[" << x << "]=" << domain[x] << std::endl;
			return EXIT_FAILURE;
		}
	}
	std::cout << "Verification succeeded" << std::endl;
	return EXIT_SUCCESS;
}
