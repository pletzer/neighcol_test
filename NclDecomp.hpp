/**
 * N-dimensional domain decomposition
 */

#ifndef NCL_DECOMP_HPP
#define NCL_DECOMP_HPP

#include <vector>

class NclDecomp {
public:
 	

NclDecomp();

~NclDecomp();

void 
setDecomposition(const std::vector<size_t>& domDims);

int
getProcId(const std::vector<size_t>& domInds);

private:
    std::vector<size_t> mDomDims;
};

#endif // NCL_DECOMP_HPP