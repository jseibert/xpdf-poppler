//========================================================================
//
// CoreOutputDev.h
//
// Copyright 2004 Glyph & Cog, LLC
//
//========================================================================

#ifndef COREOUTPUTDEV_H
#define COREOUTPUTDEV_H

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include "poppler/splash/SplashTypes.h"
#include "poppler/SplashOutputDev.h"

class TextPage;

//------------------------------------------------------------------------

typedef void (*CoreOutRedrawCbk)(void *data, int x0, int y0, int x1, int y1,
				 bool composited);

//------------------------------------------------------------------------
// CoreOutputDev
//------------------------------------------------------------------------

class CoreOutputDev: public SplashOutputDev {
public:

  CoreOutputDev(SplashColorMode colorModeA, int bitmapRowPadA,
		bool reverseVideoA, SplashColorPtr paperColorA,
		bool incrementalUpdateA,
		CoreOutRedrawCbk redrawCbkA,
		void *redrawCbkDataA);

  virtual ~CoreOutputDev();

  //----- initialization and control

  // End a page.
  virtual void endPage();

  // Dump page contents to display.
  virtual void dump();

  //----- special access

  // Clear out the document (used when displaying an empty window).
  void clear();

private:

  bool incrementalUpdate;      // incrementally update the display?
  CoreOutRedrawCbk redrawCbk;
  void *redrawCbkData;
};

#endif
