/*
 *  Tvheadend - NetCeiver DVB input
 *
 *  Copyright (C) 2013-2018 Sven Wegener
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "tvheadend.h"
#include "netceiver_private.h"
#include "input.h"
#include "settings.h"

#include <unistd.h>


/*
 * NetCeiver Hardware
 */

static idnode_set_t *netceiver_hardware_class_get_childs(idnode_t *in)
{
  return idnode_find_all(&netceiver_frontend_class, NULL);
}

static void netceiver_hardware_class_get_title(idnode_t *in, const char *lang, char *dst, size_t dstsize)
{
  snprintf(dst, dstsize, "%s", tvh_gettext_lang(lang, N_("NetCeiver")));
}

static const idclass_t netceiver_hardware_class = {
  .ic_class      = "netceiver_hardware",
  .ic_caption    = N_("NetCeiver"),
  .ic_get_title  = netceiver_hardware_class_get_title,
  .ic_get_childs = netceiver_hardware_class_get_childs,
  .ic_properties = (const property_t[]) {
    {},
  },
};

static tvh_hardware_t netceiver_hardware;

void netceiver_hardware_init(void)
{
  idclass_register(&netceiver_hardware_class);
  tvh_hardware_create0(&netceiver_hardware, &netceiver_hardware_class, NULL, NULL);
}

/******************************************************************************
 * Editor Configuration
 *
 * vim:sts=2:ts=2:sw=2:et
 *****************************************************************************/
