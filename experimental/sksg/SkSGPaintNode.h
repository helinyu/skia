/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkSGPaintNode_DEFINED
#define SkSGPaintNode_DEFINED

#include "SkSGNode.h"

#include "SkPaint.h"

namespace sksg {

/**
 * Base class for nodes which provide a 'paint' (as opposed to geometry) for
 * drawing (e.g. colors, gradients, patterns).
 *
 * Roughly equivalent to Skia's SkPaint.
 */
class PaintNode : public Node {
public:
    const SkPaint& makePaint();

    SG_ATTRIBUTE(AntiAlias  , bool          , fAntiAlias  )
    SG_ATTRIBUTE(StrokeWidth, SkScalar      , fStrokeWidth)
    SG_ATTRIBUTE(StrokeMiter, SkScalar      , fStrokeMiter)
    SG_ATTRIBUTE(Style      , SkPaint::Style, fStyle      )
    SG_ATTRIBUTE(StrokeJoin , SkPaint::Join , fStrokeJoin )
    SG_ATTRIBUTE(StrokeCap  , SkPaint::Cap  , fStrokeCap  )

protected:
    PaintNode();

    virtual void onApplyToPaint(SkPaint*) const = 0;

    void onRevalidate(InvalidationController*, const SkMatrix&) override;

private:
    SkPaint        fPaint;

    SkScalar       fStrokeWidth = 1,
                   fStrokeMiter = 4;
    bool           fAntiAlias   = false;
    SkPaint::Style fStyle       = SkPaint::kFill_Style;
    SkPaint::Join  fStrokeJoin  = SkPaint::kMiter_Join;
    SkPaint::Cap   fStrokeCap   = SkPaint::kButt_Cap;

    typedef Node INHERITED;
};

} // namespace sksg

#endif // SkSGGeometryNode_DEFINED