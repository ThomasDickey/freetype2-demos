#ifndef GBLBLIT_H_
#define GBLBLIT_H_

#include "grobjs.h"
#include "gblender.h"

/*
 * blitting interface
 *
 */

typedef enum
{
  GBLENDER_SOURCE_GRAY8 = 0,
  GBLENDER_SOURCE_HRGB,
  GBLENDER_SOURCE_HBGR,
  GBLENDER_SOURCE_VRGB,
  GBLENDER_SOURCE_VBGR,
  GBLENDER_SOURCE_BGRA,

  GBLENDER_SOURCE_MAX

} GBlenderSourceFormat;


typedef enum
{
  GBLENDER_TARGET_GRAY8 = 0,
  GBLENDER_TARGET_RGB32,
  GBLENDER_TARGET_RGB24,
  GBLENDER_TARGET_RGB565,
  GBLENDER_TARGET_RGB555,

  GBLENDER_TARGET_MAX

} GBlenderTargetFormat;

typedef struct GBlenderBlitRec_*    GBlenderBlit;

typedef void  (*GBlenderBlitFunc)( GBlenderBlit   blit,
                                   GBlenderPixel  color );

typedef struct GBlenderBlitRec_
{
  int                   width;
  int                   height;
  const unsigned char*  src_line;
  int                   src_pitch;
  int                   src_x;
  int                   src_y;
  unsigned char*        dst_line;
  int                   dst_pitch;
  int                   dst_x;
  int                   dst_y;
  GBlenderSourceFormat  src_format;
  GBlenderTargetFormat  dst_format;

  GBlender              blender;
  GBlenderBlitFunc      blit_func;

} GBlenderBlitRec;


#define  gblender_blit_run(b,color)  (b)->blit_func( (b), (color) )


GBLENDER_API( int )
grBlitGlyphToSurface( grSurface*  surface,
                      grBitmap*   glyph,
                      grPos       x,
                      grPos       y,
                      grColor     color );


#endif /* GBLBLIT_H_ */
