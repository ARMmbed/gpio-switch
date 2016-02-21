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

#ifndef __GPIO_DIGITAL_OUT_EX_H__
#define __GPIO_DIGITAL_OUT_EX_H__

#include "mbed-drivers/mbed.h"
#include "gpio-switch/GPIOSwitch.h"

using namespace mbed::util;

class DigitalOutEx
{
public:
    DigitalOutEx(uint32_t _pin, uint32_t _location = 0)
        :   pin(_pin),
            location(_location)
    {}

    void write(int value, FunctionPointer0<void> callback)
    {
        GPIOSwitch::write(pin, location, value, callback);
    }

    template <typename T>
    void write(int value, T* object, void (T::*member)(void))
    {
        GPIOSwitch::write(pin, location, value, object, member);
    }

    void read(FunctionPointer1<void, int> callback)
    {
        GPIOSwitch::read(pin, location, callback);
    }

    template <typename T>
    void read(T* object, void (T::*member)(void))
    {
        GPIOSwitch::read(pin, location, object, member);
    }

private:
    uint32_t pin;
    uint32_t location;
};

#endif // __GPIO_DIGITAL_OUT_EX_H__
