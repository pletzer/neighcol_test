#include "NclDecomp.hpp"

NclDecomp::NclDecomp() {
    mNumDims = 0;
}

NclDecomp::~NclDecomp() {
}

void 
NclDecomp::setDecomposition(const std::vector<int>& domDims) {
    mDomDims = domDims;
    mNumDims = domDims.size();
    mProdDims.resize(mNumDims, 1);
    for (size_t i = 1; i < mNumDims; ++i) {
        mProdDims[i] = mProdDims[i - 1] * mDomDims[i - 1];
    }
}

int
NclDecomp::getProcId(const std::vector<int>& domInds) {
    int res = 0;
    for (size_t i = 0; i < mNumDims; ++i) {
        res += mProdDims[i] * (domInds[i] % mDomDims[i]);
    }
    return res;
}
