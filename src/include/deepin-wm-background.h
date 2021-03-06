/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */

/**
 * Copyright (C) 2015 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

#ifndef _DEEPIN_WM_BACKGROUND_H_
#define _DEEPIN_WM_BACKGROUND_H_

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <gtk/gtk.h>
#include <prefs.h>
#include "types.h"
#include "../core/workspace.h"

G_BEGIN_DECLS

#define DEEPIN_TYPE_WM_BACKGROUND             (deepin_wm_background_get_type ())
#define DEEPIN_WM_BACKGROUND(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEEPIN_TYPE_WM_BACKGROUND, DeepinWMBackground))
#define DEEPIN_WM_BACKGROUND_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DEEPIN_TYPE_WM_BACKGROUND, DeepinWMBackgroundClass))
#define DEEPIN_IS_WM_BACKGROUND(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEEPIN_TYPE_WM_BACKGROUND))
#define DEEPIN_IS_WM_BACKGROUND_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DEEPIN_TYPE_WM_BACKGROUND))
#define DEEPIN_WM_BACKGROUND_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DEEPIN_TYPE_WM_BACKGROUND, DeepinWMBackgroundClass))

typedef struct _DeepinWMBackgroundClass DeepinWMBackgroundClass;
typedef struct _DeepinWMBackground DeepinWMBackground;
typedef struct _DeepinWMBackgroundPrivate DeepinWMBackgroundPrivate;


struct _DeepinWMBackgroundClass
{
	GtkWindowClass parent_class;
};

struct _DeepinWMBackground
{
	GtkWindow parent_instance;

	DeepinWMBackgroundPrivate *priv;
};

GType deepin_wm_background_get_type (void) G_GNUC_CONST;
GtkWidget* deepin_wm_background_new(MetaScreen* screen);
void deepin_wm_background_handle_event(DeepinWMBackground* self, XIDeviceEvent* event,
        KeySym keysym, MetaKeyBindingAction action);
void deepin_wm_background_switch_workspace(DeepinWMBackground* self, 
        MetaWorkspace* next);
void deepin_wm_background_setup(DeepinWMBackground* self);

G_END_DECLS

#endif /* _DEEPIN_WM_BACKGROUND_H_ */

