#include <vector>
#include <string>
#include <cmath>

bool isQuark(int pdg) {
  int apdg = std::abs(pdg);
  return (apdg >= 1 && apdg <= 6);
}

std::string quarkName(int pdg) {
  int apdg = std::abs(pdg);
  switch (apdg) {
  case 1: return "down";
  case 2: return "up";
  case 3: return "strange";
  case 4: return "charm";
  case 5: return "bottom";
  case 6: return "top";
  default: return "unknown";
  }
}

std::vector<int> getPrimaryQuarkIndices(
                                        const std::vector<int>* pdgVec,
                                        const std::vector<std::vector<int>>* motherIdx)
{
  std::vector<int> eventIndices;
  if (!pdgVec || !motherIdx) return eventIndices;

  size_t n = pdgVec->size();
  for (size_t j = 0; j < n; ++j) {
    int pdg = pdgVec->at(j);
    if (!isQuark(pdg)) continue;
    if (j >= motherIdx->size()) continue;

    const auto& moms = motherIdx->at(j);
    if (moms.size() < 4) continue;

    int m0 = moms[0], m1 = moms[1], g0 = moms[2], g1 = moms[3];
    if (m0 < 0 || m1 < 0 || g0 < 0 || g1 < 0) continue;
    if (static_cast<size_t>(m0) >= n || static_cast<size_t>(m1) >= n) continue;
    if (static_cast<size_t>(g0) >= n || static_cast<size_t>(g1) >= n) continue;
    if (pdgVec->at(m0) != 22 || pdgVec->at(m1) != 22) continue;
    if (std::abs(pdgVec->at(g0)) != 2212 || std::abs(pdgVec->at(g1)) != 2212) continue;

    eventIndices.push_back(static_cast<int>(j));
  }

  return eventIndices;
}
