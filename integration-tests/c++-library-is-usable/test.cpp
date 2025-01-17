// Copyright 2023 Vincent Jacques

#include <iostream>

#include <lincs.hpp>


int main() {
  lincs::Problem problem{
    {
      {"Physics grade", lincs::Criterion::ValueType::real, lincs::Criterion::CategoryCorrelation::growing},
      {"Literature grade", lincs::Criterion::ValueType::real, lincs::Criterion::CategoryCorrelation::growing},
    },
    {
      {"Bad"},
      {"Good"},
    }
  };

  problem.dump(std::cout);

  std::cout << "\n";

  lincs::Model model{problem, {{{10.f, 10.f}, {lincs::SufficientCoalitions::weights, {0.4f, 0.7f}}}}};
  model.dump(problem, std::cout);

  std::cout << "\n";

  lincs::Alternatives alternatives{problem, {{"Alice", {11.f, 12.f}, 1}, {"Bob", {9.f, 11.f}, 0}}};
  alternatives.dump(problem, std::cout);
}
