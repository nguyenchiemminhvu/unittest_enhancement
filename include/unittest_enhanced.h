/**
 * MIT License
 * 
 * Copyright (c) 2025 nguyenchiemminhvu@gmail.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <unordered_map>
#include <iostream>

#undef PRIVATE
#undef PROTECTED
#undef PUBLIC

#ifdef __UNITTEST__
    #define PRIVATE public
    #define PROTECTED public
    #define PUBLIC public
#else
    #define PRIVATE private
    #define PROTECTED protected
    #define PUBLIC public
#endif // __UNITTEST__

class unittest_enhanced
{
#ifdef __UNITTEST__
public:
    enum TEST_SLOT_TYPES
    {
        FORCE_RETURN_NULL,
        FORCE_RETURN_TRUE,
        FORCE_RETURN_FALSE,
        FORCE_RETURN_ZERO,
        BAD_ALLOC,
        OUT_OF_RANGE,
        INVALID_ARGUMENT,
        LOGIC_ERROR,
        RUNTIME_ERROR,
        LENGTH_ERROR,
        DOMAIN_ERROR,
        OVERFLOW_ERROR,
        UNDERFLOW_ERROR,
        RANGE_ERROR,
        INVALID_POINTER,
        FILE_NOT_FOUND,
        PERMISSION_DENIED,
        CONNECTION_FAILED,
        TIMEOUT_ERROR,
        UNKNOWN_ERROR,
        EXCEPTION_COUNT // Total number of exception types
    };

    unittest_enhanced() {}
    virtual ~unittest_enhanced() {}

    // Set the number of test slots for a specific exception type
    void set_test_slot(TEST_SLOT_TYPES exceptionType, int count)
    {
        m_exception_flags[exceptionType] = count;
    }

    // Check if the test slot is available (reduce count and return true if it reaches 0)
    bool acquire_test_slot(TEST_SLOT_TYPES exceptionType)
    {
        auto it = m_exception_flags.find(exceptionType);
        if (it != m_exception_flags.end() && it->second > 0)
        {
            --(it->second);
            if (it->second == 0)
            {
                return true;
            }
        }
        return false;
    }

    // Reset all test slots
    void reset_all_test_slots()
    {
        m_exception_flags.clear();
    }

private:
    std::unordered_map<TEST_SLOT_TYPES, int> m_exception_flags;
#endif // __UNITTEST__
};