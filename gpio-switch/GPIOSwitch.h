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

#ifndef __GPIO_SWITCH_H__
#define __GPIO_SWITCH_H__

#include "mbed-drivers/mbed.h"

using namespace mbed::util;

namespace GPIOSwitch {

    template <typename T>
    void rise(uint32_t pin, uint32_t location, T* object, void (T::*member)(void))
    {
//        printf("rise: %lu %lu\r\n", pin, location);
    }

    template <typename T>
    void fall(uint32_t pin, uint32_t location, T* object, void (T::*member)(void))
    {
//        printf("fall: %lu %lu\r\n", pin, location);
    }

    void detachAll(uint32_t pin, uint32_t location);



    void write(uint32_t pin, uint32_t location, int value, FunctionPointer0<void> callback);

    template <typename T>
    void write(uint32_t pin, uint32_t location, int value, T* object, void (T::*member)(void))
    {
        FunctionPointer0<void> fp(object, member);
        write(pin, location, value, fp);
    }

    void read(uint32_t pin, uint32_t location, FunctionPointer1<void, int> callback);

    template <typename T>
    void read(uint32_t pin, uint32_t location, T* object, void (T::*member)(void))
    {
        FunctionPointer1<void, int> fp(object, member);
        read(pin, location, fp);
    }
}

#endif // __GPIO_SWITCH_H__
