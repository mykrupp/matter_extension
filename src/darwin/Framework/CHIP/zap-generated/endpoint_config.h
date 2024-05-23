/*
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
 * This file is only here to satisfy includes in core files that expect an
 * endpoint config.  This file is NOT generated by ZAP, and provides the bare
 * minimum information needed to allow things to compile.
 *
 * TO DO: This needs a better setup.
 */
#include <app/util/endpoint-config-defines.h>

/**
 * We don't have any fixed endpoints.
 */
#define FIXED_ENDPOINT_COUNT 0

/**
 * We don't have any attributes not implemented by AttributeAccessInterface. But
 * using 0 here does not work, so just claim 1.
 */
#define ATTRIBUTE_LARGEST 1

#define GENERATED_ATTRIBUTES {}

