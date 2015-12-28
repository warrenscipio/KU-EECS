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

#ifndef H_Work_rslatch_structural_H
#define H_Work_rslatch_structural_H
#ifdef __MINGW32__
#include "xsimMinGW.h"
#else
#include "xsim.h"
#endif


class Work_rslatch_structural: public HSim__s6 {
public:

    HSim__s1 SE[4];

    HSim__s1 SA[4];
  char t0;
  char t1;
    Work_rslatch_structural(const char * name);
    ~Work_rslatch_structural();
    void constructObject();
    void constructPorts();
    void reset();
    void architectureInstantiate(HSimConfigDecl* cfg);
    virtual void vhdlArchImplement();
};



HSim__s6 *createWork_rslatch_structural(const char *name);

#endif
