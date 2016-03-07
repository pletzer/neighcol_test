/**
 * Local array
 */

#ifndef NCL_LOCAL_ARRAY_HPP
#define NCL_LOCAL_ARRAY_HPP

#include <vector>
#include <string> // size_t

class NclLocalArray {
public:
 	

NclLocalArray();

~NclLocalArray();

void 
setDimensions(const std::vector<size_t>& dims);

void
setStartIndices(const std::vector<size_t>& startInds);

void 
setBox(const std::vector<double>& lo, 
	   const std::vector<double>& hi);

std::vector<double>
getPointCoordinates(const std::vector<size_t>& inds);

private:
    std::vector<size_t> mDims;
    std::vector<size_t> mStartInds;
    std::vector<double> mLo;
    std::vector<double> mHi;
    std::vector<double> mPoint;
    size_t mNumDims;
};

#endif // NCL_LOCAL_ARRAY_HPP