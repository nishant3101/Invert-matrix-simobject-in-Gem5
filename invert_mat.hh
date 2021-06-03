#ifndef __ASS2_INVERT_MAT_HH__
#define __ASS2_INVERT_MAT_HH__

#include "params/InvertMat.hh"
#include "sim/sim_object.hh"

class InvertMat : public SimObject
{
	  public:
		      InvertMat(InvertMatParams *p);
};

#endif // __ASS2_INVERT_MAT_HH__
