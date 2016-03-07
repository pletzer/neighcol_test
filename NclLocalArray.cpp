#include "NclLocalArray.hpp"

NclLocalArray::NclLocalArray() {
    mNumDims = 0;
}

NclLocalArray::~NclLocalArray() {
}


void 
NclLocalArray::setDimensions(const std::vector<size_t>& dims) {
    mDims = dims;
    mNumDims = dims.size();
}

void
NclLocalArray::setStartIndices(const std::vector<size_t>& startInds) {
    mStartInds = startInds;
}

void 
NclLocalArray::setBox(const std::vector<double>& lo, 
	                  const std::vector<double>& hi) {
    mLo = lo;
    mHi = hi;
}

std::vector<double>
NclLocalArray::getPointCoordinates(const std::vector<size_t>& inds) {
    std::vector<double> point(mNumDims);
    for (size_t i = 0; i < mNumDims; ++i) {
        point[i] = mLo[i] + (mHi[i] - mLo[i])*inds[i]/double(mDims[i]);
    }
    return point;
}
