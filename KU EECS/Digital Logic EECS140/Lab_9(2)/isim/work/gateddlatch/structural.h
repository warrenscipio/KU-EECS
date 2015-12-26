////////////////////////////////////////////////////////////////////////////////
//   ____  ____   
//  /   /\/   /  
// /___/  \  /   
// \   \   \/  
//  \   \        Copyright (c) 2003-2004 Xilinx, Inc.
//  /   /        All Right Reserved. 
// /---/   /\     
// \   \  /  \  
//  \___\/\___\
////////////////////////////////////////////////////////////////////////////////

#ifndef H_Work_gateddlatch_structural_H
#define H_Work_gateddlatch_structural_H
#ifdef __MINGW32__
#include "xsimMinGW.h"
#else
#include "xsim.h"
#endif


class Work_gateddlatch_structural: public HSim__s6 {
public:

    HSim__s1 SE[3];

    HSim__s1 SA[4];
  char t0;
  char t1;
    Work_gateddlatch_structural(const char * name);
    ~Work_gateddlatch_structural();
    void constructObject();
    void constructPorts();
    void reset();
    void architectureInstantiate(HSimConfigDecl* cfg);
    virtual void vhdlArchImplement();
};



HSim__s6 *createWork_gateddlatch_structural(const char *name);

#endif
