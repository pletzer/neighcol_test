/**
 * Input class
 */

#ifndef NCL_INPUT_HPP
#define NCL_INPUT_HPP

#include <vector>

class NclInput {
public:
 	

NclInput();

~NclInput();


void 
setLocalDimensions(const std::vector<size_t>& localDims);

void 
setDomainDecomposition(const std::vector<size_t>& decomp);

void 
setPeriodicity(const std::vector<int>& periods);

void 
setDomainBox(const std::vector<double>& lo, 
	         const std::vector<double>& hi);

const std::vector<double> 
getPointCoordinates(const std::vector<size_t>& inds);

const std::vector<size_t> 
getGlobalDimensions() const;
 
private:
    std::vector<size_t> mLocalDims;
    std::vector<size_t> mDecomp;
    std::vector<size_t> mPeriods;
    std::vector<double> mLo;
    std::vector<double> mHi;
};

#endif // NCL_INPUT_HPP