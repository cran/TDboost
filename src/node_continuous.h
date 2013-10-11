//------------------------------------------------------------------------------
//  by Greg Ridgeway  Copyright (C) 2003
//
//  File:       node_continuous.h
//
//  License:    GNU GPL (version 2 or later)
//
//  Contents:   a node with a continuous split
//        	  
//  Owner:      gregr.rand.org
//
//  History:    3/26/2001   gregr created
//              2/14/2003   gregr: adapted for R implementation
//
//------------------------------------------------------------------------------

#ifndef NODECONTINUOUS_H
#define NODECONTINUOUS_H

#include <float.h>
#include "node_nonterminal.h"

class CNodeContinuous : public CNodeNonterminal
{
public:

    CNodeContinuous();
    ~CNodeContinuous();

    TDboostRESULT PrintSubtree(unsigned long cIndent);
    TDboostRESULT TransferTreeToRList(int &iNodeID,
                                CDataset *pData,
                                int *aiSplitVar,
                                double *adSplitPoint,
                                int *aiLeftNode,
                                int *aiRightNode,
                                int *aiMissingNode,
                                double *adErrorReduction,
                                double *adWeight,
                                double *adPred,
                                VEC_VEC_CATEGORIES &vecSplitCodes,
                                int cCatSplitsOld,
                                double dShrinkage);

    signed char WhichNode(CDataset *pData,
                          unsigned long iObs);
    signed char WhichNode(double *adX,
                          unsigned long cRow,
                          unsigned long cCol,
                          unsigned long iRow);

    TDboostRESULT RecycleSelf(CNodeFactory *pNodeFactory);

    double dSplitValue;
};

typedef CNodeContinuous *PCNodeContinuous;

#endif // NODECONTINUOUS_H



