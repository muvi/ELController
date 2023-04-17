/*
 * user_settings.h
 *
 * Created: 2/18/2023 5:06:45 PM
 *  Author: Christian
 */ 


#ifndef USER_SETTINGS_H_
#define USER_SETTINGS_H_

typedef union {
	struct {
		uint16_t dmx_address;
	};
	uint8_t buffer;
} UserSettings;

UserSettings userSettings;

static inline void user_settings_save() {
	_rww_flash_write(&(FLASH_0.dev), NVMCTRL_RWW_EEPROM_ADDR, &(userSettings.buffer), sizeof(userSettings));
}

static inline void user_settings_load() {
	_rww_flash_read(&(FLASH_0.dev), NVMCTRL_RWW_EEPROM_ADDR, &(userSettings.buffer), sizeof(userSettings));
}

#endif /* USER_SETTINGS_H_ */