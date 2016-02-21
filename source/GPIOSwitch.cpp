/*
 * Copyright (c) 2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "gpio-switch/GPIOSwitch.h"
#include "gpio-pcal64/PCAL64.h"
#include "wrd-utilities/SharedModules.h"

static PCAL64 ioexpander1(YOTTA_CFG_HARDWARE_WEARABLE_REFERENCE_DESIGN_EXTERNAL_GPIO_I2C_NAME,
                          PCAL64::PRIMARY_ADDRESS,
                          YOTTA_CFG_HARDWARE_WEARABLE_REFERENCE_DESIGN_EXTERNAL_GPIO_PIN_IRQ1);

static PCAL64 ioexpander2(YOTTA_CFG_HARDWARE_WEARABLE_REFERENCE_DESIGN_EXTERNAL_GPIO_I2C_NAME,
                          PCAL64::SECONDARY_ADDRESS,
                          YOTTA_CFG_HARDWARE_WEARABLE_REFERENCE_DESIGN_EXTERNAL_GPIO_PIN_IRQ2);

void GPIOSwitch::detachAll(uint32_t pin, uint32_t location)
{
//    printf("detachAll: %lu %lu\r\n", pin, location);
}

void GPIOSwitch::read(uint32_t pin, uint32_t location, FunctionPointer1<void, int> callback)
{
    if (location == PCAL64::PRIMARY_ADDRESS)
    {
        ioexpander1.read(pin, callback);
    }
    else if (location == PCAL64::SECONDARY_ADDRESS)
    {
        ioexpander2.read(pin, callback);
    }
}

void GPIOSwitch::write(uint32_t pin, uint32_t location, int value, FunctionPointer0<void> _callback)
{
    if (location == PCAL64::PRIMARY_ADDRESS)
    {
        ioexpander1.set(pin, PCAL64::Output)
                   .set(pin, value)
                   .callback(_callback);
    }
    else if (location == PCAL64::SECONDARY_ADDRESS)
    {
        ioexpander2.set(pin, PCAL64::Output)
                   .set(pin, value)
                   .callback(_callback);
    }
}


