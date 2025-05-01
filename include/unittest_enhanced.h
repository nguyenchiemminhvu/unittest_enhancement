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