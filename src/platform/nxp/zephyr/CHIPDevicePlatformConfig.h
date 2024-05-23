/*
 *
 *    Copyright (c) 2024 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *          Platform-specific configuration overrides for the chip Device Layer
 *          on Zephyr platform.
 */

#pragma once

#include "autoconf.h"

// ==================== Platform Adaptations ====================

#define CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID CONFIG_CHIP_DEVICE_VENDOR_ID
#define CHIP_DEVICE_CONFIG_DEVICE_VENDOR_NAME CONFIG_CHIP_DEVICE_VENDOR_NAME
#define CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID CONFIG_CHIP_DEVICE_PRODUCT_ID
#define CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_NAME CONFIG_CHIP_DEVICE_PRODUCT_NAME
#define CHIP_DEVICE_CONFIG_DEFAULT_DEVICE_HARDWARE_VERSION CONFIG_CHIP_DEVICE_HARDWARE_VERSION
#define CHIP_DEVICE_CONFIG_DEFAULT_DEVICE_HARDWARE_VERSION_STRING CONFIG_CHIP_DEVICE_HARDWARE_VERSION_STRING
#define CHIP_DEVICE_CONFIG_DEVICE_SOFTWARE_VERSION CONFIG_CHIP_DEVICE_SOFTWARE_VERSION
#define CHIP_DEVICE_CONFIG_DEVICE_SOFTWARE_VERSION_STRING CONFIG_CHIP_DEVICE_SOFTWARE_VERSION_STRING
#define CHIP_DEVICE_CONFIG_TEST_MANUFACTURING_DATE CONFIG_CHIP_DEVICE_MANUFACTURING_DATE
#define CHIP_DEVICE_CONFIG_TEST_SERIAL_NUMBER CONFIG_CHIP_DEVICE_SERIAL_NUMBER
#define CHIP_DEVICE_CONFIG_DEVICE_TYPE CONFIG_CHIP_DEVICE_TYPE
#define CHIP_DEVICE_CONFIG_USE_TEST_SETUP_DISCRIMINATOR CONFIG_CHIP_DEVICE_DISCRIMINATOR
#define CHIP_DEVICE_CONFIG_USE_TEST_SETUP_PIN_CODE CONFIG_CHIP_DEVICE_SPAKE2_PASSCODE
#define CHIP_DEVICE_CONFIG_USE_TEST_SPAKE2P_ITERATION_COUNT CONFIG_CHIP_DEVICE_SPAKE2_IT
#define CHIP_DEVICE_CONFIG_USE_TEST_SPAKE2P_SALT CONFIG_CHIP_DEVICE_SPAKE2_SALT
#define CHIP_DEVICE_CONFIG_USE_TEST_SPAKE2P_VERIFIER CONFIG_CHIP_DEVICE_SPAKE2_TEST_VERIFIER

#ifdef CONFIG_NET_L2_OPENTHREAD
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD CONFIG_NET_L2_OPENTHREAD
#else
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD 0
#endif

#ifdef CONFIG_CHIP_WIFI
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI CONFIG_CHIP_WIFI
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_STATION 1
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_AP 0
#else
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI 0
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_STATION 0
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_AP 0
#endif

#ifdef CONFIG_BT
#define CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE CONFIG_BT
#else
#define CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE 0
#endif

// ========== Platform-specific Configuration =========

// These are configuration options that are unique to Zephyr platforms.
// These can be overridden by the application as needed.

#ifndef CHIP_DEVICE_CONFIG_SETTINGS_KEY
/// Key for all Matter persistent data stored using the Zephyr Settings API
#define CHIP_DEVICE_CONFIG_SETTINGS_KEY "mt"
#endif // CHIP_DEVICE_CONFIG_SETTINGS_KEY

#ifndef CHIP_DEVICE_CONFIG_OTA_REQUESTOR_REBOOT_DELAY_MS
/// Delay between completing a firmware update download and reboot to apply the update
#define CHIP_DEVICE_CONFIG_OTA_REQUESTOR_REBOOT_DELAY_MS 1000
#endif // CHIP_DEVICE_CONFIG_OTA_REQUESTOR_REBOOT_DELAY_MS

#ifndef CHIP_DEVICE_CONFIG_SERVER_SHUTDOWN_ACTIONS_SLEEP_MS
/// Time to sleep after running server shutdown actions to let lower layers complete the actions.
/// This may include transmitting packets created by the actions.
#define CHIP_DEVICE_CONFIG_SERVER_SHUTDOWN_ACTIONS_SLEEP_MS 500
#endif // CHIP_DEVICE_CONFIG_SERVER_SHUTDOWN_ACTIONS_SLEEP_MS

#ifndef CHIP_DEVICE_CONFIG_HEAP_STATISTICS_MALLINFO
#if !defined(CONFIG_CHIP_MALLOC_SYS_HEAP) && defined(CONFIG_NEWLIB_LIBC)
/// Use mallinfo() to obtain the heap usage statistics exposed by SoftwareDiagnostics cluster attributes.
#define CHIP_DEVICE_CONFIG_HEAP_STATISTICS_MALLINFO 1
#else
#define CHIP_DEVICE_CONFIG_HEAP_STATISTICS_MALLINFO 0
#endif // !defined(CONFIG_CHIP_MALLOC_SYS_HEAP) && defined(CONFIG_NEWLIB_LIBC)
#endif // CHIP_DEVICE_CONFIG_HEAP_STATISTICS_MALLINFO

#ifndef CHIP_DEVICE_BLE_ADVERTISING_PRIORITY
/// Priority of the Matter BLE advertising when there are multiple application
/// components that compete for the BLE advertising.
#define CHIP_DEVICE_BLE_ADVERTISING_PRIORITY 0
#endif // CHIP_DEVICE_BLE_ADVERTISING_PRIORITY

// ========== Platform-specific Configuration Overrides =========

#ifndef CHIP_DEVICE_CONFIG_CHIP_TASK_PRIORITY
#define CHIP_DEVICE_CONFIG_CHIP_TASK_PRIORITY (K_PRIO_PREEMPT(5))
#endif // CHIP_DEVICE_CONFIG_CHIP_TASK_PRIORITY

#ifndef CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE
#define CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE 8192
#endif // CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE

#define CHIP_DEVICE_CONFIG_MAX_EVENT_QUEUE_SIZE 64

#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_TELEMETRY 0
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY 0
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY_FULL 0

#define CHIP_DEVICE_CONFIG_CHIPOBLE_ENABLE_ADVERTISING_AUTOSTART 0

#ifndef CONFIG_CHIP_ENABLE_PAIRING_AUTOSTART
#define CHIP_DEVICE_CONFIG_ENABLE_PAIRING_AUTOSTART 0
#else
#define CHIP_DEVICE_CONFIG_ENABLE_PAIRING_AUTOSTART CONFIG_CHIP_ENABLE_PAIRING_AUTOSTART
#endif // CONFIG_CHIP_ENABLE_PAIRING_AUTOSTART

#ifdef CONFIG_CHIP_ENABLE_DNSSD_SRP
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_SRP_CLIENT 1
#ifdef CONFIG_CHIP_ENABLE_DNS_CLIENT
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_DNS_CLIENT 1
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_COMMISSIONABLE_DISCOVERY 1
#endif // CONFIG_CHIP_ENABLE_DNS_CLIENT
#endif // CONFIG_CHIP_ENABLE_DNSSD_SRP

#if defined(CONFIG_CHIP_ENABLE_ICD_SUPPORT) && defined(CONFIG_CHIP_THREAD_SSED)
#define CHIP_DEVICE_CONFIG_THREAD_SSED CONFIG_CHIP_THREAD_SSED
#else
#define CHIP_DEVICE_CONFIG_THREAD_SSED 0
#endif // defined(CONFIG_CHIP_ENABLE_ICD_SUPPORT) && defined(CONFIG_CHIP_THREAD_SSED)

#ifndef CHIP_DEVICE_CONFIG_ICD_SLOW_POLL_INTERVAL
#ifdef CONFIG_CHIP_ICD_SLOW_POLL_INTERVAL
#define CHIP_DEVICE_CONFIG_ICD_SLOW_POLL_INTERVAL chip::System::Clock::Milliseconds32(CONFIG_CHIP_ICD_SLOW_POLL_INTERVAL)
#endif // CONFIG_CHIP_ICD_SLOW_POLL_INTERVAL
#endif // CHIP_DEVICE_CONFIG_ICD_SLOW_POLL_INTERVAL

#ifndef CHIP_DEVICE_CONFIG_ICD_FAST_POLL_INTERVAL
#ifdef CONFIG_CHIP_ICD_FAST_POLLING_INTERVAL
#define CHIP_DEVICE_CONFIG_ICD_FAST_POLL_INTERVAL chip::System::Clock::Milliseconds32(CONFIG_CHIP_ICD_FAST_POLLING_INTERVAL)
#endif // CONFIG_CHIP_ICD_FAST_POLLING_INTERVAL
#endif // CHIP_DEVICE_CONFIG_ICD_FAST_POLL_INTERVAL

#ifdef CONFIG_CHIP_COMMISSIONABLE_DEVICE_TYPE
#define CHIP_DEVICE_CONFIG_ENABLE_COMMISSIONABLE_DEVICE_TYPE 1
#endif // CONFIG_CHIP_COMMISSIONABLE_DEVICE_TYPE

#ifdef CONFIG_CHIP_EXTENDED_DISCOVERY
#define CHIP_DEVICE_CONFIG_ENABLE_EXTENDED_DISCOVERY 1
#endif // CONFIG_CHIP_EXTENDED_DISCOVERY

#ifndef CHIP_DEVICE_CONFIG_ROTATING_DEVICE_ID_UNIQUE_ID_LENGTH
#ifdef CONFIG_CHIP_FACTORY_DATA
// UID will be copied from the externally programmed factory data, so we don't know the actual length and we need to assume some max
// boundary.
#define CHIP_DEVICE_CONFIG_ROTATING_DEVICE_ID_UNIQUE_ID_LENGTH CONFIG_CHIP_FACTORY_DATA_ROTATING_DEVICE_UID_MAX_LEN
#else
// UID will be copied from hex encoded Kconfig option, so we may calculate its length in bytes by subtracting null terminator and
// dividing size by 2.
#define CHIP_DEVICE_CONFIG_ROTATING_DEVICE_ID_UNIQUE_ID_LENGTH ((sizeof(CONFIG_CHIP_DEVICE_ROTATING_DEVICE_UID) - 1) / 2)
#endif // CONFIG_CHIP_FACTORY_DATA
#endif // CHIP_DEVICE_CONFIG_ROTATING_DEVICE_ID_UNIQUE_ID_LENGTH

#include <platform/nxp/common/CHIPDeviceNXPPlatformDefaultConfig.h>
