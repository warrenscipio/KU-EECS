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

#ifndef H_Work_toplevel_structural_H
#define H_Work_toplevel_structural_H
#ifdef __MINGW32__
#include "xsimMinGW.h"
#else
#include "xsim.h"
#endif


class Work_toplevel_structural: public HSim__s6 {
public:

    HSim__s1 SE[3];

    HSim__s1 SA[1];
  char t16;
    Work_toplevel_structural(const char * name);
    ~Work_toplevel_structural();
    void constructObject();
    void constructPorts();
    void reset();
    void architectureInstantiate(HSimConfigDecl* cfg);
    virtual void vhdlArchImplement();
    int ConvFunc0(HSim__s2 * drv, const char * src, int noOfBytes, const HSimConstraints * srcConstraints);
};



HSim__s6 *createWork_toplevel_structural(const char *name);

#endif
