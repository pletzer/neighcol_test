/**
 * N-dimensional domain decomposition
 */

#ifndef NCL_DECOMP_HPP
#define NCL_DECOMP_HPP

#include <vector>
#include <string> // size_t

class NclDecomp {
public:
 	

NclDecomp();

~NclDecomp();

void 
setDecomposition(const std::vector<int>& domDims);

int
getProcId(const std::vector<int>& domInds);

private:
    std::vector<int> mDomDims;
    std::vector<int> mProdDims;
    size_t mNumDims;
};

#endif // NCL_DECOMP_HPP