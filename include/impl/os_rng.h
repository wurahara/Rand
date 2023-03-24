#ifndef RAND_OS_H
#define RAND_OS_H

#include "core/rng.h"

namespace rng::impl {

/**
 * @brief The <tt>OsRng</tt> class is a random number generator that uses the operating system's random number generator.
 * @details The implementation of this class is dependent on the operating system. It retrieves the random source from
 *          the hardware using the interfaces provided by the operating systems, and then uses MT19937-64 to generate
 *          the random data.
 */
class OsRng : public core::RngCore {
public:
    uint32_t get_uint32() override;
    uint64_t get_uint64() override;
    void fill_bytes(const std::span<uint8_t> &dest) noexcept override;
};

} // namespace rng::impl

#endif //RAND_OS_H