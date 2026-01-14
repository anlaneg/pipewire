/* Spa Volume plugin */
/* SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans */
/* SPDX-License-Identifier: MIT */

#include <errno.h>
#include <stdio.h>

#include <spa/support/plugin.h>
#include <spa/support/log.h>

extern const struct spa_handle_factory spa_bluez5_dbus_factory;
extern const struct spa_handle_factory spa_bluez5_device_factory;
extern const struct spa_handle_factory spa_media_sink_factory;
extern const struct spa_handle_factory spa_media_source_factory;
extern const struct spa_handle_factory spa_sco_sink_factory;
extern const struct spa_handle_factory spa_sco_source_factory;
extern const struct spa_handle_factory spa_a2dp_sink_factory;
extern const struct spa_handle_factory spa_a2dp_source_factory;
extern const struct spa_handle_factory spa_bluez5_midi_enum_factory;
extern const struct spa_handle_factory spa_bluez5_midi_node_factory;

SPA_LOG_TOPIC_ENUM_DEFINE_REGISTERED;

SPA_EXPORT
int spa_handle_factory_enum(const struct spa_handle_factory **factory, uint32_t *index)
{
	spa_return_val_if_fail(factory != NULL, -EINVAL);
	spa_return_val_if_fail(index != NULL, -EINVAL);

	/*通过index获取其对应的factory,当index中对应的值没有对应的factory时，函数返回0*/
	switch (*index) {
	case 0:
		*factory = &spa_bluez5_dbus_factory;
		break;
	case 1:
		*factory = &spa_bluez5_device_factory;
		break;
	case 2:
		*factory = &spa_media_sink_factory;
		break;
	case 3:
		*factory = &spa_media_source_factory;
		break;
	case 4:
		*factory = &spa_sco_sink_factory;
		break;
	case 5:
		*factory = &spa_sco_source_factory;
		break;
	case 6:
		*factory = &spa_a2dp_sink_factory;
		break;
	case 7:
		*factory = &spa_a2dp_source_factory;
		break;
	case 8:
		*factory = &spa_bluez5_midi_enum_factory;
		break;
	case 9:
		*factory = &spa_bluez5_midi_node_factory;
		break;
	default:
		return 0;/*其它的均返回0*/
	}
	(*index)++;/*索引增加*/
	return 1;/*返回1，表示已设置*/
}
