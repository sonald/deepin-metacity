/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */

/**
 * Copyright (C) 2015 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

#ifndef _DEEPIN_DBUS_SERVICE_H_
#define _DEEPIN_DBUS_SERVICE_H_

#include <gtk/gtk.h>
#include "deepin-dbus-wm.h"

G_BEGIN_DECLS

#define DEEPIN_TYPE_DBUS_SERVICE             (deepin_dbus_service_get_type ())
#define DEEPIN_DBUS_SERVICE(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEEPIN_TYPE_DBUS_SERVICE, DeepinDBusService))
#define DEEPIN_DBUS_SERVICE_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DEEPIN_TYPE_DBUS_SERVICE, DeepinDBusServiceClass))
#define DEEPIN_IS_DBUS_SERVICE(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEEPIN_TYPE_DBUS_SERVICE))
#define DEEPIN_IS_DBUS_SERVICE_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DEEPIN_TYPE_DBUS_SERVICE))
#define DEEPIN_DBUS_SERVICE_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DEEPIN_TYPE_DBUS_SERVICE, DeepinDBusServiceClass))

typedef struct _DeepinDBusServiceClass DeepinDBusServiceClass;
typedef struct _DeepinDBusService DeepinDBusService;
typedef struct _DeepinDBusServicePrivate DeepinDBusServicePrivate;


struct _DeepinDBusServiceClass
{
	DeepinDBusWmSkeletonClass parent_class;
};

struct _DeepinDBusService
{
	DeepinDBusWmSkeleton parent_instance;

	DeepinDBusServicePrivate *priv;
};

GType deepin_dbus_service_get_type (void) G_GNUC_CONST;
DeepinDBusService* deepin_dbus_service_get();

G_END_DECLS

#endif /* _DEEPIN_DBUS_SERVICE_H_ */

